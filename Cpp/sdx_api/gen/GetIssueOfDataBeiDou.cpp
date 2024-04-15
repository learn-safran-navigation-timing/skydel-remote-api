
#include "GetIssueOfDataBeiDou.h"

#include "command_factory.h"
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
    const char* const GetIssueOfDataBeiDou::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetIssueOfDataBeiDou);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIssueOfDataBeiDou);


    GetIssueOfDataBeiDou::GetIssueOfDataBeiDou()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetIssueOfDataBeiDou::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetIssueOfDataBeiDou::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
