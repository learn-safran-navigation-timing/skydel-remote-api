
#include "EnableSpoofTx.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableSpoofTx
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableSpoofTx::CmdName = "EnableSpoofTx";
    const char* const EnableSpoofTx::Documentation = "Enable/Disable the spoofer.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ ------------------------------------------------\n"
      "Enabled bool   Enable (true) or disable (false) the transmitter\n"
      "Id      string Transmitter unique identifier.";
    const char* const EnableSpoofTx::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableSpoofTx);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableSpoofTx);


    EnableSpoofTx::EnableSpoofTx()
      : CommandBase(CmdName, TargetId)
    {}

    EnableSpoofTx::EnableSpoofTx(bool enabled, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setEnabled(enabled);
      setId(id);
    }

    EnableSpoofTxPtr EnableSpoofTx::create(bool enabled, const std::string& id)
    {
      return std::make_shared<EnableSpoofTx>(enabled, id);
    }

    EnableSpoofTxPtr EnableSpoofTx::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableSpoofTx>(ptr);
    }

    bool EnableSpoofTx::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string EnableSpoofTx::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableSpoofTx::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled", "Id"}; 
      return names; 
    }


    int EnableSpoofTx::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    bool EnableSpoofTx::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableSpoofTx::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string EnableSpoofTx::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void EnableSpoofTx::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
