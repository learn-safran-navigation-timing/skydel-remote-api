
#include "gen/SetPseudorangeNoiseGaussMarkovForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPseudorangeNoiseGaussMarkovForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPseudorangeNoiseGaussMarkovForSV::CmdName = "SetPseudorangeNoiseGaussMarkovForSV";
    const char* const SetPseudorangeNoiseGaussMarkovForSV::Documentation = "Set the satellite pseudorange noise Gauss-Markov process attributes.";

    REGISTER_COMMAND_FACTORY(SetPseudorangeNoiseGaussMarkovForSV);


    SetPseudorangeNoiseGaussMarkovForSV::SetPseudorangeNoiseGaussMarkovForSV()
      : CommandBase(CmdName)
    {}

    SetPseudorangeNoiseGaussMarkovForSV::SetPseudorangeNoiseGaussMarkovForSV(const std::string& system, int svId, int process, bool enabled, double sigma, double time, int seed)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setProcess(process);
      setEnabled(enabled);
      setSigma(sigma);
      setTime(time);
      setSeed(seed);
    }

    SetPseudorangeNoiseGaussMarkovForSVPtr SetPseudorangeNoiseGaussMarkovForSV::create(const std::string& system, int svId, int process, bool enabled, double sigma, double time, int seed)
    {
      return std::make_shared<SetPseudorangeNoiseGaussMarkovForSV>(system, svId, process, enabled, sigma, time, seed);
    }

    SetPseudorangeNoiseGaussMarkovForSVPtr SetPseudorangeNoiseGaussMarkovForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetPseudorangeNoiseGaussMarkovForSV>(ptr);
    }

    bool SetPseudorangeNoiseGaussMarkovForSV::isValid() const
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

    std::string SetPseudorangeNoiseGaussMarkovForSV::documentation() const { return Documentation; }


    int SetPseudorangeNoiseGaussMarkovForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetPseudorangeNoiseGaussMarkovForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetPseudorangeNoiseGaussMarkovForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetPseudorangeNoiseGaussMarkovForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetPseudorangeNoiseGaussMarkovForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetPseudorangeNoiseGaussMarkovForSV::process() const
    {
      return parse_json<int>::parse(m_values["Process"]);
    }

    void SetPseudorangeNoiseGaussMarkovForSV::setProcess(int process)
    {
      m_values.AddMember("Process", parse_json<int>::format(process, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetPseudorangeNoiseGaussMarkovForSV::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void SetPseudorangeNoiseGaussMarkovForSV::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetPseudorangeNoiseGaussMarkovForSV::sigma() const
    {
      return parse_json<double>::parse(m_values["Sigma"]);
    }

    void SetPseudorangeNoiseGaussMarkovForSV::setSigma(double sigma)
    {
      m_values.AddMember("Sigma", parse_json<double>::format(sigma, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetPseudorangeNoiseGaussMarkovForSV::time() const
    {
      return parse_json<double>::parse(m_values["Time"]);
    }

    void SetPseudorangeNoiseGaussMarkovForSV::setTime(double time)
    {
      m_values.AddMember("Time", parse_json<double>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetPseudorangeNoiseGaussMarkovForSV::seed() const
    {
      return parse_json<int>::parse(m_values["Seed"]);
    }

    void SetPseudorangeNoiseGaussMarkovForSV::setSeed(int seed)
    {
      m_values.AddMember("Seed", parse_json<int>::format(seed, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
