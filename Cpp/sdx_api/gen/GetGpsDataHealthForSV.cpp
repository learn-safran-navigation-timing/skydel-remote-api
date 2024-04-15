
#include "GetGpsDataHealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsDataHealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsDataHealthForSV::CmdName = "GetGpsDataHealthForSV";
    const char* const GetGpsDataHealthForSV::Documentation = "Get GPS nav data health\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite's SV ID 1..32\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetGpsDataHealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGpsDataHealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGpsDataHealthForSV);


    GetGpsDataHealthForSV::GetGpsDataHealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetGpsDataHealthForSV::GetGpsDataHealthForSV(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetGpsDataHealthForSVPtr GetGpsDataHealthForSV::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsDataHealthForSV>(svId, dataSetName);
    }

    GetGpsDataHealthForSVPtr GetGpsDataHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsDataHealthForSV>(ptr);
    }

    bool GetGpsDataHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsDataHealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGpsDataHealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


    int GetGpsDataHealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsDataHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsDataHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGpsDataHealthForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsDataHealthForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
