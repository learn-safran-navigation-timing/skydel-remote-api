
#include "IsLOSEnabledForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsLOSEnabledForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsLOSEnabledForEachSV::CmdName = "IsLOSEnabledForEachSV";
    const char* const IsLOSEnabledForEachSV::Documentation = "Get Direct Line Of Sight signal from satellite disabled or enabled. Generally used when only multipaths signal is visible.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ --------------------------------------------------------------------------\n"
      "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
    const char* const IsLOSEnabledForEachSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsLOSEnabledForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsLOSEnabledForEachSV);


    IsLOSEnabledForEachSV::IsLOSEnabledForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    IsLOSEnabledForEachSV::IsLOSEnabledForEachSV(const std::string& system)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& IsLOSEnabledForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System"}; 
      return names; 
    }


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
