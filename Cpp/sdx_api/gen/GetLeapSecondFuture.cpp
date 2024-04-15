
#include "GetLeapSecondFuture.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetLeapSecondFuture
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetLeapSecondFuture::CmdName = "GetLeapSecondFuture";
    const char* const GetLeapSecondFuture::Documentation = "Get the next leap second event";
    const char* const GetLeapSecondFuture::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetLeapSecondFuture);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetLeapSecondFuture);


    GetLeapSecondFuture::GetLeapSecondFuture()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetLeapSecondFuturePtr GetLeapSecondFuture::create()
    {
      return std::make_shared<GetLeapSecondFuture>();
    }

    GetLeapSecondFuturePtr GetLeapSecondFuture::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetLeapSecondFuture>(ptr);
    }

    bool GetLeapSecondFuture::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetLeapSecondFuture::documentation() const { return Documentation; }

    const std::vector<std::string>& GetLeapSecondFuture::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetLeapSecondFuture::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
