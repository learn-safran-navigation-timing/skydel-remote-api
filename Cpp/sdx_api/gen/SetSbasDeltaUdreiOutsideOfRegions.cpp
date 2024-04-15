
#include "SetSbasDeltaUdreiOutsideOfRegions.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSbasDeltaUdreiOutsideOfRegions
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSbasDeltaUdreiOutsideOfRegions::CmdName = "SetSbasDeltaUdreiOutsideOfRegions";
    const char* const SetSbasDeltaUdreiOutsideOfRegions::Documentation = "Set SBAS delta UDREI outside all the defined regions for this service provider.\n"
      "\n"
      "Name            Type   Description\n"
      "--------------- ------ ----------------------------------------------------------------------------------\n"
      "ServiceProvider string Service providers, accepts \"WAAS\", \"EGNOS\", \"MSAS\", \"GAGAN\" and \"SDCM\".\n"
      "DeltaUdrei      int    Delta UDREI applicable outside all the defined regions. Accepted range is [0..15].";
    const char* const SetSbasDeltaUdreiOutsideOfRegions::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSbasDeltaUdreiOutsideOfRegions);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSbasDeltaUdreiOutsideOfRegions);


    SetSbasDeltaUdreiOutsideOfRegions::SetSbasDeltaUdreiOutsideOfRegions()
      : CommandBase(CmdName, TargetId)
    {}

    SetSbasDeltaUdreiOutsideOfRegions::SetSbasDeltaUdreiOutsideOfRegions(const std::string& serviceProvider, int deltaUdrei)
      : CommandBase(CmdName, TargetId)
    {

      setServiceProvider(serviceProvider);
      setDeltaUdrei(deltaUdrei);
    }

    SetSbasDeltaUdreiOutsideOfRegionsPtr SetSbasDeltaUdreiOutsideOfRegions::create(const std::string& serviceProvider, int deltaUdrei)
    {
      return std::make_shared<SetSbasDeltaUdreiOutsideOfRegions>(serviceProvider, deltaUdrei);
    }

    SetSbasDeltaUdreiOutsideOfRegionsPtr SetSbasDeltaUdreiOutsideOfRegions::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSbasDeltaUdreiOutsideOfRegions>(ptr);
    }

    bool SetSbasDeltaUdreiOutsideOfRegions::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
          && parse_json<int>::is_valid(m_values["DeltaUdrei"])
        ;

    }

    std::string SetSbasDeltaUdreiOutsideOfRegions::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSbasDeltaUdreiOutsideOfRegions::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ServiceProvider", "DeltaUdrei"}; 
      return names; 
    }


    int SetSbasDeltaUdreiOutsideOfRegions::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetSbasDeltaUdreiOutsideOfRegions::serviceProvider() const
    {
      return parse_json<std::string>::parse(m_values["ServiceProvider"]);
    }

    void SetSbasDeltaUdreiOutsideOfRegions::setServiceProvider(const std::string& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetSbasDeltaUdreiOutsideOfRegions::deltaUdrei() const
    {
      return parse_json<int>::parse(m_values["DeltaUdrei"]);
    }

    void SetSbasDeltaUdreiOutsideOfRegions::setDeltaUdrei(int deltaUdrei)
    {
      m_values.AddMember("DeltaUdrei", parse_json<int>::format(deltaUdrei, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
