
#include "gen/GetConfigBroadcastFilterResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetConfigBroadcastFilterResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetConfigBroadcastFilterResult::CmdName = "GetConfigBroadcastFilterResult";
    const char* const GetConfigBroadcastFilterResult::Documentation = "Result of GetConfigBroadcastFilter.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetConfigBroadcastFilterResult);


    GetConfigBroadcastFilterResult::GetConfigBroadcastFilterResult()
      : CommandResult(CmdName)
    {}

    GetConfigBroadcastFilterResult::GetConfigBroadcastFilterResult(const std::vector<Sdx::ConfigFilter>& filter)
      : CommandResult(CmdName)
    {

      setFilter(filter);
    }

    GetConfigBroadcastFilterResult::GetConfigBroadcastFilterResult(CommandBasePtr relatedCommand, const std::vector<Sdx::ConfigFilter>& filter)
      : CommandResult(CmdName, relatedCommand)
    {

      setFilter(filter);
    }


    GetConfigBroadcastFilterResultPtr GetConfigBroadcastFilterResult::create(const std::vector<Sdx::ConfigFilter>& filter)
    {
      return std::make_shared<GetConfigBroadcastFilterResult>(filter);
    }

    GetConfigBroadcastFilterResultPtr GetConfigBroadcastFilterResult::create(CommandBasePtr relatedCommand, const std::vector<Sdx::ConfigFilter>& filter)
    {
      return std::make_shared<GetConfigBroadcastFilterResult>(relatedCommand, filter);
    }

    GetConfigBroadcastFilterResultPtr GetConfigBroadcastFilterResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetConfigBroadcastFilterResult>(ptr);
    }

    bool GetConfigBroadcastFilterResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<Sdx::ConfigFilter>>::is_valid(m_values["Filter"])
        ;

    }

    std::string GetConfigBroadcastFilterResult::documentation() const { return Documentation; }


    std::vector<Sdx::ConfigFilter> GetConfigBroadcastFilterResult::filter() const
    {
      return parse_json<std::vector<Sdx::ConfigFilter>>::parse(m_values["Filter"]);
    }

    void GetConfigBroadcastFilterResult::setFilter(const std::vector<Sdx::ConfigFilter>& filter)
    {
      m_values.AddMember("Filter", parse_json<std::vector<Sdx::ConfigFilter>>::format(filter, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
