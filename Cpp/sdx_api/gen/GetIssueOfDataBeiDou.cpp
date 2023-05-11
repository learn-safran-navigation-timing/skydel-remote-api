
#include "gen/GetIssueOfDataBeiDou.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIssueOfDataBeiDou
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIssueOfDataBeiDou::CmdName = "GetIssueOfDataBeiDou";
    const char* const GetIssueOfDataBeiDou::Documentation = "Get BeiDou Issue of data, Ephemeris (IODE) and Issue of data, Clock (IODC)";

    REGISTER_COMMAND_FACTORY(GetIssueOfDataBeiDou);


    GetIssueOfDataBeiDou::GetIssueOfDataBeiDou()
      : CommandBase(CmdName)
    {

    }

    GetIssueOfDataBeiDouPtr GetIssueOfDataBeiDou::create()
    {
      return std::make_shared<GetIssueOfDataBeiDou>();
    }

    GetIssueOfDataBeiDouPtr GetIssueOfDataBeiDou::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIssueOfDataBeiDou>(ptr);
    }

    bool GetIssueOfDataBeiDou::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetIssueOfDataBeiDou::documentation() const { return Documentation; }


    int GetIssueOfDataBeiDou::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
