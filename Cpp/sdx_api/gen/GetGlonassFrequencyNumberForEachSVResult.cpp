
#include "GetGlonassFrequencyNumberForEachSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlonassFrequencyNumberForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlonassFrequencyNumberForEachSVResult::CmdName = "GetGlonassFrequencyNumberForEachSVResult";
    const char* const GetGlonassFrequencyNumberForEachSVResult::Documentation = "Result of GetGlonassFrequencyNumberForEachSV\n"
      "\n"
      "Name            Type      Description\n"
      "--------------- --------- --------------------------------------------------------------------------------------------------\n"
      "FrequencyNumber array int Frequency number of each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)";
    const char* const GetGlonassFrequencyNumberForEachSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGlonassFrequencyNumberForEachSVResult);


    GetGlonassFrequencyNumberForEachSVResult::GetGlonassFrequencyNumberForEachSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetGlonassFrequencyNumberForEachSVResult::GetGlonassFrequencyNumberForEachSVResult(const std::vector<int>& frequencyNumber)
      : CommandResult(CmdName, TargetId)
    {

      setFrequencyNumber(frequencyNumber);
    }

    GetGlonassFrequencyNumberForEachSVResult::GetGlonassFrequencyNumberForEachSVResult(CommandBasePtr relatedCommand, const std::vector<int>& frequencyNumber)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setFrequencyNumber(frequencyNumber);
    }


    GetGlonassFrequencyNumberForEachSVResultPtr GetGlonassFrequencyNumberForEachSVResult::create(const std::vector<int>& frequencyNumber)
    {
      return std::make_shared<GetGlonassFrequencyNumberForEachSVResult>(frequencyNumber);
    }

    GetGlonassFrequencyNumberForEachSVResultPtr GetGlonassFrequencyNumberForEachSVResult::create(CommandBasePtr relatedCommand, const std::vector<int>& frequencyNumber)
    {
      return std::make_shared<GetGlonassFrequencyNumberForEachSVResult>(relatedCommand, frequencyNumber);
    }

    GetGlonassFrequencyNumberForEachSVResultPtr GetGlonassFrequencyNumberForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGlonassFrequencyNumberForEachSVResult>(ptr);
    }

    bool GetGlonassFrequencyNumberForEachSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<int>>::is_valid(m_values["FrequencyNumber"])
        ;

    }

    std::string GetGlonassFrequencyNumberForEachSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGlonassFrequencyNumberForEachSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"FrequencyNumber"}; 
      return names; 
    }


    std::vector<int> GetGlonassFrequencyNumberForEachSVResult::frequencyNumber() const
    {
      return parse_json<std::vector<int>>::parse(m_values["FrequencyNumber"]);
    }

    void GetGlonassFrequencyNumberForEachSVResult::setFrequencyNumber(const std::vector<int>& frequencyNumber)
    {
      m_values.AddMember("FrequencyNumber", parse_json<std::vector<int>>::format(frequencyNumber, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
