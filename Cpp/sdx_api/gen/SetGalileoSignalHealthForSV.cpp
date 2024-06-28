
#include "SetGalileoSignalHealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGalileoSignalHealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGalileoSignalHealthForSV::CmdName = "SetGalileoSignalHealthForSV";
    const char* const SetGalileoSignalHealthForSV::Documentation = "Set Galileo signal health for I/NAV and F/NAV message\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             The satellite's SV ID 1..36\n"
      "Component   string          Component is either \"E5a\", \"E5b\", or \"E1B\"\n"
      "Health      int             Signal health 0..3\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetGalileoSignalHealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetGalileoSignalHealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetGalileoSignalHealthForSV);


    SetGalileoSignalHealthForSV::SetGalileoSignalHealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetGalileoSignalHealthForSV::SetGalileoSignalHealthForSV(int svId, const std::string& component, int health, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setComponent(component);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetGalileoSignalHealthForSVPtr SetGalileoSignalHealthForSV::create(int svId, const std::string& component, int health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetGalileoSignalHealthForSV>(svId, component, health, dataSetName);
    }

    SetGalileoSignalHealthForSVPtr SetGalileoSignalHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGalileoSignalHealthForSV>(ptr);
    }

    bool SetGalileoSignalHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["Component"])
          && parse_json<int>::is_valid(m_values["Health"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGalileoSignalHealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetGalileoSignalHealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Component", "Health", "DataSetName"}; 
      return names; 
    }


    int SetGalileoSignalHealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGalileoSignalHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetGalileoSignalHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetGalileoSignalHealthForSV::component() const
    {
      return parse_json<std::string>::parse(m_values["Component"]);
    }

    void SetGalileoSignalHealthForSV::setComponent(const std::string& component)
    {
      m_values.AddMember("Component", parse_json<std::string>::format(component, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetGalileoSignalHealthForSV::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void SetGalileoSignalHealthForSV::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetGalileoSignalHealthForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGalileoSignalHealthForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
