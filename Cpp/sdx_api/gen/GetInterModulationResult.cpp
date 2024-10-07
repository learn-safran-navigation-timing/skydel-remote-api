
#include "GetInterModulationResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetInterModulationResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetInterModulationResult::CmdName = "GetInterModulationResult";
    const char* const GetInterModulationResult::Documentation = "Result of GetInterModulation.\n"
      "\n"
      "Name        Type                      Description\n"
      "----------- ------------------------- -------------------------\n"
      "SignalArray array SignalWithComponent Signals to multiply.\n"
      "Coefficient double                    The coefficient to apply.";
    const char* const GetInterModulationResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetInterModulationResult);


    GetInterModulationResult::GetInterModulationResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetInterModulationResult::GetInterModulationResult(const std::vector<Sdx::SignalWithComponent>& signalArray, double coefficient)
      : CommandResult(CmdName, TargetId)
    {

      setSignalArray(signalArray);
      setCoefficient(coefficient);
    }

    GetInterModulationResult::GetInterModulationResult(CommandBasePtr relatedCommand, const std::vector<Sdx::SignalWithComponent>& signalArray, double coefficient)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSignalArray(signalArray);
      setCoefficient(coefficient);
    }


    GetInterModulationResultPtr GetInterModulationResult::create(const std::vector<Sdx::SignalWithComponent>& signalArray, double coefficient)
    {
      return std::make_shared<GetInterModulationResult>(signalArray, coefficient);
    }

    GetInterModulationResultPtr GetInterModulationResult::create(CommandBasePtr relatedCommand, const std::vector<Sdx::SignalWithComponent>& signalArray, double coefficient)
    {
      return std::make_shared<GetInterModulationResult>(relatedCommand, signalArray, coefficient);
    }

    GetInterModulationResultPtr GetInterModulationResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetInterModulationResult>(ptr);
    }

    bool GetInterModulationResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<Sdx::SignalWithComponent>>::is_valid(m_values["SignalArray"])
          && parse_json<double>::is_valid(m_values["Coefficient"])
        ;

    }

    std::string GetInterModulationResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetInterModulationResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SignalArray", "Coefficient"}; 
      return names; 
    }


    std::vector<Sdx::SignalWithComponent> GetInterModulationResult::signalArray() const
    {
      return parse_json<std::vector<Sdx::SignalWithComponent>>::parse(m_values["SignalArray"]);
    }

    void GetInterModulationResult::setSignalArray(const std::vector<Sdx::SignalWithComponent>& signalArray)
    {
      m_values.AddMember("SignalArray", parse_json<std::vector<Sdx::SignalWithComponent>>::format(signalArray, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetInterModulationResult::coefficient() const
    {
      return parse_json<double>::parse(m_values["Coefficient"]);
    }

    void GetInterModulationResult::setCoefficient(double coefficient)
    {
      m_values.AddMember("Coefficient", parse_json<double>::format(coefficient, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
