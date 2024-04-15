
#include "EnableLogRinex.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableLogRinex
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableLogRinex::CmdName = "EnableLogRinex";
    const char* const EnableLogRinex::Documentation = "Enable (or disable) ephemeris data logging in RINEX v3.03 format\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ------------------------------------------------\n"
      "Enabled bool If true, files will be created during simulation";
    const char* const EnableLogRinex::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableLogRinex);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableLogRinex);


    EnableLogRinex::EnableLogRinex()
      : CommandBase(CmdName, TargetId)
    {}

    EnableLogRinex::EnableLogRinex(bool enabled)
      : CommandBase(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    EnableLogRinexPtr EnableLogRinex::create(bool enabled)
    {
      return std::make_shared<EnableLogRinex>(enabled);
    }

    EnableLogRinexPtr EnableLogRinex::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableLogRinex>(ptr);
    }

    bool EnableLogRinex::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableLogRinex::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableLogRinex::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


    int EnableLogRinex::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool EnableLogRinex::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableLogRinex::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
