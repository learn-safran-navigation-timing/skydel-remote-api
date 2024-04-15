
#include "SetSpoofTxUseManualPropagationLoss.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSpoofTxUseManualPropagationLoss
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSpoofTxUseManualPropagationLoss::CmdName = "SetSpoofTxUseManualPropagationLoss";
    const char* const SetSpoofTxUseManualPropagationLoss::Documentation = "Set whether a spoofer should only use user-provided propagation loss values. Propagation loss will not update automatically if set. This state is not preserved after simulation end.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ -------------------------------------------------------------\n"
      "Manual bool   If true, propagation loss will be 1000 dB until set manually.\n"
      "Id     string Spoofing transmitter unique identifier.";
    const char* const SetSpoofTxUseManualPropagationLoss::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSpoofTxUseManualPropagationLoss);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSpoofTxUseManualPropagationLoss);


    SetSpoofTxUseManualPropagationLoss::SetSpoofTxUseManualPropagationLoss()
      : CommandBase(CmdName, TargetId)
    {}

    SetSpoofTxUseManualPropagationLoss::SetSpoofTxUseManualPropagationLoss(bool manual, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setManual(manual);
      setId(id);
    }

    SetSpoofTxUseManualPropagationLossPtr SetSpoofTxUseManualPropagationLoss::create(bool manual, const std::string& id)
    {
      return std::make_shared<SetSpoofTxUseManualPropagationLoss>(manual, id);
    }

    SetSpoofTxUseManualPropagationLossPtr SetSpoofTxUseManualPropagationLoss::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSpoofTxUseManualPropagationLoss>(ptr);
    }

    bool SetSpoofTxUseManualPropagationLoss::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Manual"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetSpoofTxUseManualPropagationLoss::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSpoofTxUseManualPropagationLoss::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Manual", "Id"}; 
      return names; 
    }


    int SetSpoofTxUseManualPropagationLoss::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    bool SetSpoofTxUseManualPropagationLoss::manual() const
    {
      return parse_json<bool>::parse(m_values["Manual"]);
    }

    void SetSpoofTxUseManualPropagationLoss::setManual(bool manual)
    {
      m_values.AddMember("Manual", parse_json<bool>::format(manual, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetSpoofTxUseManualPropagationLoss::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetSpoofTxUseManualPropagationLoss::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
