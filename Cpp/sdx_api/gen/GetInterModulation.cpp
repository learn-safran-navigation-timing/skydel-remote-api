
#include "GetInterModulation.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetInterModulation
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetInterModulation::CmdName = "GetInterModulation";
    const char* const GetInterModulation::Documentation = "Get the inter-modulation coefficient for this signal component. The default value is 1 for the signal component and 0 for the global inter-modulation coefficient.\n"
      "\n"
      "Name        Type                      Description\n"
      "----------- ------------------------- --------------------\n"
      "SignalArray array SignalWithComponent Signals to multiply.";
    const char* const GetInterModulation::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetInterModulation);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetInterModulation);


    GetInterModulation::GetInterModulation()
      : CommandBase(CmdName, TargetId)
    {}

    GetInterModulation::GetInterModulation(const std::vector<Sdx::SignalWithComponent>& signalArray)
      : CommandBase(CmdName, TargetId)
    {

      setSignalArray(signalArray);
    }

    GetInterModulationPtr GetInterModulation::create(const std::vector<Sdx::SignalWithComponent>& signalArray)
    {
      return std::make_shared<GetInterModulation>(signalArray);
    }

    GetInterModulationPtr GetInterModulation::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetInterModulation>(ptr);
    }

    bool GetInterModulation::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<Sdx::SignalWithComponent>>::is_valid(m_values["SignalArray"])
        ;

    }

    std::string GetInterModulation::documentation() const { return Documentation; }

    const std::vector<std::string>& GetInterModulation::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SignalArray"}; 
      return names; 
    }


    int GetInterModulation::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::vector<Sdx::SignalWithComponent> GetInterModulation::signalArray() const
    {
      return parse_json<std::vector<Sdx::SignalWithComponent>>::parse(m_values["SignalArray"]);
    }

    void GetInterModulation::setSignalArray(const std::vector<Sdx::SignalWithComponent>& signalArray)
    {
      m_values.AddMember("SignalArray", parse_json<std::vector<Sdx::SignalWithComponent>>::format(signalArray, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
