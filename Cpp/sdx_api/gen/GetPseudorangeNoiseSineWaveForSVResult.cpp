
#include "GetPseudorangeNoiseSineWaveForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPseudorangeNoiseSineWaveForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPseudorangeNoiseSineWaveForSVResult::CmdName = "GetPseudorangeNoiseSineWaveForSVResult";
    const char* const GetPseudorangeNoiseSineWaveForSVResult::Documentation = "Result of GetPseudorangeNoiseSineWaveForSV.\n"
      "\n"
      "Name      Type   Description\n"
      "--------- ------ --------------------------------------------------------------------------\n"
      "System    string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "SvId      int    The satellite's SV ID\n"
      "SineWave  int    Sine wave number (0 or 1)\n"
      "Enabled   bool   If true, sine wave is enabled\n"
      "Amplitude double Sine wave amplitude in meters\n"
      "Period    int    Sine wave period in seconds (minimum 3 seconds)\n"
      "Offset    double Phase offset in radians";
    const char* const GetPseudorangeNoiseSineWaveForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPseudorangeNoiseSineWaveForSVResult);


    GetPseudorangeNoiseSineWaveForSVResult::GetPseudorangeNoiseSineWaveForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetPseudorangeNoiseSineWaveForSVResult::GetPseudorangeNoiseSineWaveForSVResult(const std::string& system, int svId, int sineWave, bool enabled, double amplitude, int period, double offset)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setSineWave(sineWave);
      setEnabled(enabled);
      setAmplitude(amplitude);
      setPeriod(period);
      setOffset(offset);
    }

    GetPseudorangeNoiseSineWaveForSVResult::GetPseudorangeNoiseSineWaveForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, int sineWave, bool enabled, double amplitude, int period, double offset)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
      setSineWave(sineWave);
      setEnabled(enabled);
      setAmplitude(amplitude);
      setPeriod(period);
      setOffset(offset);
    }


    GetPseudorangeNoiseSineWaveForSVResultPtr GetPseudorangeNoiseSineWaveForSVResult::create(const std::string& system, int svId, int sineWave, bool enabled, double amplitude, int period, double offset)
    {
      return std::make_shared<GetPseudorangeNoiseSineWaveForSVResult>(system, svId, sineWave, enabled, amplitude, period, offset);
    }

    GetPseudorangeNoiseSineWaveForSVResultPtr GetPseudorangeNoiseSineWaveForSVResult::create(CommandBasePtr relatedCommand, const std::string& system, int svId, int sineWave, bool enabled, double amplitude, int period, double offset)
    {
      return std::make_shared<GetPseudorangeNoiseSineWaveForSVResult>(relatedCommand, system, svId, sineWave, enabled, amplitude, period, offset);
    }

    GetPseudorangeNoiseSineWaveForSVResultPtr GetPseudorangeNoiseSineWaveForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPseudorangeNoiseSineWaveForSVResult>(ptr);
    }

    bool GetPseudorangeNoiseSineWaveForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["SineWave"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<double>::is_valid(m_values["Amplitude"])
          && parse_json<int>::is_valid(m_values["Period"])
          && parse_json<double>::is_valid(m_values["Offset"])
        ;

    }

    std::string GetPseudorangeNoiseSineWaveForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPseudorangeNoiseSineWaveForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "SineWave", "Enabled", "Amplitude", "Period", "Offset"}; 
      return names; 
    }


    std::string GetPseudorangeNoiseSineWaveForSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetPseudorangeNoiseSineWaveForSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeNoiseSineWaveForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetPseudorangeNoiseSineWaveForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeNoiseSineWaveForSVResult::sineWave() const
    {
      return parse_json<int>::parse(m_values["SineWave"]);
    }

    void GetPseudorangeNoiseSineWaveForSVResult::setSineWave(int sineWave)
    {
      m_values.AddMember("SineWave", parse_json<int>::format(sineWave, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetPseudorangeNoiseSineWaveForSVResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void GetPseudorangeNoiseSineWaveForSVResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetPseudorangeNoiseSineWaveForSVResult::amplitude() const
    {
      return parse_json<double>::parse(m_values["Amplitude"]);
    }

    void GetPseudorangeNoiseSineWaveForSVResult::setAmplitude(double amplitude)
    {
      m_values.AddMember("Amplitude", parse_json<double>::format(amplitude, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeNoiseSineWaveForSVResult::period() const
    {
      return parse_json<int>::parse(m_values["Period"]);
    }

    void GetPseudorangeNoiseSineWaveForSVResult::setPeriod(int period)
    {
      m_values.AddMember("Period", parse_json<int>::format(period, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetPseudorangeNoiseSineWaveForSVResult::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void GetPseudorangeNoiseSineWaveForSVResult::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
