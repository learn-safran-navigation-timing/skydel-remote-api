
#include "GetIntTxSignalPropagationLoss.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxSignalPropagationLoss
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxSignalPropagationLoss::CmdName = "GetIntTxSignalPropagationLoss";
    const char* const GetIntTxSignalPropagationLoss::Documentation = "Gets the propagation loss value computed by Skydel for the specified interference signal.\n"
      "\n"
      "Name          Type   Description\n"
      "------------- ------ ------------------------------\n"
      "TransmitterId string Transmitter unique identifier.\n"
      "SignalId      string Signal unique identifier.";
    const char* const GetIntTxSignalPropagationLoss::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetIntTxSignalPropagationLoss);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIntTxSignalPropagationLoss);


    GetIntTxSignalPropagationLoss::GetIntTxSignalPropagationLoss()
      : CommandBase(CmdName, TargetId)
    {}

    GetIntTxSignalPropagationLoss::GetIntTxSignalPropagationLoss(const std::string& transmitterId, const std::string& signalId)
      : CommandBase(CmdName, TargetId)
    {

      setTransmitterId(transmitterId);
      setSignalId(signalId);
    }

    GetIntTxSignalPropagationLossPtr GetIntTxSignalPropagationLoss::create(const std::string& transmitterId, const std::string& signalId)
    {
      return std::make_shared<GetIntTxSignalPropagationLoss>(transmitterId, signalId);
    }

    GetIntTxSignalPropagationLossPtr GetIntTxSignalPropagationLoss::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxSignalPropagationLoss>(ptr);
    }

    bool GetIntTxSignalPropagationLoss::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
        ;

    }

    std::string GetIntTxSignalPropagationLoss::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIntTxSignalPropagationLoss::fieldNames() const 
    { 
      static const std::vector<std::string> names {"TransmitterId", "SignalId"}; 
      return names; 
    }


    int GetIntTxSignalPropagationLoss::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }


    std::string GetIntTxSignalPropagationLoss::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void GetIntTxSignalPropagationLoss::setTransmitterId(const std::string& transmitterId)
    {
      setValue("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()));
    }



    std::string GetIntTxSignalPropagationLoss::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void GetIntTxSignalPropagationLoss::setSignalId(const std::string& signalId)
    {
      setValue("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()));
    }


  }
}
