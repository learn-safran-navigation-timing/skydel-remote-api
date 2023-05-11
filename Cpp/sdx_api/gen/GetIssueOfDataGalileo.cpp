
#include "gen/GetIssueOfDataGalileo.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIssueOfDataGalileo
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIssueOfDataGalileo::CmdName = "GetIssueOfDataGalileo";
    const char* const GetIssueOfDataGalileo::Documentation = "Get Galileo Issue of data, Navigation (IODNAV) and Issue of data, Almanac (IODA)";

    REGISTER_COMMAND_FACTORY(GetIssueOfDataGalileo);


    GetIssueOfDataGalileo::GetIssueOfDataGalileo()
      : CommandBase(CmdName)
    {

    }

    GetIssueOfDataGalileoPtr GetIssueOfDataGalileo::create()
    {
      return std::make_shared<GetIssueOfDataGalileo>();
    }

    GetIssueOfDataGalileoPtr GetIssueOfDataGalileo::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIssueOfDataGalileo>(ptr);
    }

    bool GetIssueOfDataGalileo::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetIssueOfDataGalileo::documentation() const { return Documentation; }


    int GetIssueOfDataGalileo::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
