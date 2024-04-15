
#include "ClearAllSbasServiceMessageRegionGroup.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearAllSbasServiceMessageRegionGroup
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearAllSbasServiceMessageRegionGroup::CmdName = "ClearAllSbasServiceMessageRegionGroup";
    const char* const ClearAllSbasServiceMessageRegionGroup::Documentation = "Clears all SBAS service message region group for this service provider.\n"
      "\n"
      "Name            Type   Description\n"
      "--------------- ------ -----------------------------------------------------------------------\n"
      "ServiceProvider string Service providers, accepts \"WAAS\", \"EGNOS\", \"MSAS\", \"GAGAN\" and \"SDCM\".";
    const char* const ClearAllSbasServiceMessageRegionGroup::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ClearAllSbasServiceMessageRegionGroup);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ClearAllSbasServiceMessageRegionGroup);


    ClearAllSbasServiceMessageRegionGroup::ClearAllSbasServiceMessageRegionGroup()
      : CommandBase(CmdName, TargetId)
    {}

    ClearAllSbasServiceMessageRegionGroup::ClearAllSbasServiceMessageRegionGroup(const std::string& serviceProvider)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& ClearAllSbasServiceMessageRegionGroup::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ServiceProvider"}; 
      return names; 
    }


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
