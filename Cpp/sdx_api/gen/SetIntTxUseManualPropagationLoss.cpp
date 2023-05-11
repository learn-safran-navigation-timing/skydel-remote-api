
#include "gen/SetIntTxUseManualPropagationLoss.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxUseManualPropagationLoss
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxUseManualPropagationLoss::CmdName = "SetIntTxUseManualPropagationLoss";
    const char* const SetIntTxUseManualPropagationLoss::Documentation = "Set whether a dynamic transmitter should only use user-provided propagation loss values. Propagation loss will not update automatically if set. This state is not preserved after simulation end.";

    REGISTER_COMMAND_FACTORY(SetIntTxUseManualPropagationLoss);


    SetIntTxUseManualPropagationLoss::SetIntTxUseManualPropagationLoss()
      : CommandBase(CmdName)
    {}

    SetIntTxUseManualPropagationLoss::SetIntTxUseManualPropagationLoss(bool manual, const std::string& id)
      : CommandBase(CmdName)
    {

      setManual(manual);
      setId(id);
    }

    SetIntTxUseManualPropagationLossPtr SetIntTxUseManualPropagationLoss::create(bool manual, const std::string& id)
    {
      return std::make_shared<SetIntTxUseManualPropagationLoss>(manual, id);
    }

    SetIntTxUseManualPropagationLossPtr SetIntTxUseManualPropagationLoss::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIntTxUseManualPropagationLoss>(ptr);
    }

    bool SetIntTxUseManualPropagationLoss::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Manual"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetIntTxUseManualPropagationLoss::documentation() const { return Documentation; }


    int SetIntTxUseManualPropagationLoss::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    bool SetIntTxUseManualPropagationLoss::manual() const
    {
      return parse_json<bool>::parse(m_values["Manual"]);
    }

    void SetIntTxUseManualPropagationLoss::setManual(bool manual)
    {
      m_values.AddMember("Manual", parse_json<bool>::format(manual, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxUseManualPropagationLoss::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetIntTxUseManualPropagationLoss::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
