
#include "SetNavICL5HealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetNavICL5HealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetNavICL5HealthForSV::CmdName = "SetNavICL5HealthForSV";
    const char* const SetNavICL5HealthForSV::Documentation = "Set NavIC L5 health (Health of L5 signal)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..14, or use 0 to apply new value to all satellites.\n"
      "Health      bool            L5 health, false = signal OK, true = signal bad\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetNavICL5HealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetNavICL5HealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetNavICL5HealthForSV);


    SetNavICL5HealthForSV::SetNavICL5HealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetNavICL5HealthForSV::SetNavICL5HealthForSV(int svId, bool health, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetNavICL5HealthForSVPtr SetNavICL5HealthForSV::create(int svId, bool health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetNavICL5HealthForSV>(svId, health, dataSetName);
    }

    SetNavICL5HealthForSVPtr SetNavICL5HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetNavICL5HealthForSV>(ptr);
    }

    bool SetNavICL5HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetNavICL5HealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetNavICL5HealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int SetNavICL5HealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetNavICL5HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetNavICL5HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetNavICL5HealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetNavICL5HealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetNavICL5HealthForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetNavICL5HealthForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
