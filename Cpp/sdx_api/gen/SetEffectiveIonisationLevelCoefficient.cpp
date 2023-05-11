
#include "gen/SetEffectiveIonisationLevelCoefficient.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetEffectiveIonisationLevelCoefficient
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetEffectiveIonisationLevelCoefficient::CmdName = "SetEffectiveIonisationLevelCoefficient";
    const char* const SetEffectiveIonisationLevelCoefficient::Documentation = "Set the effective ionisation level coefficient for the 1st, 2nd or 3rd order, (ai0 , ai1 , ai2).";

    REGISTER_COMMAND_FACTORY(SetEffectiveIonisationLevelCoefficient);


    SetEffectiveIonisationLevelCoefficient::SetEffectiveIonisationLevelCoefficient()
      : CommandBase(CmdName)
    {}

    SetEffectiveIonisationLevelCoefficient::SetEffectiveIonisationLevelCoefficient(int index, double val)
      : CommandBase(CmdName)
    {

      setIndex(index);
      setVal(val);
    }

    SetEffectiveIonisationLevelCoefficientPtr SetEffectiveIonisationLevelCoefficient::create(int index, double val)
    {
      return std::make_shared<SetEffectiveIonisationLevelCoefficient>(index, val);
    }

    SetEffectiveIonisationLevelCoefficientPtr SetEffectiveIonisationLevelCoefficient::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetEffectiveIonisationLevelCoefficient>(ptr);
    }

    bool SetEffectiveIonisationLevelCoefficient::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Index"])
          && parse_json<double>::is_valid(m_values["Val"])
        ;

    }

    std::string SetEffectiveIonisationLevelCoefficient::documentation() const { return Documentation; }


    int SetEffectiveIonisationLevelCoefficient::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetEffectiveIonisationLevelCoefficient::index() const
    {
      return parse_json<int>::parse(m_values["Index"]);
    }

    void SetEffectiveIonisationLevelCoefficient::setIndex(int index)
    {
      m_values.AddMember("Index", parse_json<int>::format(index, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetEffectiveIonisationLevelCoefficient::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void SetEffectiveIonisationLevelCoefficient::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
