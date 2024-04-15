
#include "GetOsnmaTeslaHashFunction.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetOsnmaTeslaHashFunction
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetOsnmaTeslaHashFunction::CmdName = "GetOsnmaTeslaHashFunction";
    const char* const GetOsnmaTeslaHashFunction::Documentation = "Get OSNMA TESLA hash function.";
    const char* const GetOsnmaTeslaHashFunction::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetOsnmaTeslaHashFunction);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetOsnmaTeslaHashFunction);


    GetOsnmaTeslaHashFunction::GetOsnmaTeslaHashFunction()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetOsnmaTeslaHashFunctionPtr GetOsnmaTeslaHashFunction::create()
    {
      return std::make_shared<GetOsnmaTeslaHashFunction>();
    }

    GetOsnmaTeslaHashFunctionPtr GetOsnmaTeslaHashFunction::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetOsnmaTeslaHashFunction>(ptr);
    }

    bool GetOsnmaTeslaHashFunction::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetOsnmaTeslaHashFunction::documentation() const { return Documentation; }

    const std::vector<std::string>& GetOsnmaTeslaHashFunction::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetOsnmaTeslaHashFunction::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
