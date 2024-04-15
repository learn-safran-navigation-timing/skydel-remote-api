
#include "GetAllMultipathForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllMultipathForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllMultipathForSV::CmdName = "GetAllMultipathForSV";
    const char* const GetAllMultipathForSV::Documentation = "Get all multipath ID for the specified satellite of the constellation.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ --------------------------------------------------------------------------\n"
      "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "SvId   int    The satellite's SV ID";
    const char* const GetAllMultipathForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetAllMultipathForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAllMultipathForSV);


    GetAllMultipathForSV::GetAllMultipathForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetAllMultipathForSV::GetAllMultipathForSV(const std::string& system, int svId)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
    }

    GetAllMultipathForSVPtr GetAllMultipathForSV::create(const std::string& system, int svId)
    {
      return std::make_shared<GetAllMultipathForSV>(system, svId);
    }

    GetAllMultipathForSVPtr GetAllMultipathForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllMultipathForSV>(ptr);
    }

    bool GetAllMultipathForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetAllMultipathForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetAllMultipathForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId"}; 
      return names; 
    }


    int GetAllMultipathForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetAllMultipathForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetAllMultipathForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetAllMultipathForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetAllMultipathForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
