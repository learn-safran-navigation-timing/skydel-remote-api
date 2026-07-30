
#include "GetTxSignalTerrainAttenuationRateResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetTxSignalTerrainAttenuationRateResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetTxSignalTerrainAttenuationRateResult::CmdName = "GetTxSignalTerrainAttenuationRateResult";
    const char* const GetTxSignalTerrainAttenuationRateResult::Documentation = "Result of GetTxSignalTerrainAttenuationRate.\n"
      "\n"
      "Name Type Description\n"
      "---- ---- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Rate int  Rate at which terrain-based attenuation of interference and spoofing signals is recalculated. Accepted values are: 1 Hz, 5 Hz, 10 Hz, 20 Hz, 25 Hz, 40 Hz, and 50 Hz.";
    const char* const GetTxSignalTerrainAttenuationRateResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetTxSignalTerrainAttenuationRateResult);


    GetTxSignalTerrainAttenuationRateResult::GetTxSignalTerrainAttenuationRateResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetTxSignalTerrainAttenuationRateResult::GetTxSignalTerrainAttenuationRateResult(int rate)
      : CommandResult(CmdName, TargetId)
    {

      setRate(rate);
    }

    GetTxSignalTerrainAttenuationRateResult::GetTxSignalTerrainAttenuationRateResult(CommandBasePtr relatedCommand, int rate)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setRate(rate);
    }


    GetTxSignalTerrainAttenuationRateResultPtr GetTxSignalTerrainAttenuationRateResult::create(int rate)
    {
      return std::make_shared<GetTxSignalTerrainAttenuationRateResult>(rate);
    }

    GetTxSignalTerrainAttenuationRateResultPtr GetTxSignalTerrainAttenuationRateResult::create(CommandBasePtr relatedCommand, int rate)
    {
      return std::make_shared<GetTxSignalTerrainAttenuationRateResult>(relatedCommand, rate);
    }

    GetTxSignalTerrainAttenuationRateResultPtr GetTxSignalTerrainAttenuationRateResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetTxSignalTerrainAttenuationRateResult>(ptr);
    }

    bool GetTxSignalTerrainAttenuationRateResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Rate"])
        ;

    }

    std::string GetTxSignalTerrainAttenuationRateResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetTxSignalTerrainAttenuationRateResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Rate"}; 
      return names; 
    }


    int GetTxSignalTerrainAttenuationRateResult::rate() const
    {
      return parse_json<int>::parse(m_values["Rate"]);
    }

    void GetTxSignalTerrainAttenuationRateResult::setRate(int rate)
    {
      setValue("Rate", parse_json<int>::format(rate, m_values.GetAllocator()));
    }


  }
}
