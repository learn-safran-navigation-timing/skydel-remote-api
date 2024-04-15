
#include "GetEffectiveIonisationLevelCoefficientResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetEffectiveIonisationLevelCoefficientResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetEffectiveIonisationLevelCoefficientResult::CmdName = "GetEffectiveIonisationLevelCoefficientResult";
    const char* const GetEffectiveIonisationLevelCoefficientResult::Documentation = "Result of GetEffectiveIonisationLevelCoefficient.\n"
      "\n"
      "Name  Type   Description\n"
      "----- ------ ---------------------------------------------------------------\n"
      "Index int    Coefficient index, 0, 1 or 2 for ai0, ai1 and ai2 respectively.\n"
      "Val   double Coefficient value.";
    const char* const GetEffectiveIonisationLevelCoefficientResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetEffectiveIonisationLevelCoefficientResult);


    GetEffectiveIonisationLevelCoefficientResult::GetEffectiveIonisationLevelCoefficientResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetEffectiveIonisationLevelCoefficientResult::GetEffectiveIonisationLevelCoefficientResult(int index, double val)
      : CommandResult(CmdName, TargetId)
    {

      setIndex(index);
      setVal(val);
    }

    GetEffectiveIonisationLevelCoefficientResult::GetEffectiveIonisationLevelCoefficientResult(CommandBasePtr relatedCommand, int index, double val)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& GetEffectiveIonisationLevelCoefficientResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Index", "Val"}; 
      return names; 
    }


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
