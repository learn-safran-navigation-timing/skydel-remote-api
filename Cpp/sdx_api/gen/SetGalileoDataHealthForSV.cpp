
#include "SetGalileoDataHealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGalileoDataHealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGalileoDataHealthForSV::CmdName = "SetGalileoDataHealthForSV";
    const char* const SetGalileoDataHealthForSV::Documentation = "Set Galileo data health for I/NAV and F/NAV message\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID number 1..36.\n"
      "Component   string          Component is either \"E5a\", \"E5b\", or \"E1B\"\n"
      "Health      bool            False means Navigation data valid; True means Working without guarantee\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetGalileoDataHealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetGalileoDataHealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetGalileoDataHealthForSV);


    SetGalileoDataHealthForSV::SetGalileoDataHealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetGalileoDataHealthForSV::SetGalileoDataHealthForSV(int svId, const std::string& component, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setComponent(component);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetGalileoDataHealthForSVPtr SetGalileoDataHealthForSV::create(int svId, const std::string& component, bool health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetGalileoDataHealthForSV>(svId, component, health, dataSetName);
    }

    SetGalileoDataHealthForSVPtr SetGalileoDataHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGalileoDataHealthForSV>(ptr);
    }

    bool SetGalileoDataHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["Component"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGalileoDataHealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetGalileoDataHealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Component", "Health", "DataSetName"}; 
      return names; 
    }


    int SetGalileoDataHealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGalileoDataHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetGalileoDataHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetGalileoDataHealthForSV::component() const
    {
      return parse_json<std::string>::parse(m_values["Component"]);
    }

    void SetGalileoDataHealthForSV::setComponent(const std::string& component)
    {
      m_values.AddMember("Component", parse_json<std::string>::format(component, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetGalileoDataHealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetGalileoDataHealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetGalileoDataHealthForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGalileoDataHealthForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
