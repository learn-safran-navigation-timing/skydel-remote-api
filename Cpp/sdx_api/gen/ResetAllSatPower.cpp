
#include "ResetAllSatPower.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ResetAllSatPower
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ResetAllSatPower::CmdName = "ResetAllSatPower";
    const char* const ResetAllSatPower::Documentation = "Please note the command ResetAllSatPower is deprecated since 21.7. You may use ResetManualPowerOffsets.\n"
      "\n"
      "Reset power offset for all satellites is specified system to default value\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ---------------------------------------------------------------------------\n"
      "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\".";
    const char* const ResetAllSatPower::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ResetAllSatPower);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ResetAllSatPower);


    ResetAllSatPower::ResetAllSatPower()
      : CommandBase(CmdName, TargetId)
    {}

    ResetAllSatPower::ResetAllSatPower(const std::string& system)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
    }

    ResetAllSatPowerPtr ResetAllSatPower::create(const std::string& system)
    {
      return std::make_shared<ResetAllSatPower>(system);
    }

    ResetAllSatPowerPtr ResetAllSatPower::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ResetAllSatPower>(ptr);
    }

    bool ResetAllSatPower::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string ResetAllSatPower::documentation() const { return Documentation; }

    const std::vector<std::string>& ResetAllSatPower::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System"}; 
      return names; 
    }


    int ResetAllSatPower::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }


    std::string ResetAllSatPower::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void ResetAllSatPower::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
