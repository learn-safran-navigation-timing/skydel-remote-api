
#include "GetEnabledSignalsForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetEnabledSignalsForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetEnabledSignalsForSV::CmdName = "GetEnabledSignalsForSV";
    const char* const GetEnabledSignalsForSV::Documentation = "Get the list of enabled signals for a specified SV ID.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ----------------------------------------------------------------------------------------------\n"
      "System string The system, can be \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\".\n"
      "SvId   int    The satellite SV ID.";
    const char* const GetEnabledSignalsForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetEnabledSignalsForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetEnabledSignalsForSV);


    GetEnabledSignalsForSV::GetEnabledSignalsForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetEnabledSignalsForSV::GetEnabledSignalsForSV(const std::string& system, int svId)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
    }

    GetEnabledSignalsForSVPtr GetEnabledSignalsForSV::create(const std::string& system, int svId)
    {
      return std::make_shared<GetEnabledSignalsForSV>(system, svId);
    }

    GetEnabledSignalsForSVPtr GetEnabledSignalsForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetEnabledSignalsForSV>(ptr);
    }

    bool GetEnabledSignalsForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetEnabledSignalsForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetEnabledSignalsForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId"}; 
      return names; 
    }


    int GetEnabledSignalsForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string GetEnabledSignalsForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetEnabledSignalsForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetEnabledSignalsForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetEnabledSignalsForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
