
#include "ChangeModulationTargetInterference.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ChangeModulationTargetInterference
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ChangeModulationTargetInterference::CmdName = "ChangeModulationTargetInterference";
    const char* const ChangeModulationTargetInterference::Documentation = "Set the specified target and output index to a group of interferences.\n"
      "An interference transmitter is mapped to a specific RF output by using the same Interference Group Number.\n"
      "Skydel tries to keep the sampling rate as low as possible,\n"
      "but it is possible to set constaints with MinRate and MaxRate.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Output      int             Output index (zero based)\n"
      "MinRate     int             Minimum sampling rate (12500000, 25000000, 50000000, 60000000, 100000000)\n"
      "MaxRate     int             Maximum sampling rate (12500000, 25000000, 50000000, 60000000, 100000000)\n"
      "Group       int             Interference group number [1..16] or 0 for no group\n"
      "CentralFreq double          Central frequency (Hz). Put 0.0 and complete signal list to let Skydel choose automatically the central frequency.\n"
      "Gain        int             The gain associated to this output (dB). As of today, accepted values are 0, 20, 40, 60 and 80. Values at 40 and under are not recommended. Use a negative value to use the default value (60).\n"
      "Id          string          Target identifier\n"
      "Signal      optional string Comma separated signal keys if you want to match central frequency and sampling rate with a particular list of signals. Accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\", \"G1\", \"G2\", \"E1\", \"E5a\", \"E5b\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\", \"PULSARX1\", \"PULSARX5\"";
    const char* const ChangeModulationTargetInterference::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ChangeModulationTargetInterference);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ChangeModulationTargetInterference);


    ChangeModulationTargetInterference::ChangeModulationTargetInterference()
      : CommandBase(CmdName, TargetId)
    {}

    ChangeModulationTargetInterference::ChangeModulationTargetInterference(int output, int minRate, int maxRate, int group, double centralFreq, int gain, const std::string& id, const std::optional<std::string>& signal)
      : CommandBase(CmdName, TargetId)
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

    ChangeModulationTargetInterferencePtr ChangeModulationTargetInterference::create(int output, int minRate, int maxRate, int group, double centralFreq, int gain, const std::string& id, const std::optional<std::string>& signal)
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
          && parse_json<std::optional<std::string>>::is_valid(m_values["Signal"])
        ;

    }

    std::string ChangeModulationTargetInterference::documentation() const { return Documentation; }

    const std::vector<std::string>& ChangeModulationTargetInterference::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Output", "MinRate", "MaxRate", "Group", "CentralFreq", "Gain", "Id", "Signal"}; 
      return names; 
    }


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



    std::optional<std::string> ChangeModulationTargetInterference::signal() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["Signal"]);
    }

    void ChangeModulationTargetInterference::setSignal(const std::optional<std::string>& signal)
    {
      m_values.AddMember("Signal", parse_json<std::optional<std::string>>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
