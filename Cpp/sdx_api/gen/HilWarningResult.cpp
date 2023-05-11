
#include "gen/HilWarningResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of HilWarningResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const HilWarningResult::CmdName = "HilWarningResult";
    const char* const HilWarningResult::Documentation = "Result of GetLastHilWarning.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(HilWarningResult);


    HilWarningResult::HilWarningResult()
      : CommandResult(CmdName)
    {}

    HilWarningResult::HilWarningResult(bool isExtrapolated, int extrapolationTime)
      : CommandResult(CmdName)
    {

      setIsExtrapolated(isExtrapolated);
      setExtrapolationTime(extrapolationTime);
    }

    HilWarningResult::HilWarningResult(CommandBasePtr relatedCommand, bool isExtrapolated, int extrapolationTime)
      : CommandResult(CmdName, relatedCommand)
    {

      setIsExtrapolated(isExtrapolated);
      setExtrapolationTime(extrapolationTime);
    }


    HilWarningResultPtr HilWarningResult::create(bool isExtrapolated, int extrapolationTime)
    {
      return std::make_shared<HilWarningResult>(isExtrapolated, extrapolationTime);
    }

    HilWarningResultPtr HilWarningResult::create(CommandBasePtr relatedCommand, bool isExtrapolated, int extrapolationTime)
    {
      return std::make_shared<HilWarningResult>(relatedCommand, isExtrapolated, extrapolationTime);
    }

    HilWarningResultPtr HilWarningResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<HilWarningResult>(ptr);
    }

    bool HilWarningResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["IsExtrapolated"])
          && parse_json<int>::is_valid(m_values["ExtrapolationTime"])
        ;

    }

    std::string HilWarningResult::documentation() const { return Documentation; }


    bool HilWarningResult::isExtrapolated() const
    {
      return parse_json<bool>::parse(m_values["IsExtrapolated"]);
    }

    void HilWarningResult::setIsExtrapolated(bool isExtrapolated)
    {
      m_values.AddMember("IsExtrapolated", parse_json<bool>::format(isExtrapolated, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int HilWarningResult::extrapolationTime() const
    {
      return parse_json<int>::parse(m_values["ExtrapolationTime"]);
    }

    void HilWarningResult::setExtrapolationTime(int extrapolationTime)
    {
      m_values.AddMember("ExtrapolationTime", parse_json<int>::format(extrapolationTime, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
