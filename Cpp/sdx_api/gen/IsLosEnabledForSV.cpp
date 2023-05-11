
#include "gen/IsLosEnabledForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsLosEnabledForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsLosEnabledForSV::CmdName = "IsLosEnabledForSV";
    const char* const IsLosEnabledForSV::Documentation = "Get Direct Line Of Sight signal from satellite enabled or disabled. Generally used when only multipaths signal is visible.";

    REGISTER_COMMAND_FACTORY(IsLosEnabledForSV);


    IsLosEnabledForSV::IsLosEnabledForSV()
      : CommandBase(CmdName)
    {}

    IsLosEnabledForSV::IsLosEnabledForSV(const std::string& system, int svId)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
    }

    IsLosEnabledForSVPtr IsLosEnabledForSV::create(const std::string& system, int svId)
    {
      return std::make_shared<IsLosEnabledForSV>(system, svId);
    }

    IsLosEnabledForSVPtr IsLosEnabledForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsLosEnabledForSV>(ptr);
    }

    bool IsLosEnabledForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string IsLosEnabledForSV::documentation() const { return Documentation; }


    int IsLosEnabledForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsLosEnabledForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsLosEnabledForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int IsLosEnabledForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void IsLosEnabledForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
