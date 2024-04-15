
#include "GetIssueOfDataNavIC.h"

#include "command_factory.h"
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
    const char* const GetIssueOfDataNavIC::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetIssueOfDataNavIC);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIssueOfDataNavIC);


    GetIssueOfDataNavIC::GetIssueOfDataNavIC()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetIssueOfDataNavIC::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetIssueOfDataNavIC::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
