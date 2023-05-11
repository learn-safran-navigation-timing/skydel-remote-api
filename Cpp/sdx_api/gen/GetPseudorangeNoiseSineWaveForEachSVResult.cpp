
#include "gen/GetPseudorangeNoiseSineWaveForEachSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPseudorangeNoiseSineWaveForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPseudorangeNoiseSineWaveForEachSVResult::CmdName = "GetPseudorangeNoiseSineWaveForEachSVResult";
    const char* const GetPseudorangeNoiseSineWaveForEachSVResult::Documentation = "Result of GetPseudorangeNoiseSineWaveForEachSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetPseudorangeNoiseSineWaveForEachSVResult);


    GetPseudorangeNoiseSineWaveForEachSVResult::GetPseudorangeNoiseSineWaveForEachSVResult()
      : CommandResult(CmdName)
    {}

    GetPseudorangeNoiseSineWaveForEachSVResult::GetPseudorangeNoiseSineWaveForEachSVResult(const std::string& system, int sineWave, const std::vector<bool>& enabled, const std::vector<double>& amplitude, const std::vector<int>& period, const std::vector<double>& offset)
      : CommandResult(CmdName)
    {

      setSystem(system);
      setSineWave(sineWave);
      setEnabled(enabled);
      setAmplitude(amplitude);
      setPeriod(period);
      setOffset(offset);
    }

    GetPseudorangeNoiseSineWaveForEachSVResult::GetPseudorangeNoiseSineWaveForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, int sineWave, const std::vector<bool>& enabled, const std::vector<double>& amplitude, const std::vector<int>& period, const std::vector<double>& offset)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setSineWave(sineWave);
      setEnabled(enabled);
      setAmplitude(amplitude);
      setPeriod(period);
      setOffset(offset);
    }


    GetPseudorangeNoiseSineWaveForEachSVResultPtr GetPseudorangeNoiseSineWaveForEachSVResult::create(const std::string& system, int sineWave, const std::vector<bool>& enabled, const std::vector<double>& amplitude, const std::vector<int>& period, const std::vector<double>& offset)
    {
      return std::make_shared<GetPseudorangeNoiseSineWaveForEachSVResult>(system, sineWave, enabled, amplitude, period, offset);
    }

    GetPseudorangeNoiseSineWaveForEachSVResultPtr GetPseudorangeNoiseSineWaveForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& system, int sineWave, const std::vector<bool>& enabled, const std::vector<double>& amplitude, const std::vector<int>& period, const std::vector<double>& offset)
    {
      return std::make_shared<GetPseudorangeNoiseSineWaveForEachSVResult>(relatedCommand, system, sineWave, enabled, amplitude, period, offset);
    }

    GetPseudorangeNoiseSineWaveForEachSVResultPtr GetPseudorangeNoiseSineWaveForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPseudorangeNoiseSineWaveForEachSVResult>(ptr);
    }

    bool GetPseudorangeNoiseSineWaveForEachSVResult::isValid() const
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

    std::string GetPseudorangeNoiseSineWaveForEachSVResult::documentation() const { return Documentation; }


    std::string GetPseudorangeNoiseSineWaveForEachSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetPseudorangeNoiseSineWaveForEachSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeNoiseSineWaveForEachSVResult::sineWave() const
    {
      return parse_json<int>::parse(m_values["SineWave"]);
    }

    void GetPseudorangeNoiseSineWaveForEachSVResult::setSineWave(int sineWave)
    {
      m_values.AddMember("SineWave", parse_json<int>::format(sineWave, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> GetPseudorangeNoiseSineWaveForEachSVResult::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void GetPseudorangeNoiseSineWaveForEachSVResult::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetPseudorangeNoiseSineWaveForEachSVResult::amplitude() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Amplitude"]);
    }

    void GetPseudorangeNoiseSineWaveForEachSVResult::setAmplitude(const std::vector<double>& amplitude)
    {
      m_values.AddMember("Amplitude", parse_json<std::vector<double>>::format(amplitude, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<int> GetPseudorangeNoiseSineWaveForEachSVResult::period() const
    {
      return parse_json<std::vector<int>>::parse(m_values["Period"]);
    }

    void GetPseudorangeNoiseSineWaveForEachSVResult::setPeriod(const std::vector<int>& period)
    {
      m_values.AddMember("Period", parse_json<std::vector<int>>::format(period, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetPseudorangeNoiseSineWaveForEachSVResult::offset() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Offset"]);
    }

    void GetPseudorangeNoiseSineWaveForEachSVResult::setOffset(const std::vector<double>& offset)
    {
      m_values.AddMember("Offset", parse_json<std::vector<double>>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
