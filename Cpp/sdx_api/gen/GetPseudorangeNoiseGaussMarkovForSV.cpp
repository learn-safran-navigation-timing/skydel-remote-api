
#include "gen/GetPseudorangeNoiseGaussMarkovForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPseudorangeNoiseGaussMarkovForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPseudorangeNoiseGaussMarkovForSV::CmdName = "GetPseudorangeNoiseGaussMarkovForSV";
    const char* const GetPseudorangeNoiseGaussMarkovForSV::Documentation = "Get the satellite pseudorange noise Gauss-Markov process attributes.";

    REGISTER_COMMAND_FACTORY(GetPseudorangeNoiseGaussMarkovForSV);


    GetPseudorangeNoiseGaussMarkovForSV::GetPseudorangeNoiseGaussMarkovForSV()
      : CommandBase(CmdName)
    {}

    GetPseudorangeNoiseGaussMarkovForSV::GetPseudorangeNoiseGaussMarkovForSV(const std::string& system, int svId, int process)
      : CommandBase(CmdName)
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
