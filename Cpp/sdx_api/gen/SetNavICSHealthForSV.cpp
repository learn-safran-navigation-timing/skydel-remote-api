
#include "SetNavICSHealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetNavICSHealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetNavICSHealthForSV::CmdName = "SetNavICSHealthForSV";
    const char* const SetNavICSHealthForSV::Documentation = "Set NavIC S health (Health of S signal)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..14, or use 0 to apply new value to all satellites.\n"
      "Health      bool            S health, false = signal OK, true = signal bad\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetNavICSHealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetNavICSHealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetNavICSHealthForSV);


    SetNavICSHealthForSV::SetNavICSHealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetNavICSHealthForSV::SetNavICSHealthForSV(int svId, bool health, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetNavICSHealthForSVPtr SetNavICSHealthForSV::create(int svId, bool health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetNavICSHealthForSV>(svId, health, dataSetName);
    }

    SetNavICSHealthForSVPtr SetNavICSHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetNavICSHealthForSV>(ptr);
    }

    bool SetNavICSHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetNavICSHealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetNavICSHealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int SetNavICSHealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetNavICSHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetNavICSHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetNavICSHealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetNavICSHealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetNavICSHealthForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetNavICSHealthForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
