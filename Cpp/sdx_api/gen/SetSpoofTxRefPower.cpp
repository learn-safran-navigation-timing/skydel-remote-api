
#include "gen/SetSpoofTxRefPower.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSpoofTxRefPower
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSpoofTxRefPower::CmdName = "SetSpoofTxRefPower";
    const char* const SetSpoofTxRefPower::Documentation = "Set the spoofing transmitter reference power.";

    REGISTER_COMMAND_FACTORY(SetSpoofTxRefPower);


    SetSpoofTxRefPower::SetSpoofTxRefPower()
      : CommandBase(CmdName)
    {}

    SetSpoofTxRefPower::SetSpoofTxRefPower(double power, const std::string& id)
      : CommandBase(CmdName)
    {

      setPower(power);
      setId(id);
    }

    SetSpoofTxRefPowerPtr SetSpoofTxRefPower::create(double power, const std::string& id)
    {
      return std::make_shared<SetSpoofTxRefPower>(power, id);
    }

    SetSpoofTxRefPowerPtr SetSpoofTxRefPower::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSpoofTxRefPower>(ptr);
    }

    bool SetSpoofTxRefPower::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["Power"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetSpoofTxRefPower::documentation() const { return Documentation; }


    int SetSpoofTxRefPower::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    double SetSpoofTxRefPower::power() const
    {
      return parse_json<double>::parse(m_values["Power"]);
    }

    void SetSpoofTxRefPower::setPower(double power)
    {
      m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetSpoofTxRefPower::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetSpoofTxRefPower::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
