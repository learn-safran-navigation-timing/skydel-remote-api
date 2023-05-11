
#include "gen/GetIssueOfDataQzss.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIssueOfDataQzss
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIssueOfDataQzss::CmdName = "GetIssueOfDataQzss";
    const char* const GetIssueOfDataQzss::Documentation = "Get QZSS Issue of data, Ephemeris (IODE) and Issue of data, Clock (IODC)";

    REGISTER_COMMAND_FACTORY(GetIssueOfDataQzss);


    GetIssueOfDataQzss::GetIssueOfDataQzss()
      : CommandBase(CmdName)
    {

    }

    GetIssueOfDataQzssPtr GetIssueOfDataQzss::create()
    {
      return std::make_shared<GetIssueOfDataQzss>();
    }

    GetIssueOfDataQzssPtr GetIssueOfDataQzss::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIssueOfDataQzss>(ptr);
    }

    bool GetIssueOfDataQzss::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetIssueOfDataQzss::documentation() const { return Documentation; }


    int GetIssueOfDataQzss::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
