
#include "GetPseudorangeNoiseGaussMarkovForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPseudorangeNoiseGaussMarkovForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPseudorangeNoiseGaussMarkovForSVResult::CmdName = "GetPseudorangeNoiseGaussMarkovForSVResult";
    const char* const GetPseudorangeNoiseGaussMarkovForSVResult::Documentation = "Result of GetPseudorangeNoiseGaussMarkovForSV.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ --------------------------------------------------------------------------\n"
      "System  string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "SvId    int    Satellite SV ID.\n"
      "Process int    Gauss-Markov Process number (0 or 1)\n"
      "Enabled bool   If true, Gauss-Markov process is enabled\n"
      "Sigma   double Standard devition in meters [0..5000]\n"
      "Time    double Time constant [1..2000]\n"
      "Seed    int    Random seed";
    const char* const GetPseudorangeNoiseGaussMarkovForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPseudorangeNoiseGaussMarkovForSVResult);


    GetPseudorangeNoiseGaussMarkovForSVResult::GetPseudorangeNoiseGaussMarkovForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetPseudorangeNoiseGaussMarkovForSVResult::GetPseudorangeNoiseGaussMarkovForSVResult(const std::string& system, int svId, int process, bool enabled, double sigma, double time, int seed)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setProcess(process);
      setEnabled(enabled);
      setSigma(sigma);
      setTime(time);
      setSeed(seed);
    }

    GetPseudorangeNoiseGaussMarkovForSVResult::GetPseudorangeNoiseGaussMarkovForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, int process, bool enabled, double sigma, double time, int seed)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
      setProcess(process);
      setEnabled(enabled);
      setSigma(sigma);
      setTime(time);
      setSeed(seed);
    }


    GetPseudorangeNoiseGaussMarkovForSVResultPtr GetPseudorangeNoiseGaussMarkovForSVResult::create(const std::string& system, int svId, int process, bool enabled, double sigma, double time, int seed)
    {
      return std::make_shared<GetPseudorangeNoiseGaussMarkovForSVResult>(system, svId, process, enabled, sigma, time, seed);
    }

    GetPseudorangeNoiseGaussMarkovForSVResultPtr GetPseudorangeNoiseGaussMarkovForSVResult::create(CommandBasePtr relatedCommand, const std::string& system, int svId, int process, bool enabled, double sigma, double time, int seed)
    {
      return std::make_shared<GetPseudorangeNoiseGaussMarkovForSVResult>(relatedCommand, system, svId, process, enabled, sigma, time, seed);
    }

    GetPseudorangeNoiseGaussMarkovForSVResultPtr GetPseudorangeNoiseGaussMarkovForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPseudorangeNoiseGaussMarkovForSVResult>(ptr);
    }

    bool GetPseudorangeNoiseGaussMarkovForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Process"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<double>::is_valid(m_values["Sigma"])
          && parse_json<double>::is_valid(m_values["Time"])
          && parse_json<int>::is_valid(m_values["Seed"])
        ;

    }

    std::string GetPseudorangeNoiseGaussMarkovForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPseudorangeNoiseGaussMarkovForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "Process", "Enabled", "Sigma", "Time", "Seed"}; 
      return names; 
    }


    std::string GetPseudorangeNoiseGaussMarkovForSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetPseudorangeNoiseGaussMarkovForSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeNoiseGaussMarkovForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetPseudorangeNoiseGaussMarkovForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeNoiseGaussMarkovForSVResult::process() const
    {
      return parse_json<int>::parse(m_values["Process"]);
    }

    void GetPseudorangeNoiseGaussMarkovForSVResult::setProcess(int process)
    {
      m_values.AddMember("Process", parse_json<int>::format(process, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetPseudorangeNoiseGaussMarkovForSVResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void GetPseudorangeNoiseGaussMarkovForSVResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetPseudorangeNoiseGaussMarkovForSVResult::sigma() const
    {
      return parse_json<double>::parse(m_values["Sigma"]);
    }

    void GetPseudorangeNoiseGaussMarkovForSVResult::setSigma(double sigma)
    {
      m_values.AddMember("Sigma", parse_json<double>::format(sigma, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetPseudorangeNoiseGaussMarkovForSVResult::time() const
    {
      return parse_json<double>::parse(m_values["Time"]);
    }

    void GetPseudorangeNoiseGaussMarkovForSVResult::setTime(double time)
    {
      m_values.AddMember("Time", parse_json<double>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeNoiseGaussMarkovForSVResult::seed() const
    {
      return parse_json<int>::parse(m_values["Seed"]);
    }

    void GetPseudorangeNoiseGaussMarkovForSVResult::setSeed(int seed)
    {
      m_values.AddMember("Seed", parse_json<int>::format(seed, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
