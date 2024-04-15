
#include "GetOsnmaTagSize.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetOsnmaTagSize
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetOsnmaTagSize::CmdName = "GetOsnmaTagSize";
    const char* const GetOsnmaTagSize::Documentation = "Get OSNMA tag size.";
    const char* const GetOsnmaTagSize::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetOsnmaTagSize);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetOsnmaTagSize);


    GetOsnmaTagSize::GetOsnmaTagSize()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetOsnmaTagSizePtr GetOsnmaTagSize::create()
    {
      return std::make_shared<GetOsnmaTagSize>();
    }

    GetOsnmaTagSizePtr GetOsnmaTagSize::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetOsnmaTagSize>(ptr);
    }

    bool GetOsnmaTagSize::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetOsnmaTagSize::documentation() const { return Documentation; }

    const std::vector<std::string>& GetOsnmaTagSize::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetOsnmaTagSize::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
