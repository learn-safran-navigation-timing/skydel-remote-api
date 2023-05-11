
#include "gen/GetGalileoDataHealthForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoDataHealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoDataHealthForSV::CmdName = "GetGalileoDataHealthForSV";
    const char* const GetGalileoDataHealthForSV::Documentation = "Get Galileo data health for I/NAV and F/NAV message";

    REGISTER_COMMAND_FACTORY(GetGalileoDataHealthForSV);


    GetGalileoDataHealthForSV::GetGalileoDataHealthForSV()
      : CommandBase(CmdName)
    {}

    GetGalileoDataHealthForSV::GetGalileoDataHealthForSV(int svId, const std::string& component, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
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
