
#include "gen/GetPowerForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPowerForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPowerForSV::CmdName = "GetPowerForSV";
    const char* const GetPowerForSV::Documentation = "Please note the command GetPowerForSV is deprecated since 22.7. You may use GetAllPowerForSV.\n\nGet the power offset for specified satellite SV ID.";

    const char* const GetPowerForSV::Deprecated = "Please note the command GetPowerForSV is deprecated since 22.7. You may use GetAllPowerForSV.";

    REGISTER_COMMAND_FACTORY(GetPowerForSV);


    GetPowerForSV::GetPowerForSV()
      : CommandBase(CmdName)
    {}

    GetPowerForSV::GetPowerForSV(const std::string& system, int svId)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
    }

    GetPowerForSVPtr GetPowerForSV::create(const std::string& system, int svId)
    {
      return std::make_shared<GetPowerForSV>(system, svId);
    }

    GetPowerForSVPtr GetPowerForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPowerForSV>(ptr);
    }

    bool GetPowerForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetPowerForSV::documentation() const { return Documentation; }

    Sdx::optional<std::string> GetPowerForSV::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int GetPowerForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }


    std::string GetPowerForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetPowerForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPowerForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetPowerForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
