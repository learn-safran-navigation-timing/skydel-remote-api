
#include "ClearAllLOSForSystem.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearAllLOSForSystem
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearAllLOSForSystem::CmdName = "ClearAllLOSForSystem";
    const char* const ClearAllLOSForSystem::Documentation = "Enable Direct Line of Sight (LoS) of all satellites for the specified constellation.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ --------------------------------------------------------------------------\n"
      "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
    const char* const ClearAllLOSForSystem::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ClearAllLOSForSystem);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ClearAllLOSForSystem);


    ClearAllLOSForSystem::ClearAllLOSForSystem()
      : CommandBase(CmdName, TargetId)
    {}

    ClearAllLOSForSystem::ClearAllLOSForSystem(const std::string& system)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& ClearAllLOSForSystem::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System"}; 
      return names; 
    }


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
