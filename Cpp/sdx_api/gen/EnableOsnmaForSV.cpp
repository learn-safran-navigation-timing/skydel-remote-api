
#include "EnableOsnmaForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableOsnmaForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableOsnmaForSV::CmdName = "EnableOsnmaForSV";
    const char* const EnableOsnmaForSV::Documentation = "Enable (or disable) OSNMA for specified Galileo's satellite.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- -----------------------------------------------------------\n"
      "SvId    int  The satellite's SV ID (use 0 for all Galileo's satellites).\n"
      "Enabled bool OSNMA is enabled when value is True.";
    const char* const EnableOsnmaForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableOsnmaForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableOsnmaForSV);


    EnableOsnmaForSV::EnableOsnmaForSV()
      : CommandBase(CmdName, TargetId)
    {}

    EnableOsnmaForSV::EnableOsnmaForSV(int svId, bool enabled)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setEnabled(enabled);
    }

    EnableOsnmaForSVPtr EnableOsnmaForSV::create(int svId, bool enabled)
    {
      return std::make_shared<EnableOsnmaForSV>(svId, enabled);
    }

    EnableOsnmaForSVPtr EnableOsnmaForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableOsnmaForSV>(ptr);
    }

    bool EnableOsnmaForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableOsnmaForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableOsnmaForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Enabled"}; 
      return names; 
    }


    int EnableOsnmaForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int EnableOsnmaForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void EnableOsnmaForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool EnableOsnmaForSV::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableOsnmaForSV::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
