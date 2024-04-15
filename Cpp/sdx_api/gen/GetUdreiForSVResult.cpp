
#include "GetUdreiForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetUdreiForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetUdreiForSVResult::CmdName = "GetUdreiForSVResult";
    const char* const GetUdreiForSVResult::Documentation = "Result of GetUdreiForSV.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ---------------------------------------------------------------\n"
      "System string \"GPS\" or \"SBAS\".\n"
      "SvId   int    The satellite's SV ID (use 0 to apply modification to all SVs).\n"
      "Udrei  int    The UDREI value.";
    const char* const GetUdreiForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetUdreiForSVResult);


    GetUdreiForSVResult::GetUdreiForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetUdreiForSVResult::GetUdreiForSVResult(const std::string& system, int svId, int udrei)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setUdrei(udrei);
    }

    GetUdreiForSVResult::GetUdreiForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, int udrei)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
      setUdrei(udrei);
    }


    GetUdreiForSVResultPtr GetUdreiForSVResult::create(const std::string& system, int svId, int udrei)
    {
      return std::make_shared<GetUdreiForSVResult>(system, svId, udrei);
    }

    GetUdreiForSVResultPtr GetUdreiForSVResult::create(CommandBasePtr relatedCommand, const std::string& system, int svId, int udrei)
    {
      return std::make_shared<GetUdreiForSVResult>(relatedCommand, system, svId, udrei);
    }

    GetUdreiForSVResultPtr GetUdreiForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetUdreiForSVResult>(ptr);
    }

    bool GetUdreiForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Udrei"])
        ;

    }

    std::string GetUdreiForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetUdreiForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "Udrei"}; 
      return names; 
    }


    std::string GetUdreiForSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetUdreiForSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetUdreiForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetUdreiForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetUdreiForSVResult::udrei() const
    {
      return parse_json<int>::parse(m_values["Udrei"]);
    }

    void GetUdreiForSVResult::setUdrei(int udrei)
    {
      m_values.AddMember("Udrei", parse_json<int>::format(udrei, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
