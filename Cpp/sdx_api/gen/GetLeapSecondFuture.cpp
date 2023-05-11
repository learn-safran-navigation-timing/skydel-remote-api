
#include "gen/GetLeapSecondFuture.h"

#include "command_factory.h"
#include "command_result_factory.h"
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

    REGISTER_COMMAND_FACTORY(GetLeapSecondFuture);


    GetLeapSecondFuture::GetLeapSecondFuture()
      : CommandBase(CmdName)
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


    int GetLeapSecondFuture::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
