
#include "GetDOP.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetDOP
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetDOP::CmdName = "GetDOP";
    const char* const GetDOP::Documentation = "Get the current Dilution of Precision (DOP) values as separate measurements.";
    const char* const GetDOP::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetDOP);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetDOP);


    GetDOP::GetDOP()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetDOPPtr GetDOP::create()
    {
      return std::make_shared<GetDOP>();
    }

    GetDOPPtr GetDOP::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetDOP>(ptr);
    }

    bool GetDOP::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetDOP::documentation() const { return Documentation; }

    const std::vector<std::string>& GetDOP::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetDOP::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
