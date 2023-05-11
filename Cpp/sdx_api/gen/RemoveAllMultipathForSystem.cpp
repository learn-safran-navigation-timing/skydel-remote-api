
#include "gen/RemoveAllMultipathForSystem.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveAllMultipathForSystem
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveAllMultipathForSystem::CmdName = "RemoveAllMultipathForSystem";
    const char* const RemoveAllMultipathForSystem::Documentation = "Disable all multipath for the specified constellation.";

    REGISTER_COMMAND_FACTORY(RemoveAllMultipathForSystem);


    RemoveAllMultipathForSystem::RemoveAllMultipathForSystem()
      : CommandBase(CmdName)
    {}

    RemoveAllMultipathForSystem::RemoveAllMultipathForSystem(const std::string& system, bool reset)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setReset(reset);
    }

    RemoveAllMultipathForSystemPtr RemoveAllMultipathForSystem::create(const std::string& system, bool reset)
    {
      return std::make_shared<RemoveAllMultipathForSystem>(system, reset);
    }

    RemoveAllMultipathForSystemPtr RemoveAllMultipathForSystem::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveAllMultipathForSystem>(ptr);
    }

    bool RemoveAllMultipathForSystem::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<bool>::is_valid(m_values["Reset"])
        ;

    }

    std::string RemoveAllMultipathForSystem::documentation() const { return Documentation; }


    int RemoveAllMultipathForSystem::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveAllMultipathForSystem::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void RemoveAllMultipathForSystem::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool RemoveAllMultipathForSystem::reset() const
    {
      return parse_json<bool>::parse(m_values["Reset"]);
    }

    void RemoveAllMultipathForSystem::setReset(bool reset)
    {
      m_values.AddMember("Reset", parse_json<bool>::format(reset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
