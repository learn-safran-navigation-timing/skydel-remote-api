
#include "GetIntTxSignalManualPropagationLossResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxSignalManualPropagationLossResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxSignalManualPropagationLossResult::CmdName = "GetIntTxSignalManualPropagationLossResult";
    const char* const GetIntTxSignalManualPropagationLossResult::Documentation = "Result of GetIntTxSignalManualPropagationLoss.\n"
      "\n"
      "Name            Type   Description\n"
      "--------------- ------ --------------------------------------------------------------------------------------------------------\n"
      "PropagationLoss double The propagation loss in dB to use until the next call of this command, or until manual mode is disabled.\n"
      "TransmitterId   string Transmitter unique identifier.\n"
      "SignalId        string Signal unique identifier.";
    const char* const GetIntTxSignalManualPropagationLossResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIntTxSignalManualPropagationLossResult);


    GetIntTxSignalManualPropagationLossResult::GetIntTxSignalManualPropagationLossResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetIntTxSignalManualPropagationLossResult::GetIntTxSignalManualPropagationLossResult(double propagationLoss, const std::string& transmitterId, const std::string& signalId)
      : CommandResult(CmdName, TargetId)
    {

      setPropagationLoss(propagationLoss);
      setTransmitterId(transmitterId);
      setSignalId(signalId);
    }

    GetIntTxSignalManualPropagationLossResult::GetIntTxSignalManualPropagationLossResult(CommandBasePtr relatedCommand, double propagationLoss, const std::string& transmitterId, const std::string& signalId)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setPropagationLoss(propagationLoss);
      setTransmitterId(transmitterId);
      setSignalId(signalId);
    }


    GetIntTxSignalManualPropagationLossResultPtr GetIntTxSignalManualPropagationLossResult::create(double propagationLoss, const std::string& transmitterId, const std::string& signalId)
    {
      return std::make_shared<GetIntTxSignalManualPropagationLossResult>(propagationLoss, transmitterId, signalId);
    }

    GetIntTxSignalManualPropagationLossResultPtr GetIntTxSignalManualPropagationLossResult::create(CommandBasePtr relatedCommand, double propagationLoss, const std::string& transmitterId, const std::string& signalId)
    {
      return std::make_shared<GetIntTxSignalManualPropagationLossResult>(relatedCommand, propagationLoss, transmitterId, signalId);
    }

    GetIntTxSignalManualPropagationLossResultPtr GetIntTxSignalManualPropagationLossResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxSignalManualPropagationLossResult>(ptr);
    }

    bool GetIntTxSignalManualPropagationLossResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["PropagationLoss"])
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
        ;

    }

    std::string GetIntTxSignalManualPropagationLossResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIntTxSignalManualPropagationLossResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"PropagationLoss", "TransmitterId", "SignalId"}; 
      return names; 
    }


    double GetIntTxSignalManualPropagationLossResult::propagationLoss() const
    {
      return parse_json<double>::parse(m_values["PropagationLoss"]);
    }

    void GetIntTxSignalManualPropagationLossResult::setPropagationLoss(double propagationLoss)
    {
      m_values.AddMember("PropagationLoss", parse_json<double>::format(propagationLoss, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxSignalManualPropagationLossResult::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void GetIntTxSignalManualPropagationLossResult::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxSignalManualPropagationLossResult::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void GetIntTxSignalManualPropagationLossResult::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
