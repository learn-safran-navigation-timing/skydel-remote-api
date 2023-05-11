
#include "gen/GetSbasDeltaUdreiOutsideOfRegionsResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasDeltaUdreiOutsideOfRegionsResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasDeltaUdreiOutsideOfRegionsResult::CmdName = "GetSbasDeltaUdreiOutsideOfRegionsResult";
    const char* const GetSbasDeltaUdreiOutsideOfRegionsResult::Documentation = "Result of GetSbasDeltaUdreiOutsideOfRegions.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetSbasDeltaUdreiOutsideOfRegionsResult);


    GetSbasDeltaUdreiOutsideOfRegionsResult::GetSbasDeltaUdreiOutsideOfRegionsResult()
      : CommandResult(CmdName)
    {}

    GetSbasDeltaUdreiOutsideOfRegionsResult::GetSbasDeltaUdreiOutsideOfRegionsResult(const std::string& serviceProvider, int deltaUdrei)
      : CommandResult(CmdName)
    {

      setServiceProvider(serviceProvider);
      setDeltaUdrei(deltaUdrei);
    }

    GetSbasDeltaUdreiOutsideOfRegionsResult::GetSbasDeltaUdreiOutsideOfRegionsResult(CommandBasePtr relatedCommand, const std::string& serviceProvider, int deltaUdrei)
      : CommandResult(CmdName, relatedCommand)
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
