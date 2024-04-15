
#include "GetPseudorangeNoiseGaussMarkovForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPseudorangeNoiseGaussMarkovForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPseudorangeNoiseGaussMarkovForSV::CmdName = "GetPseudorangeNoiseGaussMarkovForSV";
    const char* const GetPseudorangeNoiseGaussMarkovForSV::Documentation = "Get the satellite pseudorange noise Gauss-Markov process attributes.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ --------------------------------------------------------------------------\n"
      "System  string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "SvId    int    Satellite SV ID.\n"
      "Process int    Gauss-Markov Process number (0 or 1)";
    const char* const GetPseudorangeNoiseGaussMarkovForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetPseudorangeNoiseGaussMarkovForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPseudorangeNoiseGaussMarkovForSV);


    GetPseudorangeNoiseGaussMarkovForSV::GetPseudorangeNoiseGaussMarkovForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetPseudorangeNoiseGaussMarkovForSV::GetPseudorangeNoiseGaussMarkovForSV(const std::string& system, int svId, int process)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setProcess(process);
    }

    GetPseudorangeNoiseGaussMarkovForSVPtr GetPseudorangeNoiseGaussMarkovForSV::create(const std::string& system, int svId, int process)
    {
      return std::make_shared<GetPseudorangeNoiseGaussMarkovForSV>(system, svId, process);
    }

    GetPseudorangeNoiseGaussMarkovForSVPtr GetPseudorangeNoiseGaussMarkovForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPseudorangeNoiseGaussMarkovForSV>(ptr);
    }

    bool GetPseudorangeNoiseGaussMarkovForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Process"])
        ;

    }

    std::string GetPseudorangeNoiseGaussMarkovForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPseudorangeNoiseGaussMarkovForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "Process"}; 
      return names; 
    }


    int GetPseudorangeNoiseGaussMarkovForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetPseudorangeNoiseGaussMarkovForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetPseudorangeNoiseGaussMarkovForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeNoiseGaussMarkovForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetPseudorangeNoiseGaussMarkovForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeNoiseGaussMarkovForSV::process() const
    {
      return parse_json<int>::parse(m_values["Process"]);
    }

    void GetPseudorangeNoiseGaussMarkovForSV::setProcess(int process)
    {
      m_values.AddMember("Process", parse_json<int>::format(process, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
