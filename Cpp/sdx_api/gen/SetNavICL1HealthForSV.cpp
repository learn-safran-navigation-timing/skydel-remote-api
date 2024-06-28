
#include "SetNavICL1HealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetNavICL1HealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetNavICL1HealthForSV::CmdName = "SetNavICL1HealthForSV";
    const char* const SetNavICL1HealthForSV::Documentation = "Set NavIC L1 health (Health of L1 signal)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..14, or use 0 to apply new value to all satellites.\n"
      "Health      bool            L1 health, false = signal OK, true = signal bad\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetNavICL1HealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetNavICL1HealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetNavICL1HealthForSV);


    SetNavICL1HealthForSV::SetNavICL1HealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetNavICL1HealthForSV::SetNavICL1HealthForSV(int svId, bool health, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetNavICL1HealthForSVPtr SetNavICL1HealthForSV::create(int svId, bool health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetNavICL1HealthForSV>(svId, health, dataSetName);
    }

    SetNavICL1HealthForSVPtr SetNavICL1HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetNavICL1HealthForSV>(ptr);
    }

    bool SetNavICL1HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetNavICL1HealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetNavICL1HealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int SetNavICL1HealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetNavICL1HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetNavICL1HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetNavICL1HealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetNavICL1HealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetNavICL1HealthForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetNavICL1HealthForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
