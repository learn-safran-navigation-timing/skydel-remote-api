
#include "SetGpsDataHealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsDataHealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsDataHealthForSV::CmdName = "SetGpsDataHealthForSV";
    const char* const SetGpsDataHealthForSV::Documentation = "Set GPS nav data health\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite's SV ID 1..32\n"
      "Health      int             Data health 0..7\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetGpsDataHealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetGpsDataHealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetGpsDataHealthForSV);


    SetGpsDataHealthForSV::SetGpsDataHealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetGpsDataHealthForSV::SetGpsDataHealthForSV(int svId, int health, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetGpsDataHealthForSVPtr SetGpsDataHealthForSV::create(int svId, int health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetGpsDataHealthForSV>(svId, health, dataSetName);
    }

    SetGpsDataHealthForSVPtr SetGpsDataHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsDataHealthForSV>(ptr);
    }

    bool SetGpsDataHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGpsDataHealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetGpsDataHealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int SetGpsDataHealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGpsDataHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetGpsDataHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetGpsDataHealthForSV::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void SetGpsDataHealthForSV::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetGpsDataHealthForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGpsDataHealthForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
