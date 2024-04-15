
#include "SetPseudorangeNoiseSineWaveForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPseudorangeNoiseSineWaveForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPseudorangeNoiseSineWaveForSV::CmdName = "SetPseudorangeNoiseSineWaveForSV";
    const char* const SetPseudorangeNoiseSineWaveForSV::Documentation = "Set the satellite pseudorange noise sine wave attributes.\n"
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
    const char* const SetPseudorangeNoiseSineWaveForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetPseudorangeNoiseSineWaveForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetPseudorangeNoiseSineWaveForSV);


    SetPseudorangeNoiseSineWaveForSV::SetPseudorangeNoiseSineWaveForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetPseudorangeNoiseSineWaveForSV::SetPseudorangeNoiseSineWaveForSV(const std::string& system, int svId, int sineWave, bool enabled, double amplitude, int period, double offset)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setSineWave(sineWave);
      setEnabled(enabled);
      setAmplitude(amplitude);
      setPeriod(period);
      setOffset(offset);
    }

    SetPseudorangeNoiseSineWaveForSVPtr SetPseudorangeNoiseSineWaveForSV::create(const std::string& system, int svId, int sineWave, bool enabled, double amplitude, int period, double offset)
    {
      return std::make_shared<SetPseudorangeNoiseSineWaveForSV>(system, svId, sineWave, enabled, amplitude, period, offset);
    }

    SetPseudorangeNoiseSineWaveForSVPtr SetPseudorangeNoiseSineWaveForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetPseudorangeNoiseSineWaveForSV>(ptr);
    }

    bool SetPseudorangeNoiseSineWaveForSV::isValid() const
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

    std::string SetPseudorangeNoiseSineWaveForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetPseudorangeNoiseSineWaveForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "SineWave", "Enabled", "Amplitude", "Period", "Offset"}; 
      return names; 
    }


    int SetPseudorangeNoiseSineWaveForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetPseudorangeNoiseSineWaveForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetPseudorangeNoiseSineWaveForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetPseudorangeNoiseSineWaveForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetPseudorangeNoiseSineWaveForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetPseudorangeNoiseSineWaveForSV::sineWave() const
    {
      return parse_json<int>::parse(m_values["SineWave"]);
    }

    void SetPseudorangeNoiseSineWaveForSV::setSineWave(int sineWave)
    {
      m_values.AddMember("SineWave", parse_json<int>::format(sineWave, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetPseudorangeNoiseSineWaveForSV::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void SetPseudorangeNoiseSineWaveForSV::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetPseudorangeNoiseSineWaveForSV::amplitude() const
    {
      return parse_json<double>::parse(m_values["Amplitude"]);
    }

    void SetPseudorangeNoiseSineWaveForSV::setAmplitude(double amplitude)
    {
      m_values.AddMember("Amplitude", parse_json<double>::format(amplitude, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetPseudorangeNoiseSineWaveForSV::period() const
    {
      return parse_json<int>::parse(m_values["Period"]);
    }

    void SetPseudorangeNoiseSineWaveForSV::setPeriod(int period)
    {
      m_values.AddMember("Period", parse_json<int>::format(period, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetPseudorangeNoiseSineWaveForSV::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void SetPseudorangeNoiseSineWaveForSV::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
