
#include "GetHilPort.h"

#include "command_factory.h"
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
    const char* const GetHilPort::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetHilPort);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetHilPort);


    GetHilPort::GetHilPort()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetHilPort::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetHilPort::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
