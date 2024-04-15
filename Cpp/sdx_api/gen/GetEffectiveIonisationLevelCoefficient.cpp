
#include "GetEffectiveIonisationLevelCoefficient.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetEffectiveIonisationLevelCoefficient
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetEffectiveIonisationLevelCoefficient::CmdName = "GetEffectiveIonisationLevelCoefficient";
    const char* const GetEffectiveIonisationLevelCoefficient::Documentation = "Get the effective ionisation level coefficient for the 1st, 2nd or 3rd order, (ai0 , ai1 , ai2).\n"
      "\n"
      "Name  Type Description\n"
      "----- ---- ---------------------------------------------------------------\n"
      "Index int  Coefficient index, 0, 1 or 2 for ai0, ai1 and ai2 respectively.";
    const char* const GetEffectiveIonisationLevelCoefficient::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetEffectiveIonisationLevelCoefficient);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetEffectiveIonisationLevelCoefficient);


    GetEffectiveIonisationLevelCoefficient::GetEffectiveIonisationLevelCoefficient()
      : CommandBase(CmdName, TargetId)
    {}

    GetEffectiveIonisationLevelCoefficient::GetEffectiveIonisationLevelCoefficient(int index)
      : CommandBase(CmdName, TargetId)
    {

      setIndex(index);
    }

    GetEffectiveIonisationLevelCoefficientPtr GetEffectiveIonisationLevelCoefficient::create(int index)
    {
      return std::make_shared<GetEffectiveIonisationLevelCoefficient>(index);
    }

    GetEffectiveIonisationLevelCoefficientPtr GetEffectiveIonisationLevelCoefficient::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetEffectiveIonisationLevelCoefficient>(ptr);
    }

    bool GetEffectiveIonisationLevelCoefficient::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Index"])
        ;

    }

    std::string GetEffectiveIonisationLevelCoefficient::documentation() const { return Documentation; }

    const std::vector<std::string>& GetEffectiveIonisationLevelCoefficient::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Index"}; 
      return names; 
    }


    int GetEffectiveIonisationLevelCoefficient::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetEffectiveIonisationLevelCoefficient::index() const
    {
      return parse_json<int>::parse(m_values["Index"]);
    }

    void GetEffectiveIonisationLevelCoefficient::setIndex(int index)
    {
      m_values.AddMember("Index", parse_json<int>::format(index, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
