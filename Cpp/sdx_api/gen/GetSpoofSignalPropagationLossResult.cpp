
#include "GetSpoofSignalPropagationLossResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSpoofSignalPropagationLossResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSpoofSignalPropagationLossResult::CmdName = "GetSpoofSignalPropagationLossResult";
    const char* const GetSpoofSignalPropagationLossResult::Documentation = "Result of GetSpoofSignalPropagationLoss.\n"
      "\n"
      "Name            Type   Description\n"
      "--------------- ------ ------------------------------------------\n"
      "PropagationLoss double The signal's propagation loss value in dB.\n"
      "TransmitterId   string Transmitter unique identifier.\n"
      "SignalId        string Signal unique identifier.";
    const char* const GetSpoofSignalPropagationLossResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSpoofSignalPropagationLossResult);


    GetSpoofSignalPropagationLossResult::GetSpoofSignalPropagationLossResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetSpoofSignalPropagationLossResult::GetSpoofSignalPropagationLossResult(double propagationLoss, const std::string& transmitterId, const std::string& signalId)
      : CommandResult(CmdName, TargetId)
    {

      setPropagationLoss(propagationLoss);
      setTransmitterId(transmitterId);
      setSignalId(signalId);
    }

    GetSpoofSignalPropagationLossResult::GetSpoofSignalPropagationLossResult(CommandBasePtr relatedCommand, double propagationLoss, const std::string& transmitterId, const std::string& signalId)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setPropagationLoss(propagationLoss);
      setTransmitterId(transmitterId);
      setSignalId(signalId);
    }


    GetSpoofSignalPropagationLossResultPtr GetSpoofSignalPropagationLossResult::create(double propagationLoss, const std::string& transmitterId, const std::string& signalId)
    {
      return std::make_shared<GetSpoofSignalPropagationLossResult>(propagationLoss, transmitterId, signalId);
    }

    GetSpoofSignalPropagationLossResultPtr GetSpoofSignalPropagationLossResult::create(CommandBasePtr relatedCommand, double propagationLoss, const std::string& transmitterId, const std::string& signalId)
    {
      return std::make_shared<GetSpoofSignalPropagationLossResult>(relatedCommand, propagationLoss, transmitterId, signalId);
    }

    GetSpoofSignalPropagationLossResultPtr GetSpoofSignalPropagationLossResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSpoofSignalPropagationLossResult>(ptr);
    }

    bool GetSpoofSignalPropagationLossResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["PropagationLoss"])
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
        ;

    }

    std::string GetSpoofSignalPropagationLossResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSpoofSignalPropagationLossResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"PropagationLoss", "TransmitterId", "SignalId"}; 
      return names; 
    }


    double GetSpoofSignalPropagationLossResult::propagationLoss() const
    {
      return parse_json<double>::parse(m_values["PropagationLoss"]);
    }

    void GetSpoofSignalPropagationLossResult::setPropagationLoss(double propagationLoss)
    {
      setValue("PropagationLoss", parse_json<double>::format(propagationLoss, m_values.GetAllocator()));
    }



    std::string GetSpoofSignalPropagationLossResult::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void GetSpoofSignalPropagationLossResult::setTransmitterId(const std::string& transmitterId)
    {
      setValue("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()));
    }



    std::string GetSpoofSignalPropagationLossResult::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void GetSpoofSignalPropagationLossResult::setSignalId(const std::string& signalId)
    {
      setValue("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()));
    }


  }
}
