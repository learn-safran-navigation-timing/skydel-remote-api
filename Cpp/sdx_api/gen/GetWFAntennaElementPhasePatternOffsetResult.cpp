
#include "gen/GetWFAntennaElementPhasePatternOffsetResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetWFAntennaElementPhasePatternOffsetResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetWFAntennaElementPhasePatternOffsetResult::CmdName = "GetWFAntennaElementPhasePatternOffsetResult";
    const char* const GetWFAntennaElementPhasePatternOffsetResult::Documentation = "Result of GetWFAntennaElementPhasePatternOffset.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetWFAntennaElementPhasePatternOffsetResult);


    GetWFAntennaElementPhasePatternOffsetResult::GetWFAntennaElementPhasePatternOffsetResult()
      : CommandResult(CmdName)
    {}

    GetWFAntennaElementPhasePatternOffsetResult::GetWFAntennaElementPhasePatternOffsetResult(double phaseOffset, int element)
      : CommandResult(CmdName)
    {

      setPhaseOffset(phaseOffset);
      setElement(element);
    }

    GetWFAntennaElementPhasePatternOffsetResult::GetWFAntennaElementPhasePatternOffsetResult(CommandBasePtr relatedCommand, double phaseOffset, int element)
      : CommandResult(CmdName, relatedCommand)
    {

      setPhaseOffset(phaseOffset);
      setElement(element);
    }


    GetWFAntennaElementPhasePatternOffsetResultPtr GetWFAntennaElementPhasePatternOffsetResult::create(double phaseOffset, int element)
    {
      return std::make_shared<GetWFAntennaElementPhasePatternOffsetResult>(phaseOffset, element);
    }

    GetWFAntennaElementPhasePatternOffsetResultPtr GetWFAntennaElementPhasePatternOffsetResult::create(CommandBasePtr relatedCommand, double phaseOffset, int element)
    {
      return std::make_shared<GetWFAntennaElementPhasePatternOffsetResult>(relatedCommand, phaseOffset, element);
    }

    GetWFAntennaElementPhasePatternOffsetResultPtr GetWFAntennaElementPhasePatternOffsetResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetWFAntennaElementPhasePatternOffsetResult>(ptr);
    }

    bool GetWFAntennaElementPhasePatternOffsetResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["PhaseOffset"])
          && parse_json<int>::is_valid(m_values["Element"])
        ;

    }

    std::string GetWFAntennaElementPhasePatternOffsetResult::documentation() const { return Documentation; }


    double GetWFAntennaElementPhasePatternOffsetResult::phaseOffset() const
    {
      return parse_json<double>::parse(m_values["PhaseOffset"]);
    }

    void GetWFAntennaElementPhasePatternOffsetResult::setPhaseOffset(double phaseOffset)
    {
      m_values.AddMember("PhaseOffset", parse_json<double>::format(phaseOffset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetWFAntennaElementPhasePatternOffsetResult::element() const
    {
      return parse_json<int>::parse(m_values["Element"]);
    }

    void GetWFAntennaElementPhasePatternOffsetResult::setElement(int element)
    {
      m_values.AddMember("Element", parse_json<int>::format(element, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
