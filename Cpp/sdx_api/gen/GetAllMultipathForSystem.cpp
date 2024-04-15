
#include "GetAllMultipathForSystem.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllMultipathForSystem
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllMultipathForSystem::CmdName = "GetAllMultipathForSystem";
    const char* const GetAllMultipathForSystem::Documentation = "Get all multipath ID for the specified constellation.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ --------------------------------------------------------------------------\n"
      "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
    const char* const GetAllMultipathForSystem::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetAllMultipathForSystem);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAllMultipathForSystem);


    GetAllMultipathForSystem::GetAllMultipathForSystem()
      : CommandBase(CmdName, TargetId)
    {}

    GetAllMultipathForSystem::GetAllMultipathForSystem(const std::string& system)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
    }

    GetAllMultipathForSystemPtr GetAllMultipathForSystem::create(const std::string& system)
    {
      return std::make_shared<GetAllMultipathForSystem>(system);
    }

    GetAllMultipathForSystemPtr GetAllMultipathForSystem::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllMultipathForSystem>(ptr);
    }

    bool GetAllMultipathForSystem::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string GetAllMultipathForSystem::documentation() const { return Documentation; }

    const std::vector<std::string>& GetAllMultipathForSystem::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System"}; 
      return names; 
    }


    int GetAllMultipathForSystem::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetAllMultipathForSystem::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetAllMultipathForSystem::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
