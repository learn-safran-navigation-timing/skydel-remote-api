
#include "gen/IsEachSVEnabled.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsEachSVEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsEachSVEnabled::CmdName = "IsEachSVEnabled";
    const char* const IsEachSVEnabled::Documentation = "Get whether each satellite is enabled or disabled for this constellation.";

    REGISTER_COMMAND_FACTORY(IsEachSVEnabled);


    IsEachSVEnabled::IsEachSVEnabled()
      : CommandBase(CmdName)
    {}

    IsEachSVEnabled::IsEachSVEnabled(const std::string& system)
      : CommandBase(CmdName)
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
