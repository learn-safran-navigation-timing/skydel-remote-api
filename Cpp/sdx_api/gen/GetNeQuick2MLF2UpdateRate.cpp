
#include "GetNeQuick2MLF2UpdateRate.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNeQuick2MLF2UpdateRate
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNeQuick2MLF2UpdateRate::CmdName = "GetNeQuick2MLF2UpdateRate";
    const char* const GetNeQuick2MLF2UpdateRate::Documentation = "Get the update rate of the NeQuick2-MLF2 model.";
    const char* const GetNeQuick2MLF2UpdateRate::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetNeQuick2MLF2UpdateRate);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetNeQuick2MLF2UpdateRate);


    GetNeQuick2MLF2UpdateRate::GetNeQuick2MLF2UpdateRate()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetNeQuick2MLF2UpdateRatePtr GetNeQuick2MLF2UpdateRate::create()
    {
      return std::make_shared<GetNeQuick2MLF2UpdateRate>();
    }

    GetNeQuick2MLF2UpdateRatePtr GetNeQuick2MLF2UpdateRate::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNeQuick2MLF2UpdateRate>(ptr);
    }

    bool GetNeQuick2MLF2UpdateRate::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetNeQuick2MLF2UpdateRate::documentation() const { return Documentation; }

    const std::vector<std::string>& GetNeQuick2MLF2UpdateRate::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetNeQuick2MLF2UpdateRate::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
