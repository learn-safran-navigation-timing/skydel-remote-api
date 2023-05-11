
#include "gen/EnableSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableSV::CmdName = "EnableSV";
    const char* const EnableSV::Documentation = "Enable or disable a satellite for this constellation.";

    REGISTER_COMMAND_FACTORY(EnableSV);


    EnableSV::EnableSV()
      : CommandBase(CmdName)
    {}

    EnableSV::EnableSV(const std::string& system, int svId, bool enabled)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setEnabled(enabled);
    }

    EnableSVPtr EnableSV::create(const std::string& system, int svId, bool enabled)
    {
      return std::make_shared<EnableSV>(system, svId, enabled);
    }

    EnableSVPtr EnableSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableSV>(ptr);
    }

    bool EnableSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableSV::documentation() const { return Documentation; }


    int EnableSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string EnableSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void EnableSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int EnableSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void EnableSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool EnableSV::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableSV::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
