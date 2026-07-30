
#include "IsGnssSignalTerrainObscurationEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsGnssSignalTerrainObscurationEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsGnssSignalTerrainObscurationEnabledResult::CmdName = "IsGnssSignalTerrainObscurationEnabledResult";
    const char* const IsGnssSignalTerrainObscurationEnabledResult::Documentation = "Result of IsGnssSignalTerrainObscurationEnabled.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- --------------------------------------------------------------------------------------\n"
      "Enabled bool If true, GNSS signals from satellites obscured by terrain will not reach the receiver.";
    const char* const IsGnssSignalTerrainObscurationEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsGnssSignalTerrainObscurationEnabledResult);


    IsGnssSignalTerrainObscurationEnabledResult::IsGnssSignalTerrainObscurationEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsGnssSignalTerrainObscurationEnabledResult::IsGnssSignalTerrainObscurationEnabledResult(bool enabled)
      : CommandResult(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    IsGnssSignalTerrainObscurationEnabledResult::IsGnssSignalTerrainObscurationEnabledResult(CommandBasePtr relatedCommand, bool enabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setEnabled(enabled);
    }


    IsGnssSignalTerrainObscurationEnabledResultPtr IsGnssSignalTerrainObscurationEnabledResult::create(bool enabled)
    {
      return std::make_shared<IsGnssSignalTerrainObscurationEnabledResult>(enabled);
    }

    IsGnssSignalTerrainObscurationEnabledResultPtr IsGnssSignalTerrainObscurationEnabledResult::create(CommandBasePtr relatedCommand, bool enabled)
    {
      return std::make_shared<IsGnssSignalTerrainObscurationEnabledResult>(relatedCommand, enabled);
    }

    IsGnssSignalTerrainObscurationEnabledResultPtr IsGnssSignalTerrainObscurationEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsGnssSignalTerrainObscurationEnabledResult>(ptr);
    }

    bool IsGnssSignalTerrainObscurationEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsGnssSignalTerrainObscurationEnabledResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsGnssSignalTerrainObscurationEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


    bool IsGnssSignalTerrainObscurationEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsGnssSignalTerrainObscurationEnabledResult::setEnabled(bool enabled)
    {
      setValue("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()));
    }


  }
}
