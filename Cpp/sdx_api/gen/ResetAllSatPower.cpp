
#include "gen/ResetAllSatPower.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ResetAllSatPower
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ResetAllSatPower::CmdName = "ResetAllSatPower";
    const char* const ResetAllSatPower::Documentation = "Please note the command ResetAllSatPower is deprecated since 21.7. You may use ResetManualPowerOffsets.\n\nReset power offset for all satellites is specified system to default value";

    REGISTER_COMMAND_FACTORY(ResetAllSatPower);


    ResetAllSatPower::ResetAllSatPower()
      : CommandBase(CmdName)
    {}

    ResetAllSatPower::ResetAllSatPower(const std::string& system)
      : CommandBase(CmdName)
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
