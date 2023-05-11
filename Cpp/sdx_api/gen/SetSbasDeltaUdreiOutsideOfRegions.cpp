
#include "gen/SetSbasDeltaUdreiOutsideOfRegions.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSbasDeltaUdreiOutsideOfRegions
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSbasDeltaUdreiOutsideOfRegions::CmdName = "SetSbasDeltaUdreiOutsideOfRegions";
    const char* const SetSbasDeltaUdreiOutsideOfRegions::Documentation = "Set SBAS delta UDREI outside all the defined regions for this service provider.";

    REGISTER_COMMAND_FACTORY(SetSbasDeltaUdreiOutsideOfRegions);


    SetSbasDeltaUdreiOutsideOfRegions::SetSbasDeltaUdreiOutsideOfRegions()
      : CommandBase(CmdName)
    {}

    SetSbasDeltaUdreiOutsideOfRegions::SetSbasDeltaUdreiOutsideOfRegions(const std::string& serviceProvider, int deltaUdrei)
      : CommandBase(CmdName)
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
