
#include "GetModulationTargetInterferencesResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetModulationTargetInterferencesResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetModulationTargetInterferencesResult::CmdName = "GetModulationTargetInterferencesResult";
    const char* const GetModulationTargetInterferencesResult::Documentation = "Result of GetModulationTargetInterferences.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Output      int             Output index (zero based)\n"
      "MinRate     int             Minimum sampling rate (12500000, 25000000, 50000000, 60000000, 100000000)\n"
      "MaxRate     int             Maximum sampling rate (12500000, 25000000, 50000000. 60000000, 100000000)\n"
      "Group       int             Interference group number [1..16] or 0 for no group\n"
      "CentralFreq double          Central frequency (Hz). Put 0.0 and complete signal list to let Skydel choose automaticly the central frequency.\n"
      "Gain        int             The gain associated to this output (dB). As of today, accepted values are 0, 20, 40, 60 and 80. Values at 40 and under are not recommended. Use a negative value to use the default value (60).\n"
      "Id          string          Target identifier\n"
      "Signal      optional string Comma separated signal keys if you want to match central frequency and sampling rate with a particular list of signals. Accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\", \"G1\", \"G2\", \"E1\", \"E5a\", \"E5b\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"NAVICL5\", \"PULSARXL\"";
    const char* const GetModulationTargetInterferencesResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetModulationTargetInterferencesResult);


    GetModulationTargetInterferencesResult::GetModulationTargetInterferencesResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetModulationTargetInterferencesResult::GetModulationTargetInterferencesResult(int output, int minRate, int maxRate, int group, double centralFreq, int gain, const std::string& id, const Sdx::optional<std::string>& signal)
      : CommandResult(CmdName, TargetId)
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

    GetModulationTargetInterferencesResult::GetModulationTargetInterferencesResult(CommandBasePtr relatedCommand, int output, int minRate, int maxRate, int group, double centralFreq, int gain, const std::string& id, const Sdx::optional<std::string>& signal)
      : CommandResult(CmdName, TargetId, relatedCommand)
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


    GetModulationTargetInterferencesResultPtr GetModulationTargetInterferencesResult::create(int output, int minRate, int maxRate, int group, double centralFreq, int gain, const std::string& id, const Sdx::optional<std::string>& signal)
    {
      return std::make_shared<GetModulationTargetInterferencesResult>(output, minRate, maxRate, group, centralFreq, gain, id, signal);
    }

    GetModulationTargetInterferencesResultPtr GetModulationTargetInterferencesResult::create(CommandBasePtr relatedCommand, int output, int minRate, int maxRate, int group, double centralFreq, int gain, const std::string& id, const Sdx::optional<std::string>& signal)
    {
      return std::make_shared<GetModulationTargetInterferencesResult>(relatedCommand, output, minRate, maxRate, group, centralFreq, gain, id, signal);
    }

    GetModulationTargetInterferencesResultPtr GetModulationTargetInterferencesResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetModulationTargetInterferencesResult>(ptr);
    }

    bool GetModulationTargetInterferencesResult::isValid() const
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

    std::string GetModulationTargetInterferencesResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetModulationTargetInterferencesResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Output", "MinRate", "MaxRate", "Group", "CentralFreq", "Gain", "Id", "Signal"}; 
      return names; 
    }


    int GetModulationTargetInterferencesResult::output() const
    {
      return parse_json<int>::parse(m_values["Output"]);
    }

    void GetModulationTargetInterferencesResult::setOutput(int output)
    {
      m_values.AddMember("Output", parse_json<int>::format(output, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetModulationTargetInterferencesResult::minRate() const
    {
      return parse_json<int>::parse(m_values["MinRate"]);
    }

    void GetModulationTargetInterferencesResult::setMinRate(int minRate)
    {
      m_values.AddMember("MinRate", parse_json<int>::format(minRate, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetModulationTargetInterferencesResult::maxRate() const
    {
      return parse_json<int>::parse(m_values["MaxRate"]);
    }

    void GetModulationTargetInterferencesResult::setMaxRate(int maxRate)
    {
      m_values.AddMember("MaxRate", parse_json<int>::format(maxRate, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetModulationTargetInterferencesResult::group() const
    {
      return parse_json<int>::parse(m_values["Group"]);
    }

    void GetModulationTargetInterferencesResult::setGroup(int group)
    {
      m_values.AddMember("Group", parse_json<int>::format(group, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetModulationTargetInterferencesResult::centralFreq() const
    {
      return parse_json<double>::parse(m_values["CentralFreq"]);
    }

    void GetModulationTargetInterferencesResult::setCentralFreq(double centralFreq)
    {
      m_values.AddMember("CentralFreq", parse_json<double>::format(centralFreq, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetModulationTargetInterferencesResult::gain() const
    {
      return parse_json<int>::parse(m_values["Gain"]);
    }

    void GetModulationTargetInterferencesResult::setGain(int gain)
    {
      m_values.AddMember("Gain", parse_json<int>::format(gain, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetModulationTargetInterferencesResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetModulationTargetInterferencesResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetModulationTargetInterferencesResult::signal() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["Signal"]);
    }

    void GetModulationTargetInterferencesResult::setSignal(const Sdx::optional<std::string>& signal)
    {
      m_values.AddMember("Signal", parse_json<Sdx::optional<std::string>>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
