
#include "gen/RemoveModulationAnechoicTargetInterference.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveModulationAnechoicTargetInterference
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveModulationAnechoicTargetInterference::CmdName = "RemoveModulationAnechoicTargetInterference";
    const char* const RemoveModulationAnechoicTargetInterference::Documentation = "Remove output assignation. This command works only for Anechoic Chamber\ntarget.";

    REGISTER_COMMAND_FACTORY(RemoveModulationAnechoicTargetInterference);


    RemoveModulationAnechoicTargetInterference::RemoveModulationAnechoicTargetInterference()
      : CommandBase(CmdName)
    {}

    RemoveModulationAnechoicTargetInterference::RemoveModulationAnechoicTargetInterference(int group)
      : CommandBase(CmdName)
    {

      setGroup(group);
    }

    RemoveModulationAnechoicTargetInterferencePtr RemoveModulationAnechoicTargetInterference::create(int group)
    {
      return std::make_shared<RemoveModulationAnechoicTargetInterference>(group);
    }

    RemoveModulationAnechoicTargetInterferencePtr RemoveModulationAnechoicTargetInterference::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveModulationAnechoicTargetInterference>(ptr);
    }

    bool RemoveModulationAnechoicTargetInterference::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Group"])
        ;

    }

    std::string RemoveModulationAnechoicTargetInterference::documentation() const { return Documentation; }


    int RemoveModulationAnechoicTargetInterference::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int RemoveModulationAnechoicTargetInterference::group() const
    {
      return parse_json<int>::parse(m_values["Group"]);
    }

    void RemoveModulationAnechoicTargetInterference::setGroup(int group)
    {
      m_values.AddMember("Group", parse_json<int>::format(group, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
