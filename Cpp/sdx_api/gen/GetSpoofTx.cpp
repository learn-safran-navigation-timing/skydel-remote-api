
#include "gen/GetSpoofTx.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSpoofTx
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSpoofTx::CmdName = "GetSpoofTx";
    const char* const GetSpoofTx::Documentation = "Get a spoofer transmitter. For set : the transmitter Id parameter is not set (empty string),\nSkydel will assign a unique Id to the transmitter. If the Id is set and already used by Skydel, the\ncommand will fail.";

    REGISTER_COMMAND_FACTORY(GetSpoofTx);


    GetSpoofTx::GetSpoofTx()
      : CommandBase(CmdName)
    {}

    GetSpoofTx::GetSpoofTx(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    GetSpoofTxPtr GetSpoofTx::create(const std::string& id)
    {
      return std::make_shared<GetSpoofTx>(id);
    }

    GetSpoofTxPtr GetSpoofTx::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSpoofTx>(ptr);
    }

    bool GetSpoofTx::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetSpoofTx::documentation() const { return Documentation; }


    int GetSpoofTx::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetSpoofTx::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetSpoofTx::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
