
#include "GetUdreiForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetUdreiForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetUdreiForSV::CmdName = "GetUdreiForSV";
    const char* const GetUdreiForSV::Documentation = "Get the UDREI value transmitted by SBAS for the satellite of the specified constellation.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ---------------------------------------------------------------\n"
      "System string \"GPS\" or \"SBAS\".\n"
      "SvId   int    The satellite's SV ID (use 0 to apply modification to all SVs).";
    const char* const GetUdreiForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetUdreiForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetUdreiForSV);


    GetUdreiForSV::GetUdreiForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetUdreiForSV::GetUdreiForSV(const std::string& system, int svId)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
    }

    GetUdreiForSVPtr GetUdreiForSV::create(const std::string& system, int svId)
    {
      return std::make_shared<GetUdreiForSV>(system, svId);
    }

    GetUdreiForSVPtr GetUdreiForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetUdreiForSV>(ptr);
    }

    bool GetUdreiForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetUdreiForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetUdreiForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId"}; 
      return names; 
    }


    int GetUdreiForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetUdreiForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetUdreiForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetUdreiForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetUdreiForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
