
#include "GetConfigBroadcastFilterResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetConfigBroadcastFilterResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetConfigBroadcastFilterResult::CmdName = "GetConfigBroadcastFilterResult";
    const char* const GetConfigBroadcastFilterResult::Documentation = "Result of GetConfigBroadcastFilter.\n"
      "\n"
      "Name   Type               Description\n"
      "------ ------------------ ------------------------------------------------------------------------------\n"
      "Filter array ConfigFilter Every configuration section set in this array will be excluded from broadcast.";
    const char* const GetConfigBroadcastFilterResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetConfigBroadcastFilterResult);


    GetConfigBroadcastFilterResult::GetConfigBroadcastFilterResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetConfigBroadcastFilterResult::GetConfigBroadcastFilterResult(const std::vector<Sdx::ConfigFilter>& filter)
      : CommandResult(CmdName, TargetId)
    {

      setFilter(filter);
    }

    GetConfigBroadcastFilterResult::GetConfigBroadcastFilterResult(CommandBasePtr relatedCommand, const std::vector<Sdx::ConfigFilter>& filter)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& GetConfigBroadcastFilterResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Filter"}; 
      return names; 
    }


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
