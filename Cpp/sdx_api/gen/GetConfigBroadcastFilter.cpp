
#include "gen/GetConfigBroadcastFilter.h"

#include "command_factory.h"
#include "command_result_factory.h"
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

    REGISTER_COMMAND_FACTORY(GetConfigBroadcastFilter);


    GetConfigBroadcastFilter::GetConfigBroadcastFilter()
      : CommandBase(CmdName)
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


    int GetConfigBroadcastFilter::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
