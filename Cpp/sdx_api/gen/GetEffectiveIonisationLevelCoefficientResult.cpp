
#include "gen/GetEffectiveIonisationLevelCoefficientResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetEffectiveIonisationLevelCoefficientResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetEffectiveIonisationLevelCoefficientResult::CmdName = "GetEffectiveIonisationLevelCoefficientResult";
    const char* const GetEffectiveIonisationLevelCoefficientResult::Documentation = "Result of GetEffectiveIonisationLevelCoefficient.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetEffectiveIonisationLevelCoefficientResult);


    GetEffectiveIonisationLevelCoefficientResult::GetEffectiveIonisationLevelCoefficientResult()
      : CommandResult(CmdName)
    {}

    GetEffectiveIonisationLevelCoefficientResult::GetEffectiveIonisationLevelCoefficientResult(int index, double val)
      : CommandResult(CmdName)
    {

      setIndex(index);
      setVal(val);
    }

    GetEffectiveIonisationLevelCoefficientResult::GetEffectiveIonisationLevelCoefficientResult(CommandBasePtr relatedCommand, int index, double val)
      : CommandResult(CmdName, relatedCommand)
    {

      setIndex(index);
      setVal(val);
    }


    GetEffectiveIonisationLevelCoefficientResultPtr GetEffectiveIonisationLevelCoefficientResult::create(int index, double val)
    {
      return std::make_shared<GetEffectiveIonisationLevelCoefficientResult>(index, val);
    }

    GetEffectiveIonisationLevelCoefficientResultPtr GetEffectiveIonisationLevelCoefficientResult::create(CommandBasePtr relatedCommand, int index, double val)
    {
      return std::make_shared<GetEffectiveIonisationLevelCoefficientResult>(relatedCommand, index, val);
    }

    GetEffectiveIonisationLevelCoefficientResultPtr GetEffectiveIonisationLevelCoefficientResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetEffectiveIonisationLevelCoefficientResult>(ptr);
    }

    bool GetEffectiveIonisationLevelCoefficientResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Index"])
          && parse_json<double>::is_valid(m_values["Val"])
        ;

    }

    std::string GetEffectiveIonisationLevelCoefficientResult::documentation() const { return Documentation; }


    int GetEffectiveIonisationLevelCoefficientResult::index() const
    {
      return parse_json<int>::parse(m_values["Index"]);
    }

    void GetEffectiveIonisationLevelCoefficientResult::setIndex(int index)
    {
      m_values.AddMember("Index", parse_json<int>::format(index, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetEffectiveIonisationLevelCoefficientResult::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void GetEffectiveIonisationLevelCoefficientResult::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
