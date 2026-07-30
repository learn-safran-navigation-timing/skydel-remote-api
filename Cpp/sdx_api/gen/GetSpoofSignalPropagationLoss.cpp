
#include "GetSpoofSignalPropagationLoss.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSpoofSignalPropagationLoss
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSpoofSignalPropagationLoss::CmdName = "GetSpoofSignalPropagationLoss";
    const char* const GetSpoofSignalPropagationLoss::Documentation = "Gets the propagation loss value computed by Skydel for the specified spoofer signal.\n"
      "\n"
      "Name          Type   Description\n"
      "------------- ------ ------------------------------\n"
      "TransmitterId string Transmitter unique identifier.\n"
      "SignalId      string Signal unique identifier.";
    const char* const GetSpoofSignalPropagationLoss::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSpoofSignalPropagationLoss);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSpoofSignalPropagationLoss);


    GetSpoofSignalPropagationLoss::GetSpoofSignalPropagationLoss()
      : CommandBase(CmdName, TargetId)
    {}

    GetSpoofSignalPropagationLoss::GetSpoofSignalPropagationLoss(const std::string& transmitterId, const std::string& signalId)
      : CommandBase(CmdName, TargetId)
    {

      setTransmitterId(transmitterId);
      setSignalId(signalId);
    }

    GetSpoofSignalPropagationLossPtr GetSpoofSignalPropagationLoss::create(const std::string& transmitterId, const std::string& signalId)
    {
      return std::make_shared<GetSpoofSignalPropagationLoss>(transmitterId, signalId);
    }

    GetSpoofSignalPropagationLossPtr GetSpoofSignalPropagationLoss::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSpoofSignalPropagationLoss>(ptr);
    }

    bool GetSpoofSignalPropagationLoss::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
        ;

    }

    std::string GetSpoofSignalPropagationLoss::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSpoofSignalPropagationLoss::fieldNames() const 
    { 
      static const std::vector<std::string> names {"TransmitterId", "SignalId"}; 
      return names; 
    }


    int GetSpoofSignalPropagationLoss::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }


    std::string GetSpoofSignalPropagationLoss::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void GetSpoofSignalPropagationLoss::setTransmitterId(const std::string& transmitterId)
    {
      setValue("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()));
    }



    std::string GetSpoofSignalPropagationLoss::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void GetSpoofSignalPropagationLoss::setSignalId(const std::string& signalId)
    {
      setValue("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()));
    }


  }
}
