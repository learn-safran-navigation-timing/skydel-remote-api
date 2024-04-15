
#include "SetSbasServiceMessageRegionGroup.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSbasServiceMessageRegionGroup
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSbasServiceMessageRegionGroup::CmdName = "SetSbasServiceMessageRegionGroup";
    const char* const SetSbasServiceMessageRegionGroup::Documentation = "Set (or Modify) a SBAS service message region group.\n"
      "\n"
      "Name            Type                           Description\n"
      "--------------- ------------------------------ ---------------------------------------------------------------------------------\n"
      "ServiceProvider string                         Service providers, accepts \"WAAS\", \"EGNOS\", \"MSAS\", \"GAGAN\" and \"SDCM\".\n"
      "DeltaUdrei      int                            Delta UDREI applicable inside the defined regions. Accepted range is [0..15].\n"
      "PriorityCode    int                            Priority code of the SBAS service message region group. Accepted range is [0..3].\n"
      "Regions         array SbasServiceMessageRegion Array of SBAS service message regions. Accepted size range is [1..5].\n"
      "Id              string                         Unique identifier of the SBAS service message region group.";
    const char* const SetSbasServiceMessageRegionGroup::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSbasServiceMessageRegionGroup);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSbasServiceMessageRegionGroup);


    SetSbasServiceMessageRegionGroup::SetSbasServiceMessageRegionGroup()
      : CommandBase(CmdName, TargetId)
    {}

    SetSbasServiceMessageRegionGroup::SetSbasServiceMessageRegionGroup(const std::string& serviceProvider, int deltaUdrei, int priorityCode, const std::vector<Sdx::SbasServiceMessageRegion>& regions, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setServiceProvider(serviceProvider);
      setDeltaUdrei(deltaUdrei);
      setPriorityCode(priorityCode);
      setRegions(regions);
      setId(id);
    }

    SetSbasServiceMessageRegionGroupPtr SetSbasServiceMessageRegionGroup::create(const std::string& serviceProvider, int deltaUdrei, int priorityCode, const std::vector<Sdx::SbasServiceMessageRegion>& regions, const std::string& id)
    {
      return std::make_shared<SetSbasServiceMessageRegionGroup>(serviceProvider, deltaUdrei, priorityCode, regions, id);
    }

    SetSbasServiceMessageRegionGroupPtr SetSbasServiceMessageRegionGroup::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSbasServiceMessageRegionGroup>(ptr);
    }

    bool SetSbasServiceMessageRegionGroup::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
          && parse_json<int>::is_valid(m_values["DeltaUdrei"])
          && parse_json<int>::is_valid(m_values["PriorityCode"])
          && parse_json<std::vector<Sdx::SbasServiceMessageRegion>>::is_valid(m_values["Regions"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetSbasServiceMessageRegionGroup::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSbasServiceMessageRegionGroup::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ServiceProvider", "DeltaUdrei", "PriorityCode", "Regions", "Id"}; 
      return names; 
    }


    int SetSbasServiceMessageRegionGroup::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetSbasServiceMessageRegionGroup::serviceProvider() const
    {
      return parse_json<std::string>::parse(m_values["ServiceProvider"]);
    }

    void SetSbasServiceMessageRegionGroup::setServiceProvider(const std::string& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetSbasServiceMessageRegionGroup::deltaUdrei() const
    {
      return parse_json<int>::parse(m_values["DeltaUdrei"]);
    }

    void SetSbasServiceMessageRegionGroup::setDeltaUdrei(int deltaUdrei)
    {
      m_values.AddMember("DeltaUdrei", parse_json<int>::format(deltaUdrei, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetSbasServiceMessageRegionGroup::priorityCode() const
    {
      return parse_json<int>::parse(m_values["PriorityCode"]);
    }

    void SetSbasServiceMessageRegionGroup::setPriorityCode(int priorityCode)
    {
      m_values.AddMember("PriorityCode", parse_json<int>::format(priorityCode, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<Sdx::SbasServiceMessageRegion> SetSbasServiceMessageRegionGroup::regions() const
    {
      return parse_json<std::vector<Sdx::SbasServiceMessageRegion>>::parse(m_values["Regions"]);
    }

    void SetSbasServiceMessageRegionGroup::setRegions(const std::vector<Sdx::SbasServiceMessageRegion>& regions)
    {
      m_values.AddMember("Regions", parse_json<std::vector<Sdx::SbasServiceMessageRegion>>::format(regions, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetSbasServiceMessageRegionGroup::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetSbasServiceMessageRegionGroup::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
