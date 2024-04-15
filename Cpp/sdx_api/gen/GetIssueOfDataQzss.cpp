
#include "GetIssueOfDataQzss.h"

#include "command_factory.h"
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
    const char* const GetIssueOfDataQzss::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetIssueOfDataQzss);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIssueOfDataQzss);


    GetIssueOfDataQzss::GetIssueOfDataQzss()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetIssueOfDataQzss::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetIssueOfDataQzss::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
