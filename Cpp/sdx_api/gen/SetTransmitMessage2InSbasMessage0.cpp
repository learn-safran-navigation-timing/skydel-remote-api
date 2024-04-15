
#include "SetTransmitMessage2InSbasMessage0.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetTransmitMessage2InSbasMessage0
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetTransmitMessage2InSbasMessage0::CmdName = "SetTransmitMessage2InSbasMessage0";
    const char* const SetTransmitMessage2InSbasMessage0::Documentation = "Set whether SBAS should transmit message 2 instead of message 0.\n"
      "\n"
      "Name             Type Description\n"
      "---------------- ---- ---------------------------------------------------------\n"
      "TransmitMessage2 bool Whether SBAS should transmit message type 2 instead of 0.";
    const char* const SetTransmitMessage2InSbasMessage0::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetTransmitMessage2InSbasMessage0);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetTransmitMessage2InSbasMessage0);


    SetTransmitMessage2InSbasMessage0::SetTransmitMessage2InSbasMessage0()
      : CommandBase(CmdName, TargetId)
    {}

    SetTransmitMessage2InSbasMessage0::SetTransmitMessage2InSbasMessage0(bool transmitMessage2)
      : CommandBase(CmdName, TargetId)
    {

      setTransmitMessage2(transmitMessage2);
    }

    SetTransmitMessage2InSbasMessage0Ptr SetTransmitMessage2InSbasMessage0::create(bool transmitMessage2)
    {
      return std::make_shared<SetTransmitMessage2InSbasMessage0>(transmitMessage2);
    }

    SetTransmitMessage2InSbasMessage0Ptr SetTransmitMessage2InSbasMessage0::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetTransmitMessage2InSbasMessage0>(ptr);
    }

    bool SetTransmitMessage2InSbasMessage0::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["TransmitMessage2"])
        ;

    }

    std::string SetTransmitMessage2InSbasMessage0::documentation() const { return Documentation; }

    const std::vector<std::string>& SetTransmitMessage2InSbasMessage0::fieldNames() const 
    { 
      static const std::vector<std::string> names {"TransmitMessage2"}; 
      return names; 
    }


    int SetTransmitMessage2InSbasMessage0::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    bool SetTransmitMessage2InSbasMessage0::transmitMessage2() const
    {
      return parse_json<bool>::parse(m_values["TransmitMessage2"]);
    }

    void SetTransmitMessage2InSbasMessage0::setTransmitMessage2(bool transmitMessage2)
    {
      m_values.AddMember("TransmitMessage2", parse_json<bool>::format(transmitMessage2, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
