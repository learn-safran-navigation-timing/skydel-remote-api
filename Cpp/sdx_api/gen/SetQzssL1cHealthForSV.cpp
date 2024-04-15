
#include "SetQzssL1cHealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssL1cHealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssL1cHealthForSV::CmdName = "SetQzssL1cHealthForSV";
    const char* const SetQzssL1cHealthForSV::Documentation = "Set QZSS L1C health (Health of L1C signal)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.\n"
      "Health      bool            L1C health, false = signal OK, true = signal bad\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetQzssL1cHealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetQzssL1cHealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetQzssL1cHealthForSV);


    SetQzssL1cHealthForSV::SetQzssL1cHealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetQzssL1cHealthForSV::SetQzssL1cHealthForSV(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetQzssL1cHealthForSVPtr SetQzssL1cHealthForSV::create(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetQzssL1cHealthForSV>(svId, health, dataSetName);
    }

    SetQzssL1cHealthForSVPtr SetQzssL1cHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssL1cHealthForSV>(ptr);
    }

    bool SetQzssL1cHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetQzssL1cHealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetQzssL1cHealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int SetQzssL1cHealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetQzssL1cHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssL1cHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetQzssL1cHealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetQzssL1cHealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetQzssL1cHealthForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetQzssL1cHealthForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
