
#include "SetInterModulation.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetInterModulation
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetInterModulation::CmdName = "SetInterModulation";
    const char* const SetInterModulation::Documentation = "Set the inter-modulation coefficient for this signal component. The default value is 1 for the signal component and 0 for the global inter-modulation coefficient.\n"
      "\n"
      "Name        Type                      Description\n"
      "----------- ------------------------- -------------------------\n"
      "SignalArray array SignalWithComponent Signals to multiply.\n"
      "Coefficient double                    The coefficient to apply.";
    const char* const SetInterModulation::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetInterModulation);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetInterModulation);


    SetInterModulation::SetInterModulation()
      : CommandBase(CmdName, TargetId)
    {}

    SetInterModulation::SetInterModulation(const std::vector<Sdx::SignalWithComponent>& signalArray, double coefficient)
      : CommandBase(CmdName, TargetId)
    {

      setSignalArray(signalArray);
      setCoefficient(coefficient);
    }

    SetInterModulationPtr SetInterModulation::create(const std::vector<Sdx::SignalWithComponent>& signalArray, double coefficient)
    {
      return std::make_shared<SetInterModulation>(signalArray, coefficient);
    }

    SetInterModulationPtr SetInterModulation::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetInterModulation>(ptr);
    }

    bool SetInterModulation::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<Sdx::SignalWithComponent>>::is_valid(m_values["SignalArray"])
          && parse_json<double>::is_valid(m_values["Coefficient"])
        ;

    }

    std::string SetInterModulation::documentation() const { return Documentation; }

    const std::vector<std::string>& SetInterModulation::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SignalArray", "Coefficient"}; 
      return names; 
    }


    int SetInterModulation::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::vector<Sdx::SignalWithComponent> SetInterModulation::signalArray() const
    {
      return parse_json<std::vector<Sdx::SignalWithComponent>>::parse(m_values["SignalArray"]);
    }

    void SetInterModulation::setSignalArray(const std::vector<Sdx::SignalWithComponent>& signalArray)
    {
      m_values.AddMember("SignalArray", parse_json<std::vector<Sdx::SignalWithComponent>>::format(signalArray, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetInterModulation::coefficient() const
    {
      return parse_json<double>::parse(m_values["Coefficient"]);
    }

    void SetInterModulation::setCoefficient(double coefficient)
    {
      m_values.AddMember("Coefficient", parse_json<double>::format(coefficient, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
