
#include "gen/RemoveAllPseudorangeRampForSystem.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveAllPseudorangeRampForSystem
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveAllPseudorangeRampForSystem::CmdName = "RemoveAllPseudorangeRampForSystem";
    const char* const RemoveAllPseudorangeRampForSystem::Documentation = "Remove all PSR Ramps for all satellites of the specified system.";

    REGISTER_COMMAND_FACTORY(RemoveAllPseudorangeRampForSystem);


    RemoveAllPseudorangeRampForSystem::RemoveAllPseudorangeRampForSystem()
      : CommandBase(CmdName)
    {}

    RemoveAllPseudorangeRampForSystem::RemoveAllPseudorangeRampForSystem(const std::string& system)
      : CommandBase(CmdName)
    {

      setSystem(system);
    }

    RemoveAllPseudorangeRampForSystemPtr RemoveAllPseudorangeRampForSystem::create(const std::string& system)
    {
      return std::make_shared<RemoveAllPseudorangeRampForSystem>(system);
    }

    RemoveAllPseudorangeRampForSystemPtr RemoveAllPseudorangeRampForSystem::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveAllPseudorangeRampForSystem>(ptr);
    }

    bool RemoveAllPseudorangeRampForSystem::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string RemoveAllPseudorangeRampForSystem::documentation() const { return Documentation; }


    int RemoveAllPseudorangeRampForSystem::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveAllPseudorangeRampForSystem::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void RemoveAllPseudorangeRampForSystem::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
