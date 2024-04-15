
#include "SetAllSatellitesPseudorangeNoiseGaussMarkov.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetAllSatellitesPseudorangeNoiseGaussMarkov
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetAllSatellitesPseudorangeNoiseGaussMarkov::CmdName = "SetAllSatellitesPseudorangeNoiseGaussMarkov";
    const char* const SetAllSatellitesPseudorangeNoiseGaussMarkov::Documentation = "Please note the command SetAllSatellitesPseudorangeNoiseGaussMarkov is deprecated since 21.3. You may use SetPseudorangeNoiseGaussMarkovForEachSV.\n"
      "\n"
      "Set the satellite pseudorange noise Gauss-Markov process attributes for all satellites.\n"
      "\n"
      "Name    Type         Description\n"
      "------- ------------ --------------------------------------------------------------------------\n"
      "System  string       \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Process int          Gauss-Markov Process number (0 or 1)\n"
      "Enabled array bool   If true, Gauss-Markov process is enabled\n"
      "Sigma   array double Standard devition\n"
      "Time    array double Time constant\n"
      "Seed    array int    Random seed";
    const char* const SetAllSatellitesPseudorangeNoiseGaussMarkov::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetAllSatellitesPseudorangeNoiseGaussMarkov);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetAllSatellitesPseudorangeNoiseGaussMarkov);


    SetAllSatellitesPseudorangeNoiseGaussMarkov::SetAllSatellitesPseudorangeNoiseGaussMarkov()
      : CommandBase(CmdName, TargetId)
    {}

    SetAllSatellitesPseudorangeNoiseGaussMarkov::SetAllSatellitesPseudorangeNoiseGaussMarkov(const std::string& system, int process, const std::vector<bool>& enabled, const std::vector<double>& sigma, const std::vector<double>& time, const std::vector<int>& seed)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setProcess(process);
      setEnabled(enabled);
      setSigma(sigma);
      setTime(time);
      setSeed(seed);
    }

    SetAllSatellitesPseudorangeNoiseGaussMarkovPtr SetAllSatellitesPseudorangeNoiseGaussMarkov::create(const std::string& system, int process, const std::vector<bool>& enabled, const std::vector<double>& sigma, const std::vector<double>& time, const std::vector<int>& seed)
    {
      return std::make_shared<SetAllSatellitesPseudorangeNoiseGaussMarkov>(system, process, enabled, sigma, time, seed);
    }

    SetAllSatellitesPseudorangeNoiseGaussMarkovPtr SetAllSatellitesPseudorangeNoiseGaussMarkov::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetAllSatellitesPseudorangeNoiseGaussMarkov>(ptr);
    }

    bool SetAllSatellitesPseudorangeNoiseGaussMarkov::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Process"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
          && parse_json<std::vector<double>>::is_valid(m_values["Sigma"])
          && parse_json<std::vector<double>>::is_valid(m_values["Time"])
          && parse_json<std::vector<int>>::is_valid(m_values["Seed"])
        ;

    }

    std::string SetAllSatellitesPseudorangeNoiseGaussMarkov::documentation() const { return Documentation; }

    const std::vector<std::string>& SetAllSatellitesPseudorangeNoiseGaussMarkov::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Process", "Enabled", "Sigma", "Time", "Seed"}; 
      return names; 
    }


    int SetAllSatellitesPseudorangeNoiseGaussMarkov::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetAllSatellitesPseudorangeNoiseGaussMarkov::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetAllSatellitesPseudorangeNoiseGaussMarkov::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetAllSatellitesPseudorangeNoiseGaussMarkov::process() const
    {
      return parse_json<int>::parse(m_values["Process"]);
    }

    void SetAllSatellitesPseudorangeNoiseGaussMarkov::setProcess(int process)
    {
      m_values.AddMember("Process", parse_json<int>::format(process, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> SetAllSatellitesPseudorangeNoiseGaussMarkov::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void SetAllSatellitesPseudorangeNoiseGaussMarkov::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetAllSatellitesPseudorangeNoiseGaussMarkov::sigma() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Sigma"]);
    }

    void SetAllSatellitesPseudorangeNoiseGaussMarkov::setSigma(const std::vector<double>& sigma)
    {
      m_values.AddMember("Sigma", parse_json<std::vector<double>>::format(sigma, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetAllSatellitesPseudorangeNoiseGaussMarkov::time() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Time"]);
    }

    void SetAllSatellitesPseudorangeNoiseGaussMarkov::setTime(const std::vector<double>& time)
    {
      m_values.AddMember("Time", parse_json<std::vector<double>>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<int> SetAllSatellitesPseudorangeNoiseGaussMarkov::seed() const
    {
      return parse_json<std::vector<int>>::parse(m_values["Seed"]);
    }

    void SetAllSatellitesPseudorangeNoiseGaussMarkov::setSeed(const std::vector<int>& seed)
    {
      m_values.AddMember("Seed", parse_json<std::vector<int>>::format(seed, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
