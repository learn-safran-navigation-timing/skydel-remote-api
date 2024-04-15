
#include "EnableIntTx.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableIntTx
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableIntTx::CmdName = "EnableIntTx";
    const char* const EnableIntTx::Documentation = "Enable/Disable the interference transmitter.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ ------------------------------------------------\n"
      "Enabled bool   Enable (true) or disable (false) the transmitter\n"
      "Id      string Transmitter unique identifier.";
    const char* const EnableIntTx::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableIntTx);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableIntTx);


    EnableIntTx::EnableIntTx()
      : CommandBase(CmdName, TargetId)
    {}

    EnableIntTx::EnableIntTx(bool enabled, const std::string& id)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& EnableIntTx::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled", "Id"}; 
      return names; 
    }


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
