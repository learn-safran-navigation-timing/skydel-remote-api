
#include "gen/GetVersion.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVersion
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVersion::CmdName = "GetVersion";
    const char* const GetVersion::Documentation = "Get Skydel version.";

    REGISTER_COMMAND_FACTORY(GetVersion);


    GetVersion::GetVersion()
      : CommandBase(CmdName)
    {

    }

    GetVersionPtr GetVersion::create()
    {
      return std::make_shared<GetVersion>();
    }

    GetVersionPtr GetVersion::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVersion>(ptr);
    }

    bool GetVersion::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetVersion::documentation() const { return Documentation; }


    int GetVersion::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
