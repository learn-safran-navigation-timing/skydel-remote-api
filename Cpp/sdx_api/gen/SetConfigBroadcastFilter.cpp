
#include "SetConfigBroadcastFilter.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetConfigBroadcastFilter
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetConfigBroadcastFilter::CmdName = "SetConfigBroadcastFilter";
    const char* const SetConfigBroadcastFilter::Documentation = "Set the filter for configuration broadcast.\n"
      "\n"
      "Name   Type               Description\n"
      "------ ------------------ ------------------------------------------------------------------------------\n"
      "Filter array ConfigFilter Every configuration section set in this array will be excluded from broadcast.";
    const char* const SetConfigBroadcastFilter::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetConfigBroadcastFilter);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetConfigBroadcastFilter);


    SetConfigBroadcastFilter::SetConfigBroadcastFilter()
      : CommandBase(CmdName, TargetId)
    {}

    SetConfigBroadcastFilter::SetConfigBroadcastFilter(const std::vector<Sdx::ConfigFilter>& filter)
      : CommandBase(CmdName, TargetId)
    {

      setFilter(filter);
    }

    SetConfigBroadcastFilterPtr SetConfigBroadcastFilter::create(const std::vector<Sdx::ConfigFilter>& filter)
    {
      return std::make_shared<SetConfigBroadcastFilter>(filter);
    }

    SetConfigBroadcastFilterPtr SetConfigBroadcastFilter::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetConfigBroadcastFilter>(ptr);
    }

    bool SetConfigBroadcastFilter::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<Sdx::ConfigFilter>>::is_valid(m_values["Filter"])
        ;

    }

    std::string SetConfigBroadcastFilter::documentation() const { return Documentation; }

    const std::vector<std::string>& SetConfigBroadcastFilter::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Filter"}; 
      return names; 
    }


    int SetConfigBroadcastFilter::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::vector<Sdx::ConfigFilter> SetConfigBroadcastFilter::filter() const
    {
      return parse_json<std::vector<Sdx::ConfigFilter>>::parse(m_values["Filter"]);
    }

    void SetConfigBroadcastFilter::setFilter(const std::vector<Sdx::ConfigFilter>& filter)
    {
      m_values.AddMember("Filter", parse_json<std::vector<Sdx::ConfigFilter>>::format(filter, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
