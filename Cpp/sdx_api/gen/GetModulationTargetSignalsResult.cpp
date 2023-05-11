
#include "gen/GetModulationTargetSignalsResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetModulationTargetSignalsResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetModulationTargetSignalsResult::CmdName = "GetModulationTargetSignalsResult";
    const char* const GetModulationTargetSignalsResult::Documentation = "Result of GetModulationTargetSignals.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetModulationTargetSignalsResult);


    GetModulationTargetSignalsResult::GetModulationTargetSignalsResult()
      : CommandResult(CmdName)
    {}

    GetModulationTargetSignalsResult::GetModulationTargetSignalsResult(int output, int minRate, int maxRate, const std::string& band, const std::string& signal, int gain, bool gaussianNoise, const std::string& id, const Sdx::optional<double>& centralFrequency)
      : CommandResult(CmdName)
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

    GetModulationTargetSignalsResult::GetModulationTargetSignalsResult(CommandBasePtr relatedCommand, int output, int minRate, int maxRate, const std::string& band, const std::string& signal, int gain, bool gaussianNoise, const std::string& id, const Sdx::optional<double>& centralFrequency)
      : CommandResult(CmdName, relatedCommand)
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


    GetModulationTargetSignalsResultPtr GetModulationTargetSignalsResult::create(int output, int minRate, int maxRate, const std::string& band, const std::string& signal, int gain, bool gaussianNoise, const std::string& id, const Sdx::optional<double>& centralFrequency)
    {
      return std::make_shared<GetModulationTargetSignalsResult>(output, minRate, maxRate, band, signal, gain, gaussianNoise, id, centralFrequency);
    }

    GetModulationTargetSignalsResultPtr GetModulationTargetSignalsResult::create(CommandBasePtr relatedCommand, int output, int minRate, int maxRate, const std::string& band, const std::string& signal, int gain, bool gaussianNoise, const std::string& id, const Sdx::optional<double>& centralFrequency)
    {
      return std::make_shared<GetModulationTargetSignalsResult>(relatedCommand, output, minRate, maxRate, band, signal, gain, gaussianNoise, id, centralFrequency);
    }

    GetModulationTargetSignalsResultPtr GetModulationTargetSignalsResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetModulationTargetSignalsResult>(ptr);
    }

    bool GetModulationTargetSignalsResult::isValid() const
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

    std::string GetModulationTargetSignalsResult::documentation() const { return Documentation; }


    int GetModulationTargetSignalsResult::output() const
    {
      return parse_json<int>::parse(m_values["Output"]);
    }

    void GetModulationTargetSignalsResult::setOutput(int output)
    {
      m_values.AddMember("Output", parse_json<int>::format(output, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetModulationTargetSignalsResult::minRate() const
    {
      return parse_json<int>::parse(m_values["MinRate"]);
    }

    void GetModulationTargetSignalsResult::setMinRate(int minRate)
    {
      m_values.AddMember("MinRate", parse_json<int>::format(minRate, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetModulationTargetSignalsResult::maxRate() const
    {
      return parse_json<int>::parse(m_values["MaxRate"]);
    }

    void GetModulationTargetSignalsResult::setMaxRate(int maxRate)
    {
      m_values.AddMember("MaxRate", parse_json<int>::format(maxRate, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetModulationTargetSignalsResult::band() const
    {
      return parse_json<std::string>::parse(m_values["Band"]);
    }

    void GetModulationTargetSignalsResult::setBand(const std::string& band)
    {
      m_values.AddMember("Band", parse_json<std::string>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetModulationTargetSignalsResult::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetModulationTargetSignalsResult::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetModulationTargetSignalsResult::gain() const
    {
      return parse_json<int>::parse(m_values["Gain"]);
    }

    void GetModulationTargetSignalsResult::setGain(int gain)
    {
      m_values.AddMember("Gain", parse_json<int>::format(gain, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetModulationTargetSignalsResult::gaussianNoise() const
    {
      return parse_json<bool>::parse(m_values["GaussianNoise"]);
    }

    void GetModulationTargetSignalsResult::setGaussianNoise(bool gaussianNoise)
    {
      m_values.AddMember("GaussianNoise", parse_json<bool>::format(gaussianNoise, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetModulationTargetSignalsResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetModulationTargetSignalsResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<double> GetModulationTargetSignalsResult::centralFrequency() const
    {
      return parse_json<Sdx::optional<double>>::parse(m_values["CentralFrequency"]);
    }

    void GetModulationTargetSignalsResult::setCentralFrequency(const Sdx::optional<double>& centralFrequency)
    {
      m_values.AddMember("CentralFrequency", parse_json<Sdx::optional<double>>::format(centralFrequency, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
