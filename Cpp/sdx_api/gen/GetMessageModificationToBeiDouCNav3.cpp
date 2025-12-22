
#include "GetMessageModificationToBeiDouCNav3.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToBeiDouCNav3
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToBeiDouCNav3::CmdName = "GetMessageModificationToBeiDouCNav3";
    const char* const GetMessageModificationToBeiDouCNav3::Documentation = "Get infos about the BeiDou CNAV3 message modification with this ID.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Unique identifier of the event";
    const char* const GetMessageModificationToBeiDouCNav3::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetMessageModificationToBeiDouCNav3);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageModificationToBeiDouCNav3);


    GetMessageModificationToBeiDouCNav3::GetMessageModificationToBeiDouCNav3()
      : CommandBase(CmdName, TargetId)
    {}

    GetMessageModificationToBeiDouCNav3::GetMessageModificationToBeiDouCNav3(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetMessageModificationToBeiDouCNav3Ptr GetMessageModificationToBeiDouCNav3::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToBeiDouCNav3>(id);
    }

    GetMessageModificationToBeiDouCNav3Ptr GetMessageModificationToBeiDouCNav3::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToBeiDouCNav3>(ptr);
    }

    bool GetMessageModificationToBeiDouCNav3::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToBeiDouCNav3::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageModificationToBeiDouCNav3::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetMessageModificationToBeiDouCNav3::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToBeiDouCNav3::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToBeiDouCNav3::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
