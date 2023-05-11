
#include "gen/SetAllSatellitesPseudorangeNoiseSineWave.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetAllSatellitesPseudorangeNoiseSineWave
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetAllSatellitesPseudorangeNoiseSineWave::CmdName = "SetAllSatellitesPseudorangeNoiseSineWave";
    const char* const SetAllSatellitesPseudorangeNoiseSineWave::Documentation = "Please note the command SetAllSatellitesPseudorangeNoiseSineWave is deprecated since 21.3. You may use SetPseudorangeNoiseSineWaveForEachSV.\n\nSet the satellite pseudorange noise sine wave attributes for all satellites.";

    REGISTER_COMMAND_FACTORY(SetAllSatellitesPseudorangeNoiseSineWave);


    SetAllSatellitesPseudorangeNoiseSineWave::SetAllSatellitesPseudorangeNoiseSineWave()
      : CommandBase(CmdName)
    {}

    SetAllSatellitesPseudorangeNoiseSineWave::SetAllSatellitesPseudorangeNoiseSineWave(const std::string& system, int sineWave, const std::vector<bool>& enabled, const std::vector<double>& amplitude, const std::vector<int>& period, const std::vector<double>& offset)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSineWave(sineWave);
      setEnabled(enabled);
      setAmplitude(amplitude);
      setPeriod(period);
      setOffset(offset);
    }

    SetAllSatellitesPseudorangeNoiseSineWavePtr SetAllSatellitesPseudorangeNoiseSineWave::create(const std::string& system, int sineWave, const std::vector<bool>& enabled, const std::vector<double>& amplitude, const std::vector<int>& period, const std::vector<double>& offset)
    {
      return std::make_shared<SetAllSatellitesPseudorangeNoiseSineWave>(system, sineWave, enabled, amplitude, period, offset);
    }

    SetAllSatellitesPseudorangeNoiseSineWavePtr SetAllSatellitesPseudorangeNoiseSineWave::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetAllSatellitesPseudorangeNoiseSineWave>(ptr);
    }

    bool SetAllSatellitesPseudorangeNoiseSineWave::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SineWave"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
          && parse_json<std::vector<double>>::is_valid(m_values["Amplitude"])
          && parse_json<std::vector<int>>::is_valid(m_values["Period"])
          && parse_json<std::vector<double>>::is_valid(m_values["Offset"])
        ;

    }

    std::string SetAllSatellitesPseudorangeNoiseSineWave::documentation() const { return Documentation; }


    int SetAllSatellitesPseudorangeNoiseSineWave::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetAllSatellitesPseudorangeNoiseSineWave::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetAllSatellitesPseudorangeNoiseSineWave::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetAllSatellitesPseudorangeNoiseSineWave::sineWave() const
    {
      return parse_json<int>::parse(m_values["SineWave"]);
    }

    void SetAllSatellitesPseudorangeNoiseSineWave::setSineWave(int sineWave)
    {
      m_values.AddMember("SineWave", parse_json<int>::format(sineWave, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> SetAllSatellitesPseudorangeNoiseSineWave::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void SetAllSatellitesPseudorangeNoiseSineWave::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetAllSatellitesPseudorangeNoiseSineWave::amplitude() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Amplitude"]);
    }

    void SetAllSatellitesPseudorangeNoiseSineWave::setAmplitude(const std::vector<double>& amplitude)
    {
      m_values.AddMember("Amplitude", parse_json<std::vector<double>>::format(amplitude, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<int> SetAllSatellitesPseudorangeNoiseSineWave::period() const
    {
      return parse_json<std::vector<int>>::parse(m_values["Period"]);
    }

    void SetAllSatellitesPseudorangeNoiseSineWave::setPeriod(const std::vector<int>& period)
    {
      m_values.AddMember("Period", parse_json<std::vector<int>>::format(period, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetAllSatellitesPseudorangeNoiseSineWave::offset() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Offset"]);
    }

    void SetAllSatellitesPseudorangeNoiseSineWave::setOffset(const std::vector<double>& offset)
    {
      m_values.AddMember("Offset", parse_json<std::vector<double>>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
