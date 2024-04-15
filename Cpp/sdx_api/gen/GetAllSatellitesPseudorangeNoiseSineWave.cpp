
#include "GetAllSatellitesPseudorangeNoiseSineWave.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllSatellitesPseudorangeNoiseSineWave
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllSatellitesPseudorangeNoiseSineWave::CmdName = "GetAllSatellitesPseudorangeNoiseSineWave";
    const char* const GetAllSatellitesPseudorangeNoiseSineWave::Documentation = "Please note the command GetAllSatellitesPseudorangeNoiseSineWave is deprecated since 21.3. You may use GetPseudorangeNoiseSineWaveForEachSV.\n"
      "\n"
      "Get the satellite pseudorange noise sine wave attributes for all satellites.\n"
      "\n"
      "Name     Type   Description\n"
      "-------- ------ --------------------------------------------------------------------------\n"
      "System   string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "SineWave int    Sine wave number (0 or 1)";
    const char* const GetAllSatellitesPseudorangeNoiseSineWave::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetAllSatellitesPseudorangeNoiseSineWave);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAllSatellitesPseudorangeNoiseSineWave);


    GetAllSatellitesPseudorangeNoiseSineWave::GetAllSatellitesPseudorangeNoiseSineWave()
      : CommandBase(CmdName, TargetId)
    {}

    GetAllSatellitesPseudorangeNoiseSineWave::GetAllSatellitesPseudorangeNoiseSineWave(const std::string& system, int sineWave)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setSineWave(sineWave);
    }

    GetAllSatellitesPseudorangeNoiseSineWavePtr GetAllSatellitesPseudorangeNoiseSineWave::create(const std::string& system, int sineWave)
    {
      return std::make_shared<GetAllSatellitesPseudorangeNoiseSineWave>(system, sineWave);
    }

    GetAllSatellitesPseudorangeNoiseSineWavePtr GetAllSatellitesPseudorangeNoiseSineWave::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllSatellitesPseudorangeNoiseSineWave>(ptr);
    }

    bool GetAllSatellitesPseudorangeNoiseSineWave::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SineWave"])
        ;

    }

    std::string GetAllSatellitesPseudorangeNoiseSineWave::documentation() const { return Documentation; }

    const std::vector<std::string>& GetAllSatellitesPseudorangeNoiseSineWave::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SineWave"}; 
      return names; 
    }


    int GetAllSatellitesPseudorangeNoiseSineWave::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetAllSatellitesPseudorangeNoiseSineWave::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetAllSatellitesPseudorangeNoiseSineWave::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetAllSatellitesPseudorangeNoiseSineWave::sineWave() const
    {
      return parse_json<int>::parse(m_values["SineWave"]);
    }

    void GetAllSatellitesPseudorangeNoiseSineWave::setSineWave(int sineWave)
    {
      m_values.AddMember("SineWave", parse_json<int>::format(sineWave, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
