
#include "EnableTxSignalTerrainAttenuation.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableTxSignalTerrainAttenuation
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableTxSignalTerrainAttenuation::CmdName = "EnableTxSignalTerrainAttenuation";
    const char* const EnableTxSignalTerrainAttenuation::Documentation = "Enable (or disable) terrain-based attenuation of interference and spoofing signals.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ----------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Enabled bool If true, the power of interference and spoofing signals will be reduced based on the terrain profile between the transmitter and the receiver.";
    const char* const EnableTxSignalTerrainAttenuation::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableTxSignalTerrainAttenuation);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableTxSignalTerrainAttenuation);


    EnableTxSignalTerrainAttenuation::EnableTxSignalTerrainAttenuation()
      : CommandBase(CmdName, TargetId)
    {}

    EnableTxSignalTerrainAttenuation::EnableTxSignalTerrainAttenuation(bool enabled)
      : CommandBase(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    EnableTxSignalTerrainAttenuationPtr EnableTxSignalTerrainAttenuation::create(bool enabled)
    {
      return std::make_shared<EnableTxSignalTerrainAttenuation>(enabled);
    }

    EnableTxSignalTerrainAttenuationPtr EnableTxSignalTerrainAttenuation::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableTxSignalTerrainAttenuation>(ptr);
    }

    bool EnableTxSignalTerrainAttenuation::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableTxSignalTerrainAttenuation::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableTxSignalTerrainAttenuation::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


    int EnableTxSignalTerrainAttenuation::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool EnableTxSignalTerrainAttenuation::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableTxSignalTerrainAttenuation::setEnabled(bool enabled)
    {
      setValue("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()));
    }


  }
}
