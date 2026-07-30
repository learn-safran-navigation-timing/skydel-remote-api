
#include "SetTxSignalTerrainAttenuationRate.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetTxSignalTerrainAttenuationRate
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetTxSignalTerrainAttenuationRate::CmdName = "SetTxSignalTerrainAttenuationRate";
    const char* const SetTxSignalTerrainAttenuationRate::Documentation = "Set the rate (in Hz) at which terrain-based attenuation of interference and spoofing signals is recalculated.\n"
      "\n"
      "Name Type Description\n"
      "---- ---- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Rate int  Rate at which terrain-based attenuation of interference and spoofing signals is recalculated. Accepted values are: 1 Hz, 5 Hz, 10 Hz, 20 Hz, 25 Hz, 40 Hz, and 50 Hz.";
    const char* const SetTxSignalTerrainAttenuationRate::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetTxSignalTerrainAttenuationRate);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetTxSignalTerrainAttenuationRate);


    SetTxSignalTerrainAttenuationRate::SetTxSignalTerrainAttenuationRate()
      : CommandBase(CmdName, TargetId)
    {}

    SetTxSignalTerrainAttenuationRate::SetTxSignalTerrainAttenuationRate(int rate)
      : CommandBase(CmdName, TargetId)
    {

      setRate(rate);
    }

    SetTxSignalTerrainAttenuationRatePtr SetTxSignalTerrainAttenuationRate::create(int rate)
    {
      return std::make_shared<SetTxSignalTerrainAttenuationRate>(rate);
    }

    SetTxSignalTerrainAttenuationRatePtr SetTxSignalTerrainAttenuationRate::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetTxSignalTerrainAttenuationRate>(ptr);
    }

    bool SetTxSignalTerrainAttenuationRate::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Rate"])
        ;

    }

    std::string SetTxSignalTerrainAttenuationRate::documentation() const { return Documentation; }

    const std::vector<std::string>& SetTxSignalTerrainAttenuationRate::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Rate"}; 
      return names; 
    }


    int SetTxSignalTerrainAttenuationRate::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetTxSignalTerrainAttenuationRate::rate() const
    {
      return parse_json<int>::parse(m_values["Rate"]);
    }

    void SetTxSignalTerrainAttenuationRate::setRate(int rate)
    {
      setValue("Rate", parse_json<int>::format(rate, m_values.GetAllocator()));
    }


  }
}
