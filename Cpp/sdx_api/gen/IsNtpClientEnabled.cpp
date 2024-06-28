
#include "IsNtpClientEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsNtpClientEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsNtpClientEnabled::CmdName = "IsNtpClientEnabled";
    const char* const IsNtpClientEnabled::Documentation = "Indicates if the NTP client is enabled.";
    const char* const IsNtpClientEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsNtpClientEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsNtpClientEnabled);


    IsNtpClientEnabled::IsNtpClientEnabled()
      : CommandBase(CmdName, TargetId)
    {

    }

    IsNtpClientEnabledPtr IsNtpClientEnabled::create()
    {
      return std::make_shared<IsNtpClientEnabled>();
    }

    IsNtpClientEnabledPtr IsNtpClientEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsNtpClientEnabled>(ptr);
    }

    bool IsNtpClientEnabled::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsNtpClientEnabled::documentation() const { return Documentation; }

    const std::vector<std::string>& IsNtpClientEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsNtpClientEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
