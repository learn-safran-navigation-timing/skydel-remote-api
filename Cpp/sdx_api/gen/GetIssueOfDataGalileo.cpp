
#include "GetIssueOfDataGalileo.h"

#include "command_factory.h"
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
    const char* const GetIssueOfDataGalileo::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetIssueOfDataGalileo);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIssueOfDataGalileo);


    GetIssueOfDataGalileo::GetIssueOfDataGalileo()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetIssueOfDataGalileo::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetIssueOfDataGalileo::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
