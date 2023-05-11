
#include "gen/IsLOSEnabledForEachSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsLOSEnabledForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsLOSEnabledForEachSV::CmdName = "IsLOSEnabledForEachSV";
    const char* const IsLOSEnabledForEachSV::Documentation = "Get Direct Line Of Sight signal from satellite disabled or enabled. Generally used when only multipaths signal is visible.";

    REGISTER_COMMAND_FACTORY(IsLOSEnabledForEachSV);


    IsLOSEnabledForEachSV::IsLOSEnabledForEachSV()
      : CommandBase(CmdName)
    {}

    IsLOSEnabledForEachSV::IsLOSEnabledForEachSV(const std::string& system)
      : CommandBase(CmdName)
    {

      setSystem(system);
    }

    IsLOSEnabledForEachSVPtr IsLOSEnabledForEachSV::create(const std::string& system)
    {
      return std::make_shared<IsLOSEnabledForEachSV>(system);
    }

    IsLOSEnabledForEachSVPtr IsLOSEnabledForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsLOSEnabledForEachSV>(ptr);
    }

    bool IsLOSEnabledForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string IsLOSEnabledForEachSV::documentation() const { return Documentation; }


    int IsLOSEnabledForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsLOSEnabledForEachSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsLOSEnabledForEachSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
