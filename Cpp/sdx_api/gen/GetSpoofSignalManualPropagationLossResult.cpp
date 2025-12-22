
#include "GetSpoofSignalManualPropagationLossResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSpoofSignalManualPropagationLossResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSpoofSignalManualPropagationLossResult::CmdName = "GetSpoofSignalManualPropagationLossResult";
    const char* const GetSpoofSignalManualPropagationLossResult::Documentation = "Result of GetSpoofSignalManualPropagationLoss.\n"
      "\n"
      "Name            Type   Description\n"
      "--------------- ------ --------------------------------------------------------------------------------------------------------\n"
      "PropagationLoss double The propagation loss in dB to use until the next call of this command, or until manual mode is disabled.\n"
      "TransmitterId   string Transmitter unique identifier.\n"
      "SignalId        string Signal unique identifier.";
    const char* const GetSpoofSignalManualPropagationLossResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSpoofSignalManualPropagationLossResult);


    GetSpoofSignalManualPropagationLossResult::GetSpoofSignalManualPropagationLossResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetSpoofSignalManualPropagationLossResult::GetSpoofSignalManualPropagationLossResult(double propagationLoss, const std::string& transmitterId, const std::string& signalId)
      : CommandResult(CmdName, TargetId)
    {

      setPropagationLoss(propagationLoss);
      setTransmitterId(transmitterId);
      setSignalId(signalId);
    }

    GetSpoofSignalManualPropagationLossResult::GetSpoofSignalManualPropagationLossResult(CommandBasePtr relatedCommand, double propagationLoss, const std::string& transmitterId, const std::string& signalId)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setPropagationLoss(propagationLoss);
      setTransmitterId(transmitterId);
      setSignalId(signalId);
    }


    GetSpoofSignalManualPropagationLossResultPtr GetSpoofSignalManualPropagationLossResult::create(double propagationLoss, const std::string& transmitterId, const std::string& signalId)
    {
      return std::make_shared<GetSpoofSignalManualPropagationLossResult>(propagationLoss, transmitterId, signalId);
    }

    GetSpoofSignalManualPropagationLossResultPtr GetSpoofSignalManualPropagationLossResult::create(CommandBasePtr relatedCommand, double propagationLoss, const std::string& transmitterId, const std::string& signalId)
    {
      return std::make_shared<GetSpoofSignalManualPropagationLossResult>(relatedCommand, propagationLoss, transmitterId, signalId);
    }

    GetSpoofSignalManualPropagationLossResultPtr GetSpoofSignalManualPropagationLossResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSpoofSignalManualPropagationLossResult>(ptr);
    }

    bool GetSpoofSignalManualPropagationLossResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["PropagationLoss"])
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
        ;

    }

    std::string GetSpoofSignalManualPropagationLossResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSpoofSignalManualPropagationLossResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"PropagationLoss", "TransmitterId", "SignalId"}; 
      return names; 
    }


    double GetSpoofSignalManualPropagationLossResult::propagationLoss() const
    {
      return parse_json<double>::parse(m_values["PropagationLoss"]);
    }

    void GetSpoofSignalManualPropagationLossResult::setPropagationLoss(double propagationLoss)
    {
      m_values.AddMember("PropagationLoss", parse_json<double>::format(propagationLoss, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSpoofSignalManualPropagationLossResult::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void GetSpoofSignalManualPropagationLossResult::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSpoofSignalManualPropagationLossResult::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void GetSpoofSignalManualPropagationLossResult::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
