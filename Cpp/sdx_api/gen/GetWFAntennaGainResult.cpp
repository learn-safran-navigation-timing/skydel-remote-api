
#include "gen/GetWFAntennaGainResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetWFAntennaGainResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetWFAntennaGainResult::CmdName = "GetWFAntennaGainResult";
    const char* const GetWFAntennaGainResult::Documentation = "Result of GetWFAntennaGain.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetWFAntennaGainResult);


    GetWFAntennaGainResult::GetWFAntennaGainResult()
      : CommandResult(CmdName)
    {}

    GetWFAntennaGainResult::GetWFAntennaGainResult(int gain)
      : CommandResult(CmdName)
    {

      setGain(gain);
    }

    GetWFAntennaGainResult::GetWFAntennaGainResult(CommandBasePtr relatedCommand, int gain)
      : CommandResult(CmdName, relatedCommand)
    {

      setGain(gain);
    }


    GetWFAntennaGainResultPtr GetWFAntennaGainResult::create(int gain)
    {
      return std::make_shared<GetWFAntennaGainResult>(gain);
    }

    GetWFAntennaGainResultPtr GetWFAntennaGainResult::create(CommandBasePtr relatedCommand, int gain)
    {
      return std::make_shared<GetWFAntennaGainResult>(relatedCommand, gain);
    }

    GetWFAntennaGainResultPtr GetWFAntennaGainResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetWFAntennaGainResult>(ptr);
    }

    bool GetWFAntennaGainResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Gain"])
        ;

    }

    std::string GetWFAntennaGainResult::documentation() const { return Documentation; }


    int GetWFAntennaGainResult::gain() const
    {
      return parse_json<int>::parse(m_values["Gain"]);
    }

    void GetWFAntennaGainResult::setGain(int gain)
    {
      m_values.AddMember("Gain", parse_json<int>::format(gain, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
