
#include "GetSpoofSignalManualPropagationLoss.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSpoofSignalManualPropagationLoss
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSpoofSignalManualPropagationLoss::CmdName = "GetSpoofSignalManualPropagationLoss";
    const char* const GetSpoofSignalManualPropagationLoss::Documentation = "Get the manual propagation loss for the given spoofer signal.\n"
      "\n"
      "Name          Type   Description\n"
      "------------- ------ ------------------------------\n"
      "TransmitterId string Transmitter unique identifier.\n"
      "SignalId      string Signal unique identifier.";
    const char* const GetSpoofSignalManualPropagationLoss::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSpoofSignalManualPropagationLoss);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSpoofSignalManualPropagationLoss);


    GetSpoofSignalManualPropagationLoss::GetSpoofSignalManualPropagationLoss()
      : CommandBase(CmdName, TargetId)
    {}

    GetSpoofSignalManualPropagationLoss::GetSpoofSignalManualPropagationLoss(const std::string& transmitterId, const std::string& signalId)
      : CommandBase(CmdName, TargetId)
    {

      setTransmitterId(transmitterId);
      setSignalId(signalId);
    }

    GetSpoofSignalManualPropagationLossPtr GetSpoofSignalManualPropagationLoss::create(const std::string& transmitterId, const std::string& signalId)
    {
      return std::make_shared<GetSpoofSignalManualPropagationLoss>(transmitterId, signalId);
    }

    GetSpoofSignalManualPropagationLossPtr GetSpoofSignalManualPropagationLoss::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSpoofSignalManualPropagationLoss>(ptr);
    }

    bool GetSpoofSignalManualPropagationLoss::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
        ;

    }

    std::string GetSpoofSignalManualPropagationLoss::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSpoofSignalManualPropagationLoss::fieldNames() const 
    { 
      static const std::vector<std::string> names {"TransmitterId", "SignalId"}; 
      return names; 
    }


    int GetSpoofSignalManualPropagationLoss::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string GetSpoofSignalManualPropagationLoss::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void GetSpoofSignalManualPropagationLoss::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSpoofSignalManualPropagationLoss::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void GetSpoofSignalManualPropagationLoss::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
