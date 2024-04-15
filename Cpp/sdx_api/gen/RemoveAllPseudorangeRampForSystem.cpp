
#include "RemoveAllPseudorangeRampForSystem.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveAllPseudorangeRampForSystem
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveAllPseudorangeRampForSystem::CmdName = "RemoveAllPseudorangeRampForSystem";
    const char* const RemoveAllPseudorangeRampForSystem::Documentation = "Remove all PSR Ramps for all satellites of the specified system.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ --------------------------------------------------------------------------\n"
      "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
    const char* const RemoveAllPseudorangeRampForSystem::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RemoveAllPseudorangeRampForSystem);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RemoveAllPseudorangeRampForSystem);


    RemoveAllPseudorangeRampForSystem::RemoveAllPseudorangeRampForSystem()
      : CommandBase(CmdName, TargetId)
    {}

    RemoveAllPseudorangeRampForSystem::RemoveAllPseudorangeRampForSystem(const std::string& system)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& RemoveAllPseudorangeRampForSystem::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System"}; 
      return names; 
    }


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
