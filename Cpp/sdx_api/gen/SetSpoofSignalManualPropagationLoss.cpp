
#include "SetSpoofSignalManualPropagationLoss.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSpoofSignalManualPropagationLoss
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSpoofSignalManualPropagationLoss::CmdName = "SetSpoofSignalManualPropagationLoss";
    const char* const SetSpoofSignalManualPropagationLoss::Documentation = "Set the manual propagation loss for the given spoofer signal. Value is used only if SetSpoofTxUseManualPropagationLoss has been set on the corresponding spoofer. This value is not preserved after simulation end.\n"
      "\n"
      "Name            Type   Description\n"
      "--------------- ------ --------------------------------------------------------------------------------------------------------\n"
      "PropagationLoss double The propagation loss in dB to use until the next call of this command, or until manual mode is disabled.\n"
      "TransmitterId   string Transmitter unique identifier.\n"
      "SignalId        string Signal unique identifier.";
    const char* const SetSpoofSignalManualPropagationLoss::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSpoofSignalManualPropagationLoss);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSpoofSignalManualPropagationLoss);


    SetSpoofSignalManualPropagationLoss::SetSpoofSignalManualPropagationLoss()
      : CommandBase(CmdName, TargetId)
    {}

    SetSpoofSignalManualPropagationLoss::SetSpoofSignalManualPropagationLoss(double propagationLoss, const std::string& transmitterId, const std::string& signalId)
      : CommandBase(CmdName, TargetId)
    {

      setPropagationLoss(propagationLoss);
      setTransmitterId(transmitterId);
      setSignalId(signalId);
    }

    SetSpoofSignalManualPropagationLossPtr SetSpoofSignalManualPropagationLoss::create(double propagationLoss, const std::string& transmitterId, const std::string& signalId)
    {
      return std::make_shared<SetSpoofSignalManualPropagationLoss>(propagationLoss, transmitterId, signalId);
    }

    SetSpoofSignalManualPropagationLossPtr SetSpoofSignalManualPropagationLoss::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSpoofSignalManualPropagationLoss>(ptr);
    }

    bool SetSpoofSignalManualPropagationLoss::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["PropagationLoss"])
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
        ;

    }

    std::string SetSpoofSignalManualPropagationLoss::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSpoofSignalManualPropagationLoss::fieldNames() const 
    { 
      static const std::vector<std::string> names {"PropagationLoss", "TransmitterId", "SignalId"}; 
      return names; 
    }


    int SetSpoofSignalManualPropagationLoss::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    double SetSpoofSignalManualPropagationLoss::propagationLoss() const
    {
      return parse_json<double>::parse(m_values["PropagationLoss"]);
    }

    void SetSpoofSignalManualPropagationLoss::setPropagationLoss(double propagationLoss)
    {
      m_values.AddMember("PropagationLoss", parse_json<double>::format(propagationLoss, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetSpoofSignalManualPropagationLoss::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void SetSpoofSignalManualPropagationLoss::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetSpoofSignalManualPropagationLoss::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void SetSpoofSignalManualPropagationLoss::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
