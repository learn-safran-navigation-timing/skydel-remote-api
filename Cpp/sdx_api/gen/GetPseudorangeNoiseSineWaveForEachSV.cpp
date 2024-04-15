
#include "GetPseudorangeNoiseSineWaveForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPseudorangeNoiseSineWaveForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPseudorangeNoiseSineWaveForEachSV::CmdName = "GetPseudorangeNoiseSineWaveForEachSV";
    const char* const GetPseudorangeNoiseSineWaveForEachSV::Documentation = "Get the satellite pseudorange noise sine wave attributes for all satellites.\n"
      "\n"
      "Name     Type   Description\n"
      "-------- ------ --------------------------------------------------------------------------\n"
      "System   string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "SineWave int    Sine wave number (0 or 1)";
    const char* const GetPseudorangeNoiseSineWaveForEachSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetPseudorangeNoiseSineWaveForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPseudorangeNoiseSineWaveForEachSV);


    GetPseudorangeNoiseSineWaveForEachSV::GetPseudorangeNoiseSineWaveForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetPseudorangeNoiseSineWaveForEachSV::GetPseudorangeNoiseSineWaveForEachSV(const std::string& system, int sineWave)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setSineWave(sineWave);
    }

    GetPseudorangeNoiseSineWaveForEachSVPtr GetPseudorangeNoiseSineWaveForEachSV::create(const std::string& system, int sineWave)
    {
      return std::make_shared<GetPseudorangeNoiseSineWaveForEachSV>(system, sineWave);
    }

    GetPseudorangeNoiseSineWaveForEachSVPtr GetPseudorangeNoiseSineWaveForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPseudorangeNoiseSineWaveForEachSV>(ptr);
    }

    bool GetPseudorangeNoiseSineWaveForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SineWave"])
        ;

    }

    std::string GetPseudorangeNoiseSineWaveForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPseudorangeNoiseSineWaveForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SineWave"}; 
      return names; 
    }


    int GetPseudorangeNoiseSineWaveForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetPseudorangeNoiseSineWaveForEachSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetPseudorangeNoiseSineWaveForEachSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeNoiseSineWaveForEachSV::sineWave() const
    {
      return parse_json<int>::parse(m_values["SineWave"]);
    }

    void GetPseudorangeNoiseSineWaveForEachSV::setSineWave(int sineWave)
    {
      m_values.AddMember("SineWave", parse_json<int>::format(sineWave, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
