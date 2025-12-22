
#include "GetIntTxSignalManualPropagationLoss.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxSignalManualPropagationLoss
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxSignalManualPropagationLoss::CmdName = "GetIntTxSignalManualPropagationLoss";
    const char* const GetIntTxSignalManualPropagationLoss::Documentation = "Get the manual propagation loss for the given interference signal.\n"
      "\n"
      "Name          Type   Description\n"
      "------------- ------ ------------------------------\n"
      "TransmitterId string Transmitter unique identifier.\n"
      "SignalId      string Signal unique identifier.";
    const char* const GetIntTxSignalManualPropagationLoss::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetIntTxSignalManualPropagationLoss);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIntTxSignalManualPropagationLoss);


    GetIntTxSignalManualPropagationLoss::GetIntTxSignalManualPropagationLoss()
      : CommandBase(CmdName, TargetId)
    {}

    GetIntTxSignalManualPropagationLoss::GetIntTxSignalManualPropagationLoss(const std::string& transmitterId, const std::string& signalId)
      : CommandBase(CmdName, TargetId)
    {

      setTransmitterId(transmitterId);
      setSignalId(signalId);
    }

    GetIntTxSignalManualPropagationLossPtr GetIntTxSignalManualPropagationLoss::create(const std::string& transmitterId, const std::string& signalId)
    {
      return std::make_shared<GetIntTxSignalManualPropagationLoss>(transmitterId, signalId);
    }

    GetIntTxSignalManualPropagationLossPtr GetIntTxSignalManualPropagationLoss::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxSignalManualPropagationLoss>(ptr);
    }

    bool GetIntTxSignalManualPropagationLoss::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
        ;

    }

    std::string GetIntTxSignalManualPropagationLoss::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIntTxSignalManualPropagationLoss::fieldNames() const 
    { 
      static const std::vector<std::string> names {"TransmitterId", "SignalId"}; 
      return names; 
    }


    int GetIntTxSignalManualPropagationLoss::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string GetIntTxSignalManualPropagationLoss::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void GetIntTxSignalManualPropagationLoss::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxSignalManualPropagationLoss::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void GetIntTxSignalManualPropagationLoss::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
