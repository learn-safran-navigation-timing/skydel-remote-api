
#include "gen/GetComputerSystemTimeSinceEpochAtPps0.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetComputerSystemTimeSinceEpochAtPps0
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetComputerSystemTimeSinceEpochAtPps0::CmdName = "GetComputerSystemTimeSinceEpochAtPps0";
    const char* const GetComputerSystemTimeSinceEpochAtPps0::Documentation = "Get  the computer system time since epoch at PPS0, for the computer running this Skydel instance.\nUse this command after StartPPS.";

    REGISTER_COMMAND_FACTORY(GetComputerSystemTimeSinceEpochAtPps0);


    GetComputerSystemTimeSinceEpochAtPps0::GetComputerSystemTimeSinceEpochAtPps0()
      : CommandBase(CmdName)
    {

    }

    GetComputerSystemTimeSinceEpochAtPps0Ptr GetComputerSystemTimeSinceEpochAtPps0::create()
    {
      return std::make_shared<GetComputerSystemTimeSinceEpochAtPps0>();
    }

    GetComputerSystemTimeSinceEpochAtPps0Ptr GetComputerSystemTimeSinceEpochAtPps0::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetComputerSystemTimeSinceEpochAtPps0>(ptr);
    }

    bool GetComputerSystemTimeSinceEpochAtPps0::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetComputerSystemTimeSinceEpochAtPps0::documentation() const { return Documentation; }


    int GetComputerSystemTimeSinceEpochAtPps0::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }

  }
}
