
#include "gen/SetIntTxIgnoreVehicleAntennaPattern.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxIgnoreVehicleAntennaPattern
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxIgnoreVehicleAntennaPattern::CmdName = "SetIntTxIgnoreVehicleAntennaPattern";
    const char* const SetIntTxIgnoreVehicleAntennaPattern::Documentation = "Please note the command SetIntTxIgnoreVehicleAntennaPattern is deprecated since 20.2. You may use SetIntTxIgnoreRxAntennaPatterns.\n\nSet whether a dynamic transmitter should ignore the vehicle's antenna patterns (gain and phase).";

    REGISTER_COMMAND_FACTORY(SetIntTxIgnoreVehicleAntennaPattern);


    SetIntTxIgnoreVehicleAntennaPattern::SetIntTxIgnoreVehicleAntennaPattern()
      : CommandBase(CmdName)
    {}

    SetIntTxIgnoreVehicleAntennaPattern::SetIntTxIgnoreVehicleAntennaPattern(bool ignore, const std::string& id)
      : CommandBase(CmdName)
    {

      setIgnore(ignore);
      setId(id);
    }

    SetIntTxIgnoreVehicleAntennaPatternPtr SetIntTxIgnoreVehicleAntennaPattern::create(bool ignore, const std::string& id)
    {
      return std::make_shared<SetIntTxIgnoreVehicleAntennaPattern>(ignore, id);
    }

    SetIntTxIgnoreVehicleAntennaPatternPtr SetIntTxIgnoreVehicleAntennaPattern::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIntTxIgnoreVehicleAntennaPattern>(ptr);
    }

    bool SetIntTxIgnoreVehicleAntennaPattern::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Ignore"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetIntTxIgnoreVehicleAntennaPattern::documentation() const { return Documentation; }


    int SetIntTxIgnoreVehicleAntennaPattern::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    bool SetIntTxIgnoreVehicleAntennaPattern::ignore() const
    {
      return parse_json<bool>::parse(m_values["Ignore"]);
    }

    void SetIntTxIgnoreVehicleAntennaPattern::setIgnore(bool ignore)
    {
      m_values.AddMember("Ignore", parse_json<bool>::format(ignore, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxIgnoreVehicleAntennaPattern::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetIntTxIgnoreVehicleAntennaPattern::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
