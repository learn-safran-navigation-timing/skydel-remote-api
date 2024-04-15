
#include "GetGalileoDataHealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoDataHealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoDataHealthForSV::CmdName = "GetGalileoDataHealthForSV";
    const char* const GetGalileoDataHealthForSV::Documentation = "Get Galileo data health for I/NAV and F/NAV message\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID number 1..36.\n"
      "Component   string          Component is either \"E5a\", \"E5b\", or \"E1B\"\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetGalileoDataHealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGalileoDataHealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGalileoDataHealthForSV);


    GetGalileoDataHealthForSV::GetGalileoDataHealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetGalileoDataHealthForSV::GetGalileoDataHealthForSV(int svId, const std::string& component, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setComponent(component);
      setDataSetName(dataSetName);
    }

    GetGalileoDataHealthForSVPtr GetGalileoDataHealthForSV::create(int svId, const std::string& component, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGalileoDataHealthForSV>(svId, component, dataSetName);
    }

    GetGalileoDataHealthForSVPtr GetGalileoDataHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoDataHealthForSV>(ptr);
    }

    bool GetGalileoDataHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["Component"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGalileoDataHealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGalileoDataHealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Component", "DataSetName"}; 
      return names; 
    }


    int GetGalileoDataHealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGalileoDataHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGalileoDataHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGalileoDataHealthForSV::component() const
    {
      return parse_json<std::string>::parse(m_values["Component"]);
    }

    void GetGalileoDataHealthForSV::setComponent(const std::string& component)
    {
      m_values.AddMember("Component", parse_json<std::string>::format(component, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGalileoDataHealthForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGalileoDataHealthForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
