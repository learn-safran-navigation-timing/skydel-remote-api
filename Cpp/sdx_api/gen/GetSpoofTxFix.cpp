
#include "GetSpoofTxFix.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSpoofTxFix
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSpoofTxFix::CmdName = "GetSpoofTxFix";
    const char* const GetSpoofTxFix::Documentation = "Get spoofer transmitter static position and orientation\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const GetSpoofTxFix::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSpoofTxFix);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSpoofTxFix);


    GetSpoofTxFix::GetSpoofTxFix()
      : CommandBase(CmdName, TargetId)
    {}

    GetSpoofTxFix::GetSpoofTxFix(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetSpoofTxFixPtr GetSpoofTxFix::create(const std::string& id)
    {
      return std::make_shared<GetSpoofTxFix>(id);
    }

    GetSpoofTxFixPtr GetSpoofTxFix::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSpoofTxFix>(ptr);
    }

    bool GetSpoofTxFix::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetSpoofTxFix::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSpoofTxFix::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetSpoofTxFix::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetSpoofTxFix::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetSpoofTxFix::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
