
#include "GetConfigBroadcastFilter.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetConfigBroadcastFilter
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetConfigBroadcastFilter::CmdName = "GetConfigBroadcastFilter";
    const char* const GetConfigBroadcastFilter::Documentation = "Get the filter for configuration broadcast.";
    const char* const GetConfigBroadcastFilter::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetConfigBroadcastFilter);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetConfigBroadcastFilter);


    GetConfigBroadcastFilter::GetConfigBroadcastFilter()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetConfigBroadcastFilterPtr GetConfigBroadcastFilter::create()
    {
      return std::make_shared<GetConfigBroadcastFilter>();
    }

    GetConfigBroadcastFilterPtr GetConfigBroadcastFilter::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetConfigBroadcastFilter>(ptr);
    }

    bool GetConfigBroadcastFilter::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetConfigBroadcastFilter::documentation() const { return Documentation; }

    const std::vector<std::string>& GetConfigBroadcastFilter::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetConfigBroadcastFilter::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
