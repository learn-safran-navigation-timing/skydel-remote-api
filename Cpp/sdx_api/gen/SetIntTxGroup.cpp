
#include "SetIntTxGroup.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxGroup
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxGroup::CmdName = "SetIntTxGroup";
    const char* const SetIntTxGroup::Documentation = "Set the interference transmitter group (which links to a specific RF output target).\n"
      "\n"
      "Name  Type   Description\n"
      "----- ------ ---------------------------------\n"
      "Group int    Interference group number [1..16]\n"
      "Id    string Transmitter unique identifier.";
    const char* const SetIntTxGroup::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetIntTxGroup);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetIntTxGroup);


    SetIntTxGroup::SetIntTxGroup()
      : CommandBase(CmdName, TargetId)
    {}

    SetIntTxGroup::SetIntTxGroup(int group, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setGroup(group);
      setId(id);
    }

    SetIntTxGroupPtr SetIntTxGroup::create(int group, const std::string& id)
    {
      return std::make_shared<SetIntTxGroup>(group, id);
    }

    SetIntTxGroupPtr SetIntTxGroup::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIntTxGroup>(ptr);
    }

    bool SetIntTxGroup::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Group"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetIntTxGroup::documentation() const { return Documentation; }

    const std::vector<std::string>& SetIntTxGroup::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Group", "Id"}; 
      return names; 
    }


    int SetIntTxGroup::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetIntTxGroup::group() const
    {
      return parse_json<int>::parse(m_values["Group"]);
    }

    void SetIntTxGroup::setGroup(int group)
    {
      m_values.AddMember("Group", parse_json<int>::format(group, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxGroup::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetIntTxGroup::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
