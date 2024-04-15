
#include "GetSbasServiceMessageRegionGroupResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasServiceMessageRegionGroupResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasServiceMessageRegionGroupResult::CmdName = "GetSbasServiceMessageRegionGroupResult";
    const char* const GetSbasServiceMessageRegionGroupResult::Documentation = "Result of GetSbasServiceMessageRegionGroup.\n"
      "\n"
      "Name            Type                           Description\n"
      "--------------- ------------------------------ ---------------------------------------------------------------------------------\n"
      "ServiceProvider string                         Service providers, accepts \"WAAS\", \"EGNOS\", \"MSAS\", \"GAGAN\" and \"SDCM\".\n"
      "DeltaUdrei      int                            Delta UDREI applicable inside the defined regions. Accepted range is [0..15].\n"
      "PriorityCode    int                            Priority code of the SBAS service message region group. Accepted range is [0..3].\n"
      "Regions         array SbasServiceMessageRegion Array of SBAS service message regions. Accepted size range is [1..5].\n"
      "Id              string                         Unique identifier of the SBAS service message region group.";
    const char* const GetSbasServiceMessageRegionGroupResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSbasServiceMessageRegionGroupResult);


    GetSbasServiceMessageRegionGroupResult::GetSbasServiceMessageRegionGroupResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetSbasServiceMessageRegionGroupResult::GetSbasServiceMessageRegionGroupResult(const std::string& serviceProvider, int deltaUdrei, int priorityCode, const std::vector<Sdx::SbasServiceMessageRegion>& regions, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setServiceProvider(serviceProvider);
      setDeltaUdrei(deltaUdrei);
      setPriorityCode(priorityCode);
      setRegions(regions);
      setId(id);
    }

    GetSbasServiceMessageRegionGroupResult::GetSbasServiceMessageRegionGroupResult(CommandBasePtr relatedCommand, const std::string& serviceProvider, int deltaUdrei, int priorityCode, const std::vector<Sdx::SbasServiceMessageRegion>& regions, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setServiceProvider(serviceProvider);
      setDeltaUdrei(deltaUdrei);
      setPriorityCode(priorityCode);
      setRegions(regions);
      setId(id);
    }


    GetSbasServiceMessageRegionGroupResultPtr GetSbasServiceMessageRegionGroupResult::create(const std::string& serviceProvider, int deltaUdrei, int priorityCode, const std::vector<Sdx::SbasServiceMessageRegion>& regions, const std::string& id)
    {
      return std::make_shared<GetSbasServiceMessageRegionGroupResult>(serviceProvider, deltaUdrei, priorityCode, regions, id);
    }

    GetSbasServiceMessageRegionGroupResultPtr GetSbasServiceMessageRegionGroupResult::create(CommandBasePtr relatedCommand, const std::string& serviceProvider, int deltaUdrei, int priorityCode, const std::vector<Sdx::SbasServiceMessageRegion>& regions, const std::string& id)
    {
      return std::make_shared<GetSbasServiceMessageRegionGroupResult>(relatedCommand, serviceProvider, deltaUdrei, priorityCode, regions, id);
    }

    GetSbasServiceMessageRegionGroupResultPtr GetSbasServiceMessageRegionGroupResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasServiceMessageRegionGroupResult>(ptr);
    }

    bool GetSbasServiceMessageRegionGroupResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
          && parse_json<int>::is_valid(m_values["DeltaUdrei"])
          && parse_json<int>::is_valid(m_values["PriorityCode"])
          && parse_json<std::vector<Sdx::SbasServiceMessageRegion>>::is_valid(m_values["Regions"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetSbasServiceMessageRegionGroupResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSbasServiceMessageRegionGroupResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ServiceProvider", "DeltaUdrei", "PriorityCode", "Regions", "Id"}; 
      return names; 
    }


    std::string GetSbasServiceMessageRegionGroupResult::serviceProvider() const
    {
      return parse_json<std::string>::parse(m_values["ServiceProvider"]);
    }

    void GetSbasServiceMessageRegionGroupResult::setServiceProvider(const std::string& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSbasServiceMessageRegionGroupResult::deltaUdrei() const
    {
      return parse_json<int>::parse(m_values["DeltaUdrei"]);
    }

    void GetSbasServiceMessageRegionGroupResult::setDeltaUdrei(int deltaUdrei)
    {
      m_values.AddMember("DeltaUdrei", parse_json<int>::format(deltaUdrei, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSbasServiceMessageRegionGroupResult::priorityCode() const
    {
      return parse_json<int>::parse(m_values["PriorityCode"]);
    }

    void GetSbasServiceMessageRegionGroupResult::setPriorityCode(int priorityCode)
    {
      m_values.AddMember("PriorityCode", parse_json<int>::format(priorityCode, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<Sdx::SbasServiceMessageRegion> GetSbasServiceMessageRegionGroupResult::regions() const
    {
      return parse_json<std::vector<Sdx::SbasServiceMessageRegion>>::parse(m_values["Regions"]);
    }

    void GetSbasServiceMessageRegionGroupResult::setRegions(const std::vector<Sdx::SbasServiceMessageRegion>& regions)
    {
      m_values.AddMember("Regions", parse_json<std::vector<Sdx::SbasServiceMessageRegion>>::format(regions, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSbasServiceMessageRegionGroupResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetSbasServiceMessageRegionGroupResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
