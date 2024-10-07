
#include "GetModulationTargetSignalsResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetModulationTargetSignalsResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetModulationTargetSignalsResult::CmdName = "GetModulationTargetSignalsResult";
    const char* const GetModulationTargetSignalsResult::Documentation = "Result of GetModulationTargetSignals.\n"
      "\n"
      "Name             Type            Description\n"
      "---------------- --------------- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Output           int             Output index (zero based)\n"
      "MinRate          int             Minimum sampling rate (12500000, 25000000, 50000000, 60000000, 100000000)\n"
      "MaxRate          int             Maximum sampling rate (12500000, 25000000, 50000000, 60000000, 100000000)\n"
      "Band             string          Frequency band is \"LowerL\", \"UpperL\" or \"S-Band\"\n"
      "Signal           string          Comma separated signal keys, accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\", \"G1\", \"G2\", \"E1\", \"E5a\", \"E5b\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\"\n"
      "Gain             int             The gain associated to this output (dB). This value has to be between the radio minimum value and 115. A negative value means to use the radio default value.\n"
      "GaussianNoise    bool            If true, add Gaussian noise to ensure realistic signal to noise ratio. When combining multiple outputs, only one should have Gaussian noise enabled.\n"
      "Id               string          Target identifier\n"
      "CentralFrequency optional double Forced central frequency to this value. Central frequency can only be one of this values: 1176450000, 1191795000, 1202000000, 1207140000, 1217370000, 1222000000, 1227000000, 1227600000, 1230000000, 1235000000, 1246000000, 1561098000, 1575420000, 1582000000, 1584000000, 1586000000, 1602000000, 2492028000.";
    const char* const GetModulationTargetSignalsResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetModulationTargetSignalsResult);


    GetModulationTargetSignalsResult::GetModulationTargetSignalsResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetModulationTargetSignalsResult::GetModulationTargetSignalsResult(int output, int minRate, int maxRate, const std::string& band, const std::string& signal, int gain, bool gaussianNoise, const std::string& id, const std::optional<double>& centralFrequency)
      : CommandResult(CmdName, TargetId)
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

    GetModulationTargetSignalsResult::GetModulationTargetSignalsResult(CommandBasePtr relatedCommand, int output, int minRate, int maxRate, const std::string& band, const std::string& signal, int gain, bool gaussianNoise, const std::string& id, const std::optional<double>& centralFrequency)
      : CommandResult(CmdName, TargetId, relatedCommand)
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


    GetModulationTargetSignalsResultPtr GetModulationTargetSignalsResult::create(int output, int minRate, int maxRate, const std::string& band, const std::string& signal, int gain, bool gaussianNoise, const std::string& id, const std::optional<double>& centralFrequency)
    {
      return std::make_shared<GetModulationTargetSignalsResult>(output, minRate, maxRate, band, signal, gain, gaussianNoise, id, centralFrequency);
    }

    GetModulationTargetSignalsResultPtr GetModulationTargetSignalsResult::create(CommandBasePtr relatedCommand, int output, int minRate, int maxRate, const std::string& band, const std::string& signal, int gain, bool gaussianNoise, const std::string& id, const std::optional<double>& centralFrequency)
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
          && parse_json<std::optional<double>>::is_valid(m_values["CentralFrequency"])
        ;

    }

    std::string GetModulationTargetSignalsResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetModulationTargetSignalsResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Output", "MinRate", "MaxRate", "Band", "Signal", "Gain", "GaussianNoise", "Id", "CentralFrequency"}; 
      return names; 
    }


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



    std::optional<double> GetModulationTargetSignalsResult::centralFrequency() const
    {
      return parse_json<std::optional<double>>::parse(m_values["CentralFrequency"]);
    }

    void GetModulationTargetSignalsResult::setCentralFrequency(const std::optional<double>& centralFrequency)
    {
      m_values.AddMember("CentralFrequency", parse_json<std::optional<double>>::format(centralFrequency, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
