
#include "gen/GetIntTxFixEcef.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxFixEcef
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxFixEcef::CmdName = "GetIntTxFixEcef";
    const char* const GetIntTxFixEcef::Documentation = "Get interference transmitter static position and orientation";

    REGISTER_COMMAND_FACTORY(GetIntTxFixEcef);


    GetIntTxFixEcef::GetIntTxFixEcef()
      : CommandBase(CmdName)
    {}

    GetIntTxFixEcef::GetIntTxFixEcef(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    GetIntTxFixEcefPtr GetIntTxFixEcef::create(const std::string& id)
    {
      return std::make_shared<GetIntTxFixEcef>(id);
    }

    GetIntTxFixEcefPtr GetIntTxFixEcef::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxFixEcef>(ptr);
    }

    bool GetIntTxFixEcef::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetIntTxFixEcef::documentation() const { return Documentation; }


    int GetIntTxFixEcef::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetIntTxFixEcef::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetIntTxFixEcef::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
