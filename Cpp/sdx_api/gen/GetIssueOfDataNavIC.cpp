
#include "gen/GetIssueOfDataNavIC.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIssueOfDataNavIC
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIssueOfDataNavIC::CmdName = "GetIssueOfDataNavIC";
    const char* const GetIssueOfDataNavIC::Documentation = "Get NavIC Issue of data, Ephemeris and Clock (IODEC)";

    REGISTER_COMMAND_FACTORY(GetIssueOfDataNavIC);


    GetIssueOfDataNavIC::GetIssueOfDataNavIC()
      : CommandBase(CmdName)
    {

    }

    GetIssueOfDataNavICPtr GetIssueOfDataNavIC::create()
    {
      return std::make_shared<GetIssueOfDataNavIC>();
    }

    GetIssueOfDataNavICPtr GetIssueOfDataNavIC::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIssueOfDataNavIC>(ptr);
    }

    bool GetIssueOfDataNavIC::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetIssueOfDataNavIC::documentation() const { return Documentation; }


    int GetIssueOfDataNavIC::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
