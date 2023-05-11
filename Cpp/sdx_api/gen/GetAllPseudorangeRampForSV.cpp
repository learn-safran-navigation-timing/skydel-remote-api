
#include "gen/GetAllPseudorangeRampForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllPseudorangeRampForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllPseudorangeRampForSV::CmdName = "GetAllPseudorangeRampForSV";
    const char* const GetAllPseudorangeRampForSV::Documentation = "Get a list of all the pseudorange ramps IDs for a system's satellite.";

    REGISTER_COMMAND_FACTORY(GetAllPseudorangeRampForSV);


    GetAllPseudorangeRampForSV::GetAllPseudorangeRampForSV()
      : CommandBase(CmdName)
    {}

    GetAllPseudorangeRampForSV::GetAllPseudorangeRampForSV(const std::string& system, int svId)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
    }

    GetAllPseudorangeRampForSVPtr GetAllPseudorangeRampForSV::create(const std::string& system, int svId)
    {
      return std::make_shared<GetAllPseudorangeRampForSV>(system, svId);
    }

    GetAllPseudorangeRampForSVPtr GetAllPseudorangeRampForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllPseudorangeRampForSV>(ptr);
    }

    bool GetAllPseudorangeRampForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetAllPseudorangeRampForSV::documentation() const { return Documentation; }


    int GetAllPseudorangeRampForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetAllPseudorangeRampForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetAllPseudorangeRampForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetAllPseudorangeRampForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetAllPseudorangeRampForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
