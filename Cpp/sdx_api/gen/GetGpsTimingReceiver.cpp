
#include "GetGpsTimingReceiver.h"

#include "command_factory.h"
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
    const char* const GetGpsTimingReceiver::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGpsTimingReceiver);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGpsTimingReceiver);


    GetGpsTimingReceiver::GetGpsTimingReceiver()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetGpsTimingReceiver::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetGpsTimingReceiver::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
