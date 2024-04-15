
#include "GetComputerSystemTimeSinceEpochAtPps0.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetComputerSystemTimeSinceEpochAtPps0
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetComputerSystemTimeSinceEpochAtPps0::CmdName = "GetComputerSystemTimeSinceEpochAtPps0";
    const char* const GetComputerSystemTimeSinceEpochAtPps0::Documentation = "Get  the computer system time since epoch at PPS0, for the computer running this Skydel instance.\n"
      "Use this command after StartPPS.";
    const char* const GetComputerSystemTimeSinceEpochAtPps0::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetComputerSystemTimeSinceEpochAtPps0);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetComputerSystemTimeSinceEpochAtPps0);


    GetComputerSystemTimeSinceEpochAtPps0::GetComputerSystemTimeSinceEpochAtPps0()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetComputerSystemTimeSinceEpochAtPps0::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetComputerSystemTimeSinceEpochAtPps0::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }

  }
}
