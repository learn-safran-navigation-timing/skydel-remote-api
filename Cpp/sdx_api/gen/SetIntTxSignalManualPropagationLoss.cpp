
#include "SetIntTxSignalManualPropagationLoss.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxSignalManualPropagationLoss
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxSignalManualPropagationLoss::CmdName = "SetIntTxSignalManualPropagationLoss";
    const char* const SetIntTxSignalManualPropagationLoss::Documentation = "Set the manual propagation loss for the given interference signal. Value is used only if SetIntTxUseManualPropagationLoss has been set on the corresponding transmitter. This value is not preserved after simulation end.\n"
      "\n"
      "Name            Type   Description\n"
      "--------------- ------ --------------------------------------------------------------------------------------------------------\n"
      "PropagationLoss double The propagation loss in dB to use until the next call of this command, or until manual mode is disabled.\n"
      "TransmitterId   string Transmitter unique identifier.\n"
      "SignalId        string Signal unique identifier.";
    const char* const SetIntTxSignalManualPropagationLoss::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetIntTxSignalManualPropagationLoss);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetIntTxSignalManualPropagationLoss);


    SetIntTxSignalManualPropagationLoss::SetIntTxSignalManualPropagationLoss()
      : CommandBase(CmdName, TargetId)
    {}

    SetIntTxSignalManualPropagationLoss::SetIntTxSignalManualPropagationLoss(double propagationLoss, const std::string& transmitterId, const std::string& signalId)
      : CommandBase(CmdName, TargetId)
    {

      setPropagationLoss(propagationLoss);
      setTransmitterId(transmitterId);
      setSignalId(signalId);
    }

    SetIntTxSignalManualPropagationLossPtr SetIntTxSignalManualPropagationLoss::create(double propagationLoss, const std::string& transmitterId, const std::string& signalId)
    {
      return std::make_shared<SetIntTxSignalManualPropagationLoss>(propagationLoss, transmitterId, signalId);
    }

    SetIntTxSignalManualPropagationLossPtr SetIntTxSignalManualPropagationLoss::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIntTxSignalManualPropagationLoss>(ptr);
    }

    bool SetIntTxSignalManualPropagationLoss::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["PropagationLoss"])
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
        ;

    }

    std::string SetIntTxSignalManualPropagationLoss::documentation() const { return Documentation; }

    const std::vector<std::string>& SetIntTxSignalManualPropagationLoss::fieldNames() const 
    { 
      static const std::vector<std::string> names {"PropagationLoss", "TransmitterId", "SignalId"}; 
      return names; 
    }


    int SetIntTxSignalManualPropagationLoss::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    double SetIntTxSignalManualPropagationLoss::propagationLoss() const
    {
      return parse_json<double>::parse(m_values["PropagationLoss"]);
    }

    void SetIntTxSignalManualPropagationLoss::setPropagationLoss(double propagationLoss)
    {
      m_values.AddMember("PropagationLoss", parse_json<double>::format(propagationLoss, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxSignalManualPropagationLoss::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void SetIntTxSignalManualPropagationLoss::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxSignalManualPropagationLoss::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void SetIntTxSignalManualPropagationLoss::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
