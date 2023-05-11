
#include "gen/SwapSbasServiceMessageRegionGroup.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SwapSbasServiceMessageRegionGroup
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SwapSbasServiceMessageRegionGroup::CmdName = "SwapSbasServiceMessageRegionGroup";
    const char* const SwapSbasServiceMessageRegionGroup::Documentation = "Swaps 2 SBAS service message region group.";

    REGISTER_COMMAND_FACTORY(SwapSbasServiceMessageRegionGroup);


    SwapSbasServiceMessageRegionGroup::SwapSbasServiceMessageRegionGroup()
      : CommandBase(CmdName)
    {}

    SwapSbasServiceMessageRegionGroup::SwapSbasServiceMessageRegionGroup(const std::string& serviceProvider, const std::string& firstId, const std::string& secondId)
      : CommandBase(CmdName)
    {

      setServiceProvider(serviceProvider);
      setFirstId(firstId);
      setSecondId(secondId);
    }

    SwapSbasServiceMessageRegionGroupPtr SwapSbasServiceMessageRegionGroup::create(const std::string& serviceProvider, const std::string& firstId, const std::string& secondId)
    {
      return std::make_shared<SwapSbasServiceMessageRegionGroup>(serviceProvider, firstId, secondId);
    }

    SwapSbasServiceMessageRegionGroupPtr SwapSbasServiceMessageRegionGroup::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SwapSbasServiceMessageRegionGroup>(ptr);
    }

    bool SwapSbasServiceMessageRegionGroup::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
          && parse_json<std::string>::is_valid(m_values["FirstId"])
          && parse_json<std::string>::is_valid(m_values["SecondId"])
        ;

    }

    std::string SwapSbasServiceMessageRegionGroup::documentation() const { return Documentation; }


    int SwapSbasServiceMessageRegionGroup::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SwapSbasServiceMessageRegionGroup::serviceProvider() const
    {
      return parse_json<std::string>::parse(m_values["ServiceProvider"]);
    }

    void SwapSbasServiceMessageRegionGroup::setServiceProvider(const std::string& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SwapSbasServiceMessageRegionGroup::firstId() const
    {
      return parse_json<std::string>::parse(m_values["FirstId"]);
    }

    void SwapSbasServiceMessageRegionGroup::setFirstId(const std::string& firstId)
    {
      m_values.AddMember("FirstId", parse_json<std::string>::format(firstId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SwapSbasServiceMessageRegionGroup::secondId() const
    {
      return parse_json<std::string>::parse(m_values["SecondId"]);
    }

    void SwapSbasServiceMessageRegionGroup::setSecondId(const std::string& secondId)
    {
      m_values.AddMember("SecondId", parse_json<std::string>::format(secondId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
