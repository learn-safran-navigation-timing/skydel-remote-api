
#include "EnableLogRaw.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableLogRaw
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableLogRaw::CmdName = "EnableLogRaw";
    const char* const EnableLogRaw::Documentation = "Enable (or disable) raw data logging (pseudorange, antenna gain, receiver position, satellite position, etc.)\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- -----------------------------------------------\n"
      "Enabled bool If true, file will be created during simulation";
    const char* const EnableLogRaw::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableLogRaw);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableLogRaw);


    EnableLogRaw::EnableLogRaw()
      : CommandBase(CmdName, TargetId)
    {}

    EnableLogRaw::EnableLogRaw(bool enabled)
      : CommandBase(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    EnableLogRawPtr EnableLogRaw::create(bool enabled)
    {
      return std::make_shared<EnableLogRaw>(enabled);
    }

    EnableLogRawPtr EnableLogRaw::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableLogRaw>(ptr);
    }

    bool EnableLogRaw::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableLogRaw::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableLogRaw::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


    int EnableLogRaw::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool EnableLogRaw::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableLogRaw::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
