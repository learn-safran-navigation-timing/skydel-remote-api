
#include "GetIntTxSignalPropagationLossResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxSignalPropagationLossResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxSignalPropagationLossResult::CmdName = "GetIntTxSignalPropagationLossResult";
    const char* const GetIntTxSignalPropagationLossResult::Documentation = "Result of GetIntTxSignalPropagationLoss.\n"
      "\n"
      "Name            Type   Description\n"
      "--------------- ------ ------------------------------------------\n"
      "PropagationLoss double The signal's propagation loss value in dB.\n"
      "TransmitterId   string Transmitter unique identifier.\n"
      "SignalId        string Signal unique identifier.";
    const char* const GetIntTxSignalPropagationLossResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIntTxSignalPropagationLossResult);


    GetIntTxSignalPropagationLossResult::GetIntTxSignalPropagationLossResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetIntTxSignalPropagationLossResult::GetIntTxSignalPropagationLossResult(double propagationLoss, const std::string& transmitterId, const std::string& signalId)
      : CommandResult(CmdName, TargetId)
    {

      setPropagationLoss(propagationLoss);
      setTransmitterId(transmitterId);
      setSignalId(signalId);
    }

    GetIntTxSignalPropagationLossResult::GetIntTxSignalPropagationLossResult(CommandBasePtr relatedCommand, double propagationLoss, const std::string& transmitterId, const std::string& signalId)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setPropagationLoss(propagationLoss);
      setTransmitterId(transmitterId);
      setSignalId(signalId);
    }


    GetIntTxSignalPropagationLossResultPtr GetIntTxSignalPropagationLossResult::create(double propagationLoss, const std::string& transmitterId, const std::string& signalId)
    {
      return std::make_shared<GetIntTxSignalPropagationLossResult>(propagationLoss, transmitterId, signalId);
    }

    GetIntTxSignalPropagationLossResultPtr GetIntTxSignalPropagationLossResult::create(CommandBasePtr relatedCommand, double propagationLoss, const std::string& transmitterId, const std::string& signalId)
    {
      return std::make_shared<GetIntTxSignalPropagationLossResult>(relatedCommand, propagationLoss, transmitterId, signalId);
    }

    GetIntTxSignalPropagationLossResultPtr GetIntTxSignalPropagationLossResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxSignalPropagationLossResult>(ptr);
    }

    bool GetIntTxSignalPropagationLossResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["PropagationLoss"])
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
        ;

    }

    std::string GetIntTxSignalPropagationLossResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIntTxSignalPropagationLossResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"PropagationLoss", "TransmitterId", "SignalId"}; 
      return names; 
    }


    double GetIntTxSignalPropagationLossResult::propagationLoss() const
    {
      return parse_json<double>::parse(m_values["PropagationLoss"]);
    }

    void GetIntTxSignalPropagationLossResult::setPropagationLoss(double propagationLoss)
    {
      setValue("PropagationLoss", parse_json<double>::format(propagationLoss, m_values.GetAllocator()));
    }



    std::string GetIntTxSignalPropagationLossResult::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void GetIntTxSignalPropagationLossResult::setTransmitterId(const std::string& transmitterId)
    {
      setValue("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()));
    }



    std::string GetIntTxSignalPropagationLossResult::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void GetIntTxSignalPropagationLossResult::setSignalId(const std::string& signalId)
    {
      setValue("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()));
    }


  }
}
