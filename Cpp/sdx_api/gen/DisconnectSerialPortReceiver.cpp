
#include "gen/DisconnectSerialPortReceiver.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of DisconnectSerialPortReceiver
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const DisconnectSerialPortReceiver::CmdName = "DisconnectSerialPortReceiver";
    const char* const DisconnectSerialPortReceiver::Documentation = "Disconnects the connected receiver. Does nothing if no receiver is connected.";

    REGISTER_COMMAND_FACTORY(DisconnectSerialPortReceiver);


    DisconnectSerialPortReceiver::DisconnectSerialPortReceiver()
      : CommandBase(CmdName)
    {

    }

    DisconnectSerialPortReceiverPtr DisconnectSerialPortReceiver::create()
    {
      return std::make_shared<DisconnectSerialPortReceiver>();
    }

    DisconnectSerialPortReceiverPtr DisconnectSerialPortReceiver::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<DisconnectSerialPortReceiver>(ptr);
    }

    bool DisconnectSerialPortReceiver::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string DisconnectSerialPortReceiver::documentation() const { return Documentation; }


    int DisconnectSerialPortReceiver::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }

  }
}
