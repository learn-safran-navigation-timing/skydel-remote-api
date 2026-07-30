
#include "IsTxSignalTerrainAttenuationEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsTxSignalTerrainAttenuationEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsTxSignalTerrainAttenuationEnabledResult::CmdName = "IsTxSignalTerrainAttenuationEnabledResult";
    const char* const IsTxSignalTerrainAttenuationEnabledResult::Documentation = "Result of IsTxSignalTerrainAttenuationEnabled.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ----------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Enabled bool If true, the power of interference and spoofing signals will be reduced based on the terrain profile between the transmitter and the receiver.";
    const char* const IsTxSignalTerrainAttenuationEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsTxSignalTerrainAttenuationEnabledResult);


    IsTxSignalTerrainAttenuationEnabledResult::IsTxSignalTerrainAttenuationEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsTxSignalTerrainAttenuationEnabledResult::IsTxSignalTerrainAttenuationEnabledResult(bool enabled)
      : CommandResult(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    IsTxSignalTerrainAttenuationEnabledResult::IsTxSignalTerrainAttenuationEnabledResult(CommandBasePtr relatedCommand, bool enabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setEnabled(enabled);
    }


    IsTxSignalTerrainAttenuationEnabledResultPtr IsTxSignalTerrainAttenuationEnabledResult::create(bool enabled)
    {
      return std::make_shared<IsTxSignalTerrainAttenuationEnabledResult>(enabled);
    }

    IsTxSignalTerrainAttenuationEnabledResultPtr IsTxSignalTerrainAttenuationEnabledResult::create(CommandBasePtr relatedCommand, bool enabled)
    {
      return std::make_shared<IsTxSignalTerrainAttenuationEnabledResult>(relatedCommand, enabled);
    }

    IsTxSignalTerrainAttenuationEnabledResultPtr IsTxSignalTerrainAttenuationEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsTxSignalTerrainAttenuationEnabledResult>(ptr);
    }

    bool IsTxSignalTerrainAttenuationEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsTxSignalTerrainAttenuationEnabledResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsTxSignalTerrainAttenuationEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


    bool IsTxSignalTerrainAttenuationEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsTxSignalTerrainAttenuationEnabledResult::setEnabled(bool enabled)
    {
      setValue("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()));
    }


  }
}
