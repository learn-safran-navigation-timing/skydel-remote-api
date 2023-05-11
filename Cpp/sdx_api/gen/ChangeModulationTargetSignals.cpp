
#include "gen/ChangeModulationTargetSignals.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ChangeModulationTargetSignals
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ChangeModulationTargetSignals::CmdName = "ChangeModulationTargetSignals";
    const char* const ChangeModulationTargetSignals::Documentation = "Set the signals for the specified target and output index.\nSkydel tries to keep the sampling rate as low as possible,\nbut it is possible to set constaints with MinRate and MaxRate.";

    REGISTER_COMMAND_FACTORY(ChangeModulationTargetSignals);


    ChangeModulationTargetSignals::ChangeModulationTargetSignals()
      : CommandBase(CmdName)
    {}

    ChangeModulationTargetSignals::ChangeModulationTargetSignals(int output, int minRate, int maxRate, const std::string& band, const std::string& signal, int gain, bool gaussianNoise, const std::string& id, const Sdx::optional<double>& centralFrequency)
      : CommandBase(CmdName)
    {

      setOutput(output);
      setMinRate(minRate);
      setMaxRate(maxRate);
      setBand(band);
      setSignal(signal);
      setGain(gain);
      setGaussianNoise(gaussianNoise);
      setId(id);
      setCentralFrequency(centralFrequency);
    }

    ChangeModulationTargetSignalsPtr ChangeModulationTargetSignals::create(int output, int minRate, int maxRate, const std::string& band, const std::string& signal, int gain, bool gaussianNoise, const std::string& id, const Sdx::optional<double>& centralFrequency)
    {
      return std::make_shared<ChangeModulationTargetSignals>(output, minRate, maxRate, band, signal, gain, gaussianNoise, id, centralFrequency);
    }

    ChangeModulationTargetSignalsPtr ChangeModulationTargetSignals::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ChangeModulationTargetSignals>(ptr);
    }

    bool ChangeModulationTargetSignals::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Output"])
          && parse_json<int>::is_valid(m_values["MinRate"])
          && parse_json<int>::is_valid(m_values["MaxRate"])
          && parse_json<std::string>::is_valid(m_values["Band"])
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<int>::is_valid(m_values["Gain"])
          && parse_json<bool>::is_valid(m_values["GaussianNoise"])
          && parse_json<std::string>::is_valid(m_values["Id"])
          && parse_json<Sdx::optional<double>>::is_valid(m_values["CentralFrequency"])
        ;

    }

    std::string ChangeModulationTargetSignals::documentation() const { return Documentation; }


    int ChangeModulationTargetSignals::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int ChangeModulationTargetSignals::output() const
    {
      return parse_json<int>::parse(m_values["Output"]);
    }

    void ChangeModulationTargetSignals::setOutput(int output)
    {
      m_values.AddMember("Output", parse_json<int>::format(output, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int ChangeModulationTargetSignals::minRate() const
    {
      return parse_json<int>::parse(m_values["MinRate"]);
    }

    void ChangeModulationTargetSignals::setMinRate(int minRate)
    {
      m_values.AddMember("MinRate", parse_json<int>::format(minRate, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int ChangeModulationTargetSignals::maxRate() const
    {
      return parse_json<int>::parse(m_values["MaxRate"]);
    }

    void ChangeModulationTargetSignals::setMaxRate(int maxRate)
    {
      m_values.AddMember("MaxRate", parse_json<int>::format(maxRate, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ChangeModulationTargetSignals::band() const
    {
      return parse_json<std::string>::parse(m_values["Band"]);
    }

    void ChangeModulationTargetSignals::setBand(const std::string& band)
    {
      m_values.AddMember("Band", parse_json<std::string>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ChangeModulationTargetSignals::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void ChangeModulationTargetSignals::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int ChangeModulationTargetSignals::gain() const
    {
      return parse_json<int>::parse(m_values["Gain"]);
    }

    void ChangeModulationTargetSignals::setGain(int gain)
    {
      m_values.AddMember("Gain", parse_json<int>::format(gain, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool ChangeModulationTargetSignals::gaussianNoise() const
    {
      return parse_json<bool>::parse(m_values["GaussianNoise"]);
    }

    void ChangeModulationTargetSignals::setGaussianNoise(bool gaussianNoise)
    {
      m_values.AddMember("GaussianNoise", parse_json<bool>::format(gaussianNoise, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ChangeModulationTargetSignals::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void ChangeModulationTargetSignals::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<double> ChangeModulationTargetSignals::centralFrequency() const
    {
      return parse_json<Sdx::optional<double>>::parse(m_values["CentralFrequency"]);
    }

    void ChangeModulationTargetSignals::setCentralFrequency(const Sdx::optional<double>& centralFrequency)
    {
      m_values.AddMember("CentralFrequency", parse_json<Sdx::optional<double>>::format(centralFrequency, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
