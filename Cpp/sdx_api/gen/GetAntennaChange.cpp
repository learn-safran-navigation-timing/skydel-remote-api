
#include "GetAntennaChange.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAntennaChange
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAntennaChange::CmdName = "GetAntennaChange";
    const char* const GetAntennaChange::Documentation = "Get an antenna change.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Unique identifier of the event";
    const char* const GetAntennaChange::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetAntennaChange);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAntennaChange);


    GetAntennaChange::GetAntennaChange()
      : CommandBase(CmdName, TargetId)
    {}

    GetAntennaChange::GetAntennaChange(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetAntennaChangePtr GetAntennaChange::create(const std::string& id)
    {
      return std::make_shared<GetAntennaChange>(id);
    }

    GetAntennaChangePtr GetAntennaChange::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAntennaChange>(ptr);
    }

    bool GetAntennaChange::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetAntennaChange::documentation() const { return Documentation; }

    const std::vector<std::string>& GetAntennaChange::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetAntennaChange::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetAntennaChange::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetAntennaChange::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
