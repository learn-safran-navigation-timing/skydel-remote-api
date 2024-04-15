
#include "GetPseudorangeNoiseGaussMarkovForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPseudorangeNoiseGaussMarkovForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPseudorangeNoiseGaussMarkovForEachSV::CmdName = "GetPseudorangeNoiseGaussMarkovForEachSV";
    const char* const GetPseudorangeNoiseGaussMarkovForEachSV::Documentation = "Get the satellite pseudorange noise Gauss-Markov process attributes for all satellites.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ --------------------------------------------------------------------------\n"
      "System  string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Process int    Gauss-Markov Process number (0 or 1)";
    const char* const GetPseudorangeNoiseGaussMarkovForEachSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetPseudorangeNoiseGaussMarkovForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPseudorangeNoiseGaussMarkovForEachSV);


    GetPseudorangeNoiseGaussMarkovForEachSV::GetPseudorangeNoiseGaussMarkovForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetPseudorangeNoiseGaussMarkovForEachSV::GetPseudorangeNoiseGaussMarkovForEachSV(const std::string& system, int process)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setProcess(process);
    }

    GetPseudorangeNoiseGaussMarkovForEachSVPtr GetPseudorangeNoiseGaussMarkovForEachSV::create(const std::string& system, int process)
    {
      return std::make_shared<GetPseudorangeNoiseGaussMarkovForEachSV>(system, process);
    }

    GetPseudorangeNoiseGaussMarkovForEachSVPtr GetPseudorangeNoiseGaussMarkovForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPseudorangeNoiseGaussMarkovForEachSV>(ptr);
    }

    bool GetPseudorangeNoiseGaussMarkovForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Process"])
        ;

    }

    std::string GetPseudorangeNoiseGaussMarkovForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPseudorangeNoiseGaussMarkovForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Process"}; 
      return names; 
    }


    int GetPseudorangeNoiseGaussMarkovForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetPseudorangeNoiseGaussMarkovForEachSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetPseudorangeNoiseGaussMarkovForEachSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeNoiseGaussMarkovForEachSV::process() const
    {
      return parse_json<int>::parse(m_values["Process"]);
    }

    void GetPseudorangeNoiseGaussMarkovForEachSV::setProcess(int process)
    {
      m_values.AddMember("Process", parse_json<int>::format(process, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
