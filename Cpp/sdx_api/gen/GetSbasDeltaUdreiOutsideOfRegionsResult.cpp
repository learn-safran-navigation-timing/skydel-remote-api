
#include "GetSbasDeltaUdreiOutsideOfRegionsResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasDeltaUdreiOutsideOfRegionsResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasDeltaUdreiOutsideOfRegionsResult::CmdName = "GetSbasDeltaUdreiOutsideOfRegionsResult";
    const char* const GetSbasDeltaUdreiOutsideOfRegionsResult::Documentation = "Result of GetSbasDeltaUdreiOutsideOfRegions.\n"
      "\n"
      "Name            Type   Description\n"
      "--------------- ------ ----------------------------------------------------------------------------------\n"
      "ServiceProvider string Service providers, accepts \"WAAS\", \"EGNOS\", \"MSAS\", \"GAGAN\" and \"SDCM\".\n"
      "DeltaUdrei      int    Delta UDREI applicable outside all the defined regions. Accepted range is [0..15].";
    const char* const GetSbasDeltaUdreiOutsideOfRegionsResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSbasDeltaUdreiOutsideOfRegionsResult);


    GetSbasDeltaUdreiOutsideOfRegionsResult::GetSbasDeltaUdreiOutsideOfRegionsResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetSbasDeltaUdreiOutsideOfRegionsResult::GetSbasDeltaUdreiOutsideOfRegionsResult(const std::string& serviceProvider, int deltaUdrei)
      : CommandResult(CmdName, TargetId)
    {

      setServiceProvider(serviceProvider);
      setDeltaUdrei(deltaUdrei);
    }

    GetSbasDeltaUdreiOutsideOfRegionsResult::GetSbasDeltaUdreiOutsideOfRegionsResult(CommandBasePtr relatedCommand, const std::string& serviceProvider, int deltaUdrei)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setServiceProvider(serviceProvider);
      setDeltaUdrei(deltaUdrei);
    }


    GetSbasDeltaUdreiOutsideOfRegionsResultPtr GetSbasDeltaUdreiOutsideOfRegionsResult::create(const std::string& serviceProvider, int deltaUdrei)
    {
      return std::make_shared<GetSbasDeltaUdreiOutsideOfRegionsResult>(serviceProvider, deltaUdrei);
    }

    GetSbasDeltaUdreiOutsideOfRegionsResultPtr GetSbasDeltaUdreiOutsideOfRegionsResult::create(CommandBasePtr relatedCommand, const std::string& serviceProvider, int deltaUdrei)
    {
      return std::make_shared<GetSbasDeltaUdreiOutsideOfRegionsResult>(relatedCommand, serviceProvider, deltaUdrei);
    }

    GetSbasDeltaUdreiOutsideOfRegionsResultPtr GetSbasDeltaUdreiOutsideOfRegionsResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasDeltaUdreiOutsideOfRegionsResult>(ptr);
    }

    bool GetSbasDeltaUdreiOutsideOfRegionsResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
          && parse_json<int>::is_valid(m_values["DeltaUdrei"])
        ;

    }

    std::string GetSbasDeltaUdreiOutsideOfRegionsResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSbasDeltaUdreiOutsideOfRegionsResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ServiceProvider", "DeltaUdrei"}; 
      return names; 
    }


    std::string GetSbasDeltaUdreiOutsideOfRegionsResult::serviceProvider() const
    {
      return parse_json<std::string>::parse(m_values["ServiceProvider"]);
    }

    void GetSbasDeltaUdreiOutsideOfRegionsResult::setServiceProvider(const std::string& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSbasDeltaUdreiOutsideOfRegionsResult::deltaUdrei() const
    {
      return parse_json<int>::parse(m_values["DeltaUdrei"]);
    }

    void GetSbasDeltaUdreiOutsideOfRegionsResult::setDeltaUdrei(int deltaUdrei)
    {
      m_values.AddMember("DeltaUdrei", parse_json<int>::format(deltaUdrei, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
