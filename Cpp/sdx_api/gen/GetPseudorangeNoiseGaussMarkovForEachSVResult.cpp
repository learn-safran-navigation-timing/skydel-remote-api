
#include "GetPseudorangeNoiseGaussMarkovForEachSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPseudorangeNoiseGaussMarkovForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPseudorangeNoiseGaussMarkovForEachSVResult::CmdName = "GetPseudorangeNoiseGaussMarkovForEachSVResult";
    const char* const GetPseudorangeNoiseGaussMarkovForEachSVResult::Documentation = "Result of GetPseudorangeNoiseGaussMarkovForEachSV.\n"
      "\n"
      "Name    Type         Description\n"
      "------- ------------ --------------------------------------------------------------------------\n"
      "System  string       \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Process int          Gauss-Markov Process number (0 or 1)\n"
      "Enabled array bool   If true, Gauss-Markov process is enabled\n"
      "Sigma   array double Standard devition\n"
      "Time    array double Time constant\n"
      "Seed    array int    Random seed";
    const char* const GetPseudorangeNoiseGaussMarkovForEachSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPseudorangeNoiseGaussMarkovForEachSVResult);


    GetPseudorangeNoiseGaussMarkovForEachSVResult::GetPseudorangeNoiseGaussMarkovForEachSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetPseudorangeNoiseGaussMarkovForEachSVResult::GetPseudorangeNoiseGaussMarkovForEachSVResult(const std::string& system, int process, const std::vector<bool>& enabled, const std::vector<double>& sigma, const std::vector<double>& time, const std::vector<int>& seed)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setProcess(process);
      setEnabled(enabled);
      setSigma(sigma);
      setTime(time);
      setSeed(seed);
    }

    GetPseudorangeNoiseGaussMarkovForEachSVResult::GetPseudorangeNoiseGaussMarkovForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, int process, const std::vector<bool>& enabled, const std::vector<double>& sigma, const std::vector<double>& time, const std::vector<int>& seed)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setProcess(process);
      setEnabled(enabled);
      setSigma(sigma);
      setTime(time);
      setSeed(seed);
    }


    GetPseudorangeNoiseGaussMarkovForEachSVResultPtr GetPseudorangeNoiseGaussMarkovForEachSVResult::create(const std::string& system, int process, const std::vector<bool>& enabled, const std::vector<double>& sigma, const std::vector<double>& time, const std::vector<int>& seed)
    {
      return std::make_shared<GetPseudorangeNoiseGaussMarkovForEachSVResult>(system, process, enabled, sigma, time, seed);
    }

    GetPseudorangeNoiseGaussMarkovForEachSVResultPtr GetPseudorangeNoiseGaussMarkovForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& system, int process, const std::vector<bool>& enabled, const std::vector<double>& sigma, const std::vector<double>& time, const std::vector<int>& seed)
    {
      return std::make_shared<GetPseudorangeNoiseGaussMarkovForEachSVResult>(relatedCommand, system, process, enabled, sigma, time, seed);
    }

    GetPseudorangeNoiseGaussMarkovForEachSVResultPtr GetPseudorangeNoiseGaussMarkovForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPseudorangeNoiseGaussMarkovForEachSVResult>(ptr);
    }

    bool GetPseudorangeNoiseGaussMarkovForEachSVResult::isValid() const
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

    std::string GetPseudorangeNoiseGaussMarkovForEachSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPseudorangeNoiseGaussMarkovForEachSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Process", "Enabled", "Sigma", "Time", "Seed"}; 
      return names; 
    }


    std::string GetPseudorangeNoiseGaussMarkovForEachSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetPseudorangeNoiseGaussMarkovForEachSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeNoiseGaussMarkovForEachSVResult::process() const
    {
      return parse_json<int>::parse(m_values["Process"]);
    }

    void GetPseudorangeNoiseGaussMarkovForEachSVResult::setProcess(int process)
    {
      m_values.AddMember("Process", parse_json<int>::format(process, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> GetPseudorangeNoiseGaussMarkovForEachSVResult::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void GetPseudorangeNoiseGaussMarkovForEachSVResult::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetPseudorangeNoiseGaussMarkovForEachSVResult::sigma() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Sigma"]);
    }

    void GetPseudorangeNoiseGaussMarkovForEachSVResult::setSigma(const std::vector<double>& sigma)
    {
      m_values.AddMember("Sigma", parse_json<std::vector<double>>::format(sigma, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetPseudorangeNoiseGaussMarkovForEachSVResult::time() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Time"]);
    }

    void GetPseudorangeNoiseGaussMarkovForEachSVResult::setTime(const std::vector<double>& time)
    {
      m_values.AddMember("Time", parse_json<std::vector<double>>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<int> GetPseudorangeNoiseGaussMarkovForEachSVResult::seed() const
    {
      return parse_json<std::vector<int>>::parse(m_values["Seed"]);
    }

    void GetPseudorangeNoiseGaussMarkovForEachSVResult::setSeed(const std::vector<int>& seed)
    {
      m_values.AddMember("Seed", parse_json<std::vector<int>>::format(seed, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
