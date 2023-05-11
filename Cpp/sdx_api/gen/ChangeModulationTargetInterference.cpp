
#include "gen/ChangeModulationTargetInterference.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ChangeModulationTargetInterference
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ChangeModulationTargetInterference::CmdName = "ChangeModulationTargetInterference";
    const char* const ChangeModulationTargetInterference::Documentation = "Set the specified target and output index to a group of interferences.\nAn interference transmitter is mapped to a specific RF output by using the same Interference Group Number.\nSkydel tries to keep the sampling rate as low as possible,\nbut it is possible to set constaints with MinRate and MaxRate.";

    REGISTER_COMMAND_FACTORY(ChangeModulationTargetInterference);


    ChangeModulationTargetInterference::ChangeModulationTargetInterference()
      : CommandBase(CmdName)
    {}

    ChangeModulationTargetInterference::ChangeModulationTargetInterference(int output, int minRate, int maxRate, int group, double centralFreq, int gain, const std::string& id, const Sdx::optional<std::string>& signal)
      : CommandBase(CmdName)
    {

      setOutput(output);
      setMinRate(minRate);
      setMaxRate(maxRate);
      setGroup(group);
      setCentralFreq(centralFreq);
      setGain(gain);
      setId(id);
      setSignal(signal);
    }

    ChangeModulationTargetInterferencePtr ChangeModulationTargetInterference::create(int output, int minRate, int maxRate, int group, double centralFreq, int gain, const std::string& id, const Sdx::optional<std::string>& signal)
    {
      return std::make_shared<ChangeModulationTargetInterference>(output, minRate, maxRate, group, centralFreq, gain, id, signal);
    }

    ChangeModulationTargetInterferencePtr ChangeModulationTargetInterference::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ChangeModulationTargetInterference>(ptr);
    }

    bool ChangeModulationTargetInterference::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Output"])
          && parse_json<int>::is_valid(m_values["MinRate"])
          && parse_json<int>::is_valid(m_values["MaxRate"])
          && parse_json<int>::is_valid(m_values["Group"])
          && parse_json<double>::is_valid(m_values["CentralFreq"])
          && parse_json<int>::is_valid(m_values["Gain"])
          && parse_json<std::string>::is_valid(m_values["Id"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["Signal"])
        ;

    }

    std::string ChangeModulationTargetInterference::documentation() const { return Documentation; }


    int ChangeModulationTargetInterference::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int ChangeModulationTargetInterference::output() const
    {
      return parse_json<int>::parse(m_values["Output"]);
    }

    void ChangeModulationTargetInterference::setOutput(int output)
    {
      m_values.AddMember("Output", parse_json<int>::format(output, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int ChangeModulationTargetInterference::minRate() const
    {
      return parse_json<int>::parse(m_values["MinRate"]);
    }

    void ChangeModulationTargetInterference::setMinRate(int minRate)
    {
      m_values.AddMember("MinRate", parse_json<int>::format(minRate, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int ChangeModulationTargetInterference::maxRate() const
    {
      return parse_json<int>::parse(m_values["MaxRate"]);
    }

    void ChangeModulationTargetInterference::setMaxRate(int maxRate)
    {
      m_values.AddMember("MaxRate", parse_json<int>::format(maxRate, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int ChangeModulationTargetInterference::group() const
    {
      return parse_json<int>::parse(m_values["Group"]);
    }

    void ChangeModulationTargetInterference::setGroup(int group)
    {
      m_values.AddMember("Group", parse_json<int>::format(group, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double ChangeModulationTargetInterference::centralFreq() const
    {
      return parse_json<double>::parse(m_values["CentralFreq"]);
    }

    void ChangeModulationTargetInterference::setCentralFreq(double centralFreq)
    {
      m_values.AddMember("CentralFreq", parse_json<double>::format(centralFreq, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int ChangeModulationTargetInterference::gain() const
    {
      return parse_json<int>::parse(m_values["Gain"]);
    }

    void ChangeModulationTargetInterference::setGain(int gain)
    {
      m_values.AddMember("Gain", parse_json<int>::format(gain, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ChangeModulationTargetInterference::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void ChangeModulationTargetInterference::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> ChangeModulationTargetInterference::signal() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["Signal"]);
    }

    void ChangeModulationTargetInterference::setSignal(const Sdx::optional<std::string>& signal)
    {
      m_values.AddMember("Signal", parse_json<Sdx::optional<std::string>>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
