
#include "gen/GetHilPort.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetHilPort
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetHilPort::CmdName = "GetHilPort";
    const char* const GetHilPort::Documentation = "Get Hardware in the loop trajectory server port.";

    REGISTER_COMMAND_FACTORY(GetHilPort);


    GetHilPort::GetHilPort()
      : CommandBase(CmdName)
    {

    }

    GetHilPortPtr GetHilPort::create()
    {
      return std::make_shared<GetHilPort>();
    }

    GetHilPortPtr GetHilPort::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetHilPort>(ptr);
    }

    bool GetHilPort::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetHilPort::documentation() const { return Documentation; }


    int GetHilPort::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
