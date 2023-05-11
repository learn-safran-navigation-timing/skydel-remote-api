
#include "gen/GetSbasDeltaUdreiOutsideOfRegions.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasDeltaUdreiOutsideOfRegions
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasDeltaUdreiOutsideOfRegions::CmdName = "GetSbasDeltaUdreiOutsideOfRegions";
    const char* const GetSbasDeltaUdreiOutsideOfRegions::Documentation = "Get SBAS delta UDREI outside all the defined regions for this service provider.";

    REGISTER_COMMAND_FACTORY(GetSbasDeltaUdreiOutsideOfRegions);


    GetSbasDeltaUdreiOutsideOfRegions::GetSbasDeltaUdreiOutsideOfRegions()
      : CommandBase(CmdName)
    {}

    GetSbasDeltaUdreiOutsideOfRegions::GetSbasDeltaUdreiOutsideOfRegions(const std::string& serviceProvider)
      : CommandBase(CmdName)
    {

      setServiceProvider(serviceProvider);
    }

    GetSbasDeltaUdreiOutsideOfRegionsPtr GetSbasDeltaUdreiOutsideOfRegions::create(const std::string& serviceProvider)
    {
      return std::make_shared<GetSbasDeltaUdreiOutsideOfRegions>(serviceProvider);
    }

    GetSbasDeltaUdreiOutsideOfRegionsPtr GetSbasDeltaUdreiOutsideOfRegions::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasDeltaUdreiOutsideOfRegions>(ptr);
    }

    bool GetSbasDeltaUdreiOutsideOfRegions::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string GetSbasDeltaUdreiOutsideOfRegions::documentation() const { return Documentation; }


    int GetSbasDeltaUdreiOutsideOfRegions::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetSbasDeltaUdreiOutsideOfRegions::serviceProvider() const
    {
      return parse_json<std::string>::parse(m_values["ServiceProvider"]);
    }

    void GetSbasDeltaUdreiOutsideOfRegions::setServiceProvider(const std::string& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
