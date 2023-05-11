
#include "gen/RemoveSbasServiceMessageRegionGroup.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveSbasServiceMessageRegionGroup
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveSbasServiceMessageRegionGroup::CmdName = "RemoveSbasServiceMessageRegionGroup";
    const char* const RemoveSbasServiceMessageRegionGroup::Documentation = "Removes a SBAS service message region group for the service provider.";

    REGISTER_COMMAND_FACTORY(RemoveSbasServiceMessageRegionGroup);


    RemoveSbasServiceMessageRegionGroup::RemoveSbasServiceMessageRegionGroup()
      : CommandBase(CmdName)
    {}

    RemoveSbasServiceMessageRegionGroup::RemoveSbasServiceMessageRegionGroup(const std::string& serviceProvider, const std::string& id)
      : CommandBase(CmdName)
    {

      setServiceProvider(serviceProvider);
      setId(id);
    }

    RemoveSbasServiceMessageRegionGroupPtr RemoveSbasServiceMessageRegionGroup::create(const std::string& serviceProvider, const std::string& id)
    {
      return std::make_shared<RemoveSbasServiceMessageRegionGroup>(serviceProvider, id);
    }

    RemoveSbasServiceMessageRegionGroupPtr RemoveSbasServiceMessageRegionGroup::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveSbasServiceMessageRegionGroup>(ptr);
    }

    bool RemoveSbasServiceMessageRegionGroup::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemoveSbasServiceMessageRegionGroup::documentation() const { return Documentation; }


    int RemoveSbasServiceMessageRegionGroup::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveSbasServiceMessageRegionGroup::serviceProvider() const
    {
      return parse_json<std::string>::parse(m_values["ServiceProvider"]);
    }

    void RemoveSbasServiceMessageRegionGroup::setServiceProvider(const std::string& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string RemoveSbasServiceMessageRegionGroup::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemoveSbasServiceMessageRegionGroup::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
