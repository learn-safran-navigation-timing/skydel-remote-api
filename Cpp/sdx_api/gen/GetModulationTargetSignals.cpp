
#include "gen/GetModulationTargetSignals.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetModulationTargetSignals
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetModulationTargetSignals::CmdName = "GetModulationTargetSignals";
    const char* const GetModulationTargetSignals::Documentation = "Get the signals for the specified target and output index.\nSkydel tries to keep the sampling rate as low as possible,\nbut it is possible to set constaints with MinRate and MaxRate.";

    REGISTER_COMMAND_FACTORY(GetModulationTargetSignals);


    GetModulationTargetSignals::GetModulationTargetSignals()
      : CommandBase(CmdName)
    {}

    GetModulationTargetSignals::GetModulationTargetSignals(int output, const std::string& id)
      : CommandBase(CmdName)
    {

      setOutput(output);
      setId(id);
    }

    GetModulationTargetSignalsPtr GetModulationTargetSignals::create(int output, const std::string& id)
    {
      return std::make_shared<GetModulationTargetSignals>(output, id);
    }

    GetModulationTargetSignalsPtr GetModulationTargetSignals::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetModulationTargetSignals>(ptr);
    }

    bool GetModulationTargetSignals::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Output"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetModulationTargetSignals::documentation() const { return Documentation; }


    int GetModulationTargetSignals::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetModulationTargetSignals::output() const
    {
      return parse_json<int>::parse(m_values["Output"]);
    }

    void GetModulationTargetSignals::setOutput(int output)
    {
      m_values.AddMember("Output", parse_json<int>::format(output, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetModulationTargetSignals::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetModulationTargetSignals::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
