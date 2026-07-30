
#include "GetGnssSignalTerrainObscurationRateResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGnssSignalTerrainObscurationRateResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGnssSignalTerrainObscurationRateResult::CmdName = "GetGnssSignalTerrainObscurationRateResult";
    const char* const GetGnssSignalTerrainObscurationRateResult::Documentation = "Result of GetGnssSignalTerrainObscurationRate.\n"
      "\n"
      "Name Type Description\n"
      "---- ---- -----------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Rate int  Rate at which line-of-sight between the receiver and satellites is evaluated. Accepted values are: 1 Hz, 5 Hz, 10 Hz, 20 Hz, 25 Hz, 40 Hz, and 50 Hz.";
    const char* const GetGnssSignalTerrainObscurationRateResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGnssSignalTerrainObscurationRateResult);


    GetGnssSignalTerrainObscurationRateResult::GetGnssSignalTerrainObscurationRateResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetGnssSignalTerrainObscurationRateResult::GetGnssSignalTerrainObscurationRateResult(int rate)
      : CommandResult(CmdName, TargetId)
    {

      setRate(rate);
    }

    GetGnssSignalTerrainObscurationRateResult::GetGnssSignalTerrainObscurationRateResult(CommandBasePtr relatedCommand, int rate)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setRate(rate);
    }


    GetGnssSignalTerrainObscurationRateResultPtr GetGnssSignalTerrainObscurationRateResult::create(int rate)
    {
      return std::make_shared<GetGnssSignalTerrainObscurationRateResult>(rate);
    }

    GetGnssSignalTerrainObscurationRateResultPtr GetGnssSignalTerrainObscurationRateResult::create(CommandBasePtr relatedCommand, int rate)
    {
      return std::make_shared<GetGnssSignalTerrainObscurationRateResult>(relatedCommand, rate);
    }

    GetGnssSignalTerrainObscurationRateResultPtr GetGnssSignalTerrainObscurationRateResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGnssSignalTerrainObscurationRateResult>(ptr);
    }

    bool GetGnssSignalTerrainObscurationRateResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Rate"])
        ;

    }

    std::string GetGnssSignalTerrainObscurationRateResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGnssSignalTerrainObscurationRateResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Rate"}; 
      return names; 
    }


    int GetGnssSignalTerrainObscurationRateResult::rate() const
    {
      return parse_json<int>::parse(m_values["Rate"]);
    }

    void GetGnssSignalTerrainObscurationRateResult::setRate(int rate)
    {
      setValue("Rate", parse_json<int>::format(rate, m_values.GetAllocator()));
    }


  }
}
