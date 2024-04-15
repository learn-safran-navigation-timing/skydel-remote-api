
#include "RemoveSbasServiceMessageRegionGroup.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveSbasServiceMessageRegionGroup
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveSbasServiceMessageRegionGroup::CmdName = "RemoveSbasServiceMessageRegionGroup";
    const char* const RemoveSbasServiceMessageRegionGroup::Documentation = "Removes a SBAS service message region group for the service provider.\n"
      "\n"
      "Name            Type   Description\n"
      "--------------- ------ -----------------------------------------------------------------------\n"
      "ServiceProvider string Service providers, accepts \"WAAS\", \"EGNOS\", \"MSAS\", \"GAGAN\" and \"SDCM\".\n"
      "Id              string Unique identifier of the SBAS service message region group to remove.";
    const char* const RemoveSbasServiceMessageRegionGroup::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RemoveSbasServiceMessageRegionGroup);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RemoveSbasServiceMessageRegionGroup);


    RemoveSbasServiceMessageRegionGroup::RemoveSbasServiceMessageRegionGroup()
      : CommandBase(CmdName, TargetId)
    {}

    RemoveSbasServiceMessageRegionGroup::RemoveSbasServiceMessageRegionGroup(const std::string& serviceProvider, const std::string& id)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& RemoveSbasServiceMessageRegionGroup::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ServiceProvider", "Id"}; 
      return names; 
    }


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
