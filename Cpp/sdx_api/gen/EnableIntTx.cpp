
#include "gen/EnableIntTx.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableIntTx
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableIntTx::CmdName = "EnableIntTx";
    const char* const EnableIntTx::Documentation = "Enable/Disable the interference transmitter.";

    REGISTER_COMMAND_FACTORY(EnableIntTx);


    EnableIntTx::EnableIntTx()
      : CommandBase(CmdName)
    {}

    EnableIntTx::EnableIntTx(bool enabled, const std::string& id)
      : CommandBase(CmdName)
    {

      setEnabled(enabled);
      setId(id);
    }

    EnableIntTxPtr EnableIntTx::create(bool enabled, const std::string& id)
    {
      return std::make_shared<EnableIntTx>(enabled, id);
    }

    EnableIntTxPtr EnableIntTx::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableIntTx>(ptr);
    }

    bool EnableIntTx::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string EnableIntTx::documentation() const { return Documentation; }


    int EnableIntTx::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    bool EnableIntTx::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableIntTx::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string EnableIntTx::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void EnableIntTx::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
