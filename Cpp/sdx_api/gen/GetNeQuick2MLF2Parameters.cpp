
#include "GetNeQuick2MLF2Parameters.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNeQuick2MLF2Parameters
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNeQuick2MLF2Parameters::CmdName = "GetNeQuick2MLF2Parameters";
    const char* const GetNeQuick2MLF2Parameters::Documentation = "Get the parameters of the NeQuick2-MLF2 model.";
    const char* const GetNeQuick2MLF2Parameters::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetNeQuick2MLF2Parameters);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetNeQuick2MLF2Parameters);


    GetNeQuick2MLF2Parameters::GetNeQuick2MLF2Parameters()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetNeQuick2MLF2ParametersPtr GetNeQuick2MLF2Parameters::create()
    {
      return std::make_shared<GetNeQuick2MLF2Parameters>();
    }

    GetNeQuick2MLF2ParametersPtr GetNeQuick2MLF2Parameters::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNeQuick2MLF2Parameters>(ptr);
    }

    bool GetNeQuick2MLF2Parameters::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetNeQuick2MLF2Parameters::documentation() const { return Documentation; }

    const std::vector<std::string>& GetNeQuick2MLF2Parameters::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetNeQuick2MLF2Parameters::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
