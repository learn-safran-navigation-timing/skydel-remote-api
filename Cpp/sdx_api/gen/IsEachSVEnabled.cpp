
#include "IsEachSVEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsEachSVEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsEachSVEnabled::CmdName = "IsEachSVEnabled";
    const char* const IsEachSVEnabled::Documentation = "Get whether each satellite is enabled or disabled for this constellation.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ----------------------------------------------------------------------------------------------------------------\n"
      "System string The satellites' constellation. Can be \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
    const char* const IsEachSVEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsEachSVEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsEachSVEnabled);


    IsEachSVEnabled::IsEachSVEnabled()
      : CommandBase(CmdName, TargetId)
    {}

    IsEachSVEnabled::IsEachSVEnabled(const std::string& system)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
    }

    IsEachSVEnabledPtr IsEachSVEnabled::create(const std::string& system)
    {
      return std::make_shared<IsEachSVEnabled>(system);
    }

    IsEachSVEnabledPtr IsEachSVEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsEachSVEnabled>(ptr);
    }

    bool IsEachSVEnabled::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string IsEachSVEnabled::documentation() const { return Documentation; }

    const std::vector<std::string>& IsEachSVEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System"}; 
      return names; 
    }


    int IsEachSVEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsEachSVEnabled::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsEachSVEnabled::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
