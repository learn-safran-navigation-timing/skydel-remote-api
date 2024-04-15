
#include "GetOsnmaMacFunction.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetOsnmaMacFunction
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetOsnmaMacFunction::CmdName = "GetOsnmaMacFunction";
    const char* const GetOsnmaMacFunction::Documentation = "Get OSNMA MAC function.";
    const char* const GetOsnmaMacFunction::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetOsnmaMacFunction);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetOsnmaMacFunction);


    GetOsnmaMacFunction::GetOsnmaMacFunction()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetOsnmaMacFunctionPtr GetOsnmaMacFunction::create()
    {
      return std::make_shared<GetOsnmaMacFunction>();
    }

    GetOsnmaMacFunctionPtr GetOsnmaMacFunction::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetOsnmaMacFunction>(ptr);
    }

    bool GetOsnmaMacFunction::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetOsnmaMacFunction::documentation() const { return Documentation; }

    const std::vector<std::string>& GetOsnmaMacFunction::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetOsnmaMacFunction::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
