
#include "gen/GetGpsTimingReceiver.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsTimingReceiver
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsTimingReceiver::CmdName = "GetGpsTimingReceiver";
    const char* const GetGpsTimingReceiver::Documentation = "Get the connection parameters to the GPS Receiver from which the simulator will get the simulation start time.";

    REGISTER_COMMAND_FACTORY(GetGpsTimingReceiver);


    GetGpsTimingReceiver::GetGpsTimingReceiver()
      : CommandBase(CmdName)
    {

    }

    GetGpsTimingReceiverPtr GetGpsTimingReceiver::create()
    {
      return std::make_shared<GetGpsTimingReceiver>();
    }

    GetGpsTimingReceiverPtr GetGpsTimingReceiver::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsTimingReceiver>(ptr);
    }

    bool GetGpsTimingReceiver::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetGpsTimingReceiver::documentation() const { return Documentation; }


    int GetGpsTimingReceiver::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
