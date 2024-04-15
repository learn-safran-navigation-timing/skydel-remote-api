
#include "GetSbasDeltaUdreiOutsideOfRegions.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasDeltaUdreiOutsideOfRegions
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasDeltaUdreiOutsideOfRegions::CmdName = "GetSbasDeltaUdreiOutsideOfRegions";
    const char* const GetSbasDeltaUdreiOutsideOfRegions::Documentation = "Get SBAS delta UDREI outside all the defined regions for this service provider.\n"
      "\n"
      "Name            Type   Description\n"
      "--------------- ------ -----------------------------------------------------------------------\n"
      "ServiceProvider string Service providers, accepts \"WAAS\", \"EGNOS\", \"MSAS\", \"GAGAN\" and \"SDCM\".";
    const char* const GetSbasDeltaUdreiOutsideOfRegions::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSbasDeltaUdreiOutsideOfRegions);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSbasDeltaUdreiOutsideOfRegions);


    GetSbasDeltaUdreiOutsideOfRegions::GetSbasDeltaUdreiOutsideOfRegions()
      : CommandBase(CmdName, TargetId)
    {}

    GetSbasDeltaUdreiOutsideOfRegions::GetSbasDeltaUdreiOutsideOfRegions(const std::string& serviceProvider)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetSbasDeltaUdreiOutsideOfRegions::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ServiceProvider"}; 
      return names; 
    }


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
