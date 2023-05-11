
#include "gen/GetEnabledSignalsForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetEnabledSignalsForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetEnabledSignalsForSV::CmdName = "GetEnabledSignalsForSV";
    const char* const GetEnabledSignalsForSV::Documentation = "Get the list of enabled signals for a specified SV ID.";

    REGISTER_COMMAND_FACTORY(GetEnabledSignalsForSV);


    GetEnabledSignalsForSV::GetEnabledSignalsForSV()
      : CommandBase(CmdName)
    {}

    GetEnabledSignalsForSV::GetEnabledSignalsForSV(const std::string& system, int svId)
      : CommandBase(CmdName)
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
