
#include "SetGpsL1cHealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsL1cHealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsL1cHealthForSV::CmdName = "SetGpsL1cHealthForSV";
    const char* const SetGpsL1cHealthForSV::Documentation = "Set GPS L1C health (used in CNAV2 only)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite's SV ID 1..32, or use 0 to apply new value to all satellites.\n"
      "Health      bool            L1C health, false = signal OK, true = signal bad or unavailable\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetGpsL1cHealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetGpsL1cHealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetGpsL1cHealthForSV);


    SetGpsL1cHealthForSV::SetGpsL1cHealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetGpsL1cHealthForSV::SetGpsL1cHealthForSV(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetGpsL1cHealthForSVPtr SetGpsL1cHealthForSV::create(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetGpsL1cHealthForSV>(svId, health, dataSetName);
    }

    SetGpsL1cHealthForSVPtr SetGpsL1cHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsL1cHealthForSV>(ptr);
    }

    bool SetGpsL1cHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGpsL1cHealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetGpsL1cHealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int SetGpsL1cHealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGpsL1cHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetGpsL1cHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetGpsL1cHealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetGpsL1cHealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetGpsL1cHealthForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGpsL1cHealthForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
