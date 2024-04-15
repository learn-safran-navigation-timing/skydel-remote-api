
#include "IsRFOutputEnabledForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsRFOutputEnabledForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsRFOutputEnabledForEachSV::CmdName = "IsRFOutputEnabledForEachSV";
    const char* const IsRFOutputEnabledForEachSV::Documentation = "Tells if the RF output is enabled or disabled for each satellite.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ --------------------------------------------------------------------------\n"
      "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
    const char* const IsRFOutputEnabledForEachSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsRFOutputEnabledForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsRFOutputEnabledForEachSV);


    IsRFOutputEnabledForEachSV::IsRFOutputEnabledForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    IsRFOutputEnabledForEachSV::IsRFOutputEnabledForEachSV(const std::string& system)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
    }

    IsRFOutputEnabledForEachSVPtr IsRFOutputEnabledForEachSV::create(const std::string& system)
    {
      return std::make_shared<IsRFOutputEnabledForEachSV>(system);
    }

    IsRFOutputEnabledForEachSVPtr IsRFOutputEnabledForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsRFOutputEnabledForEachSV>(ptr);
    }

    bool IsRFOutputEnabledForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string IsRFOutputEnabledForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& IsRFOutputEnabledForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System"}; 
      return names; 
    }


    int IsRFOutputEnabledForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsRFOutputEnabledForEachSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsRFOutputEnabledForEachSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
