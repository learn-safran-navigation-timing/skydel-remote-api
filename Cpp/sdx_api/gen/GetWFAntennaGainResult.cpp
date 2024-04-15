
#include "GetWFAntennaGainResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetWFAntennaGainResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetWFAntennaGainResult::CmdName = "GetWFAntennaGainResult";
    const char* const GetWFAntennaGainResult::Documentation = "Result of GetWFAntennaGain.\n"
      "\n"
      "Name Type Description\n"
      "---- ---- -----------------\n"
      "Gain int  The CRPA LNA gain";
    const char* const GetWFAntennaGainResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetWFAntennaGainResult);


    GetWFAntennaGainResult::GetWFAntennaGainResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetWFAntennaGainResult::GetWFAntennaGainResult(int gain)
      : CommandResult(CmdName, TargetId)
    {

      setGain(gain);
    }

    GetWFAntennaGainResult::GetWFAntennaGainResult(CommandBasePtr relatedCommand, int gain)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& GetWFAntennaGainResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Gain"}; 
      return names; 
    }


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
