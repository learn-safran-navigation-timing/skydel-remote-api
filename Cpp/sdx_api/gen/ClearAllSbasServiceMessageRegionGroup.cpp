
#include "gen/ClearAllSbasServiceMessageRegionGroup.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearAllSbasServiceMessageRegionGroup
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearAllSbasServiceMessageRegionGroup::CmdName = "ClearAllSbasServiceMessageRegionGroup";
    const char* const ClearAllSbasServiceMessageRegionGroup::Documentation = "Clears all SBAS service message region group for this service provider.";

    REGISTER_COMMAND_FACTORY(ClearAllSbasServiceMessageRegionGroup);


    ClearAllSbasServiceMessageRegionGroup::ClearAllSbasServiceMessageRegionGroup()
      : CommandBase(CmdName)
    {}

    ClearAllSbasServiceMessageRegionGroup::ClearAllSbasServiceMessageRegionGroup(const std::string& serviceProvider)
      : CommandBase(CmdName)
    {

      setServiceProvider(serviceProvider);
    }

    ClearAllSbasServiceMessageRegionGroupPtr ClearAllSbasServiceMessageRegionGroup::create(const std::string& serviceProvider)
    {
      return std::make_shared<ClearAllSbasServiceMessageRegionGroup>(serviceProvider);
    }

    ClearAllSbasServiceMessageRegionGroupPtr ClearAllSbasServiceMessageRegionGroup::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ClearAllSbasServiceMessageRegionGroup>(ptr);
    }

    bool ClearAllSbasServiceMessageRegionGroup::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string ClearAllSbasServiceMessageRegionGroup::documentation() const { return Documentation; }


    int ClearAllSbasServiceMessageRegionGroup::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string ClearAllSbasServiceMessageRegionGroup::serviceProvider() const
    {
      return parse_json<std::string>::parse(m_values["ServiceProvider"]);
    }

    void ClearAllSbasServiceMessageRegionGroup::setServiceProvider(const std::string& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
