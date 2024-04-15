
#include "GetAllSatellitesPseudorangeNoiseGaussMarkov.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllSatellitesPseudorangeNoiseGaussMarkov
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllSatellitesPseudorangeNoiseGaussMarkov::CmdName = "GetAllSatellitesPseudorangeNoiseGaussMarkov";
    const char* const GetAllSatellitesPseudorangeNoiseGaussMarkov::Documentation = "Please note the command GetAllSatellitesPseudorangeNoiseGaussMarkov is deprecated since 21.3. You may use GetPseudorangeNoiseGaussMarkovForEachSV.\n"
      "\n"
      "Get the satellite pseudorange noise Gauss-Markov process attributes for all satellites.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ --------------------------------------------------------------------------\n"
      "System  string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Process int    Gauss-Markov Process number (0 or 1)";
    const char* const GetAllSatellitesPseudorangeNoiseGaussMarkov::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetAllSatellitesPseudorangeNoiseGaussMarkov);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAllSatellitesPseudorangeNoiseGaussMarkov);


    GetAllSatellitesPseudorangeNoiseGaussMarkov::GetAllSatellitesPseudorangeNoiseGaussMarkov()
      : CommandBase(CmdName, TargetId)
    {}

    GetAllSatellitesPseudorangeNoiseGaussMarkov::GetAllSatellitesPseudorangeNoiseGaussMarkov(const std::string& system, int process)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setProcess(process);
    }

    GetAllSatellitesPseudorangeNoiseGaussMarkovPtr GetAllSatellitesPseudorangeNoiseGaussMarkov::create(const std::string& system, int process)
    {
      return std::make_shared<GetAllSatellitesPseudorangeNoiseGaussMarkov>(system, process);
    }

    GetAllSatellitesPseudorangeNoiseGaussMarkovPtr GetAllSatellitesPseudorangeNoiseGaussMarkov::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllSatellitesPseudorangeNoiseGaussMarkov>(ptr);
    }

    bool GetAllSatellitesPseudorangeNoiseGaussMarkov::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Process"])
        ;

    }

    std::string GetAllSatellitesPseudorangeNoiseGaussMarkov::documentation() const { return Documentation; }

    const std::vector<std::string>& GetAllSatellitesPseudorangeNoiseGaussMarkov::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Process"}; 
      return names; 
    }


    int GetAllSatellitesPseudorangeNoiseGaussMarkov::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetAllSatellitesPseudorangeNoiseGaussMarkov::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetAllSatellitesPseudorangeNoiseGaussMarkov::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetAllSatellitesPseudorangeNoiseGaussMarkov::process() const
    {
      return parse_json<int>::parse(m_values["Process"]);
    }

    void GetAllSatellitesPseudorangeNoiseGaussMarkov::setProcess(int process)
    {
      m_values.AddMember("Process", parse_json<int>::format(process, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
