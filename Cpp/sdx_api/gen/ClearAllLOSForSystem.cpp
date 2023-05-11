
#include "gen/ClearAllLOSForSystem.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearAllLOSForSystem
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearAllLOSForSystem::CmdName = "ClearAllLOSForSystem";
    const char* const ClearAllLOSForSystem::Documentation = "Enable Direct Line of Sight (LoS) of all satellites for the specified constellation.";

    REGISTER_COMMAND_FACTORY(ClearAllLOSForSystem);


    ClearAllLOSForSystem::ClearAllLOSForSystem()
      : CommandBase(CmdName)
    {}

    ClearAllLOSForSystem::ClearAllLOSForSystem(const std::string& system)
      : CommandBase(CmdName)
    {

      setSystem(system);
    }

    ClearAllLOSForSystemPtr ClearAllLOSForSystem::create(const std::string& system)
    {
      return std::make_shared<ClearAllLOSForSystem>(system);
    }

    ClearAllLOSForSystemPtr ClearAllLOSForSystem::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ClearAllLOSForSystem>(ptr);
    }

    bool ClearAllLOSForSystem::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string ClearAllLOSForSystem::documentation() const { return Documentation; }


    int ClearAllLOSForSystem::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string ClearAllLOSForSystem::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void ClearAllLOSForSystem::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
