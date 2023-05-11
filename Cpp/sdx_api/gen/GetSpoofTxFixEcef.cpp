
#include "gen/GetSpoofTxFixEcef.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSpoofTxFixEcef
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSpoofTxFixEcef::CmdName = "GetSpoofTxFixEcef";
    const char* const GetSpoofTxFixEcef::Documentation = "Get spoofer transmitter static position and orientation";

    REGISTER_COMMAND_FACTORY(GetSpoofTxFixEcef);


    GetSpoofTxFixEcef::GetSpoofTxFixEcef()
      : CommandBase(CmdName)
    {}

    GetSpoofTxFixEcef::GetSpoofTxFixEcef(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    GetSpoofTxFixEcefPtr GetSpoofTxFixEcef::create(const std::string& id)
    {
      return std::make_shared<GetSpoofTxFixEcef>(id);
    }

    GetSpoofTxFixEcefPtr GetSpoofTxFixEcef::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSpoofTxFixEcef>(ptr);
    }

    bool GetSpoofTxFixEcef::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetSpoofTxFixEcef::documentation() const { return Documentation; }


    int GetSpoofTxFixEcef::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetSpoofTxFixEcef::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetSpoofTxFixEcef::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
