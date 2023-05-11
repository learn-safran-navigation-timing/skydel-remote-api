
#include "gen/SetPseudorangeNoiseGaussMarkovForEachSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPseudorangeNoiseGaussMarkovForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPseudorangeNoiseGaussMarkovForEachSV::CmdName = "SetPseudorangeNoiseGaussMarkovForEachSV";
    const char* const SetPseudorangeNoiseGaussMarkovForEachSV::Documentation = "Set the satellite pseudorange noise Gauss-Markov process attributes for all satellites.";

    REGISTER_COMMAND_FACTORY(SetPseudorangeNoiseGaussMarkovForEachSV);


    SetPseudorangeNoiseGaussMarkovForEachSV::SetPseudorangeNoiseGaussMarkovForEachSV()
      : CommandBase(CmdName)
    {}

    SetPseudorangeNoiseGaussMarkovForEachSV::SetPseudorangeNoiseGaussMarkovForEachSV(const std::string& system, int process, const std::vector<bool>& enabled, const std::vector<double>& sigma, const std::vector<double>& time, const std::vector<int>& seed)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setProcess(process);
      setEnabled(enabled);
      setSigma(sigma);
      setTime(time);
      setSeed(seed);
    }

    SetPseudorangeNoiseGaussMarkovForEachSVPtr SetPseudorangeNoiseGaussMarkovForEachSV::create(const std::string& system, int process, const std::vector<bool>& enabled, const std::vector<double>& sigma, const std::vector<double>& time, const std::vector<int>& seed)
    {
      return std::make_shared<SetPseudorangeNoiseGaussMarkovForEachSV>(system, process, enabled, sigma, time, seed);
    }

    SetPseudorangeNoiseGaussMarkovForEachSVPtr SetPseudorangeNoiseGaussMarkovForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetPseudorangeNoiseGaussMarkovForEachSV>(ptr);
    }

    bool SetPseudorangeNoiseGaussMarkovForEachSV::isValid() const
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

    std::string SetPseudorangeNoiseGaussMarkovForEachSV::documentation() const { return Documentation; }


    int SetPseudorangeNoiseGaussMarkovForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetPseudorangeNoiseGaussMarkovForEachSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetPseudorangeNoiseGaussMarkovForEachSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetPseudorangeNoiseGaussMarkovForEachSV::process() const
    {
      return parse_json<int>::parse(m_values["Process"]);
    }

    void SetPseudorangeNoiseGaussMarkovForEachSV::setProcess(int process)
    {
      m_values.AddMember("Process", parse_json<int>::format(process, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> SetPseudorangeNoiseGaussMarkovForEachSV::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void SetPseudorangeNoiseGaussMarkovForEachSV::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetPseudorangeNoiseGaussMarkovForEachSV::sigma() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Sigma"]);
    }

    void SetPseudorangeNoiseGaussMarkovForEachSV::setSigma(const std::vector<double>& sigma)
    {
      m_values.AddMember("Sigma", parse_json<std::vector<double>>::format(sigma, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetPseudorangeNoiseGaussMarkovForEachSV::time() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Time"]);
    }

    void SetPseudorangeNoiseGaussMarkovForEachSV::setTime(const std::vector<double>& time)
    {
      m_values.AddMember("Time", parse_json<std::vector<double>>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<int> SetPseudorangeNoiseGaussMarkovForEachSV::seed() const
    {
      return parse_json<std::vector<int>>::parse(m_values["Seed"]);
    }

    void SetPseudorangeNoiseGaussMarkovForEachSV::setSeed(const std::vector<int>& seed)
    {
      m_values.AddMember("Seed", parse_json<std::vector<int>>::format(seed, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
