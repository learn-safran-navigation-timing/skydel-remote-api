
#include "gen/GetSbasServiceMessageRegionGroup.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasServiceMessageRegionGroup
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasServiceMessageRegionGroup::CmdName = "GetSbasServiceMessageRegionGroup";
    const char* const GetSbasServiceMessageRegionGroup::Documentation = "Get infos about the SBAS service message region group at this index.";

    REGISTER_COMMAND_FACTORY(GetSbasServiceMessageRegionGroup);


    GetSbasServiceMessageRegionGroup::GetSbasServiceMessageRegionGroup()
      : CommandBase(CmdName)
    {}

    GetSbasServiceMessageRegionGroup::GetSbasServiceMessageRegionGroup(const std::string& serviceProvider, const std::string& id)
      : CommandBase(CmdName)
    {

      setServiceProvider(serviceProvider);
      setId(id);
    }

    GetSbasServiceMessageRegionGroupPtr GetSbasServiceMessageRegionGroup::create(const std::string& serviceProvider, const std::string& id)
    {
      return std::make_shared<GetSbasServiceMessageRegionGroup>(serviceProvider, id);
    }

    GetSbasServiceMessageRegionGroupPtr GetSbasServiceMessageRegionGroup::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasServiceMessageRegionGroup>(ptr);
    }

    bool GetSbasServiceMessageRegionGroup::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetSbasServiceMessageRegionGroup::documentation() const { return Documentation; }


    int GetSbasServiceMessageRegionGroup::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetSbasServiceMessageRegionGroup::serviceProvider() const
    {
      return parse_json<std::string>::parse(m_values["ServiceProvider"]);
    }

    void GetSbasServiceMessageRegionGroup::setServiceProvider(const std::string& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSbasServiceMessageRegionGroup::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetSbasServiceMessageRegionGroup::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
