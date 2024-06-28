
#include "GetGpsSignalHealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsSignalHealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsSignalHealthForSV::CmdName = "GetGpsSignalHealthForSV";
    const char* const GetGpsSignalHealthForSV::Documentation = "Get GPS signal health\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite's SV ID 1..32\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetGpsSignalHealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGpsSignalHealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGpsSignalHealthForSV);


    GetGpsSignalHealthForSV::GetGpsSignalHealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetGpsSignalHealthForSV::GetGpsSignalHealthForSV(int svId, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetGpsSignalHealthForSVPtr GetGpsSignalHealthForSV::create(int svId, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsSignalHealthForSV>(svId, dataSetName);
    }

    GetGpsSignalHealthForSVPtr GetGpsSignalHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsSignalHealthForSV>(ptr);
    }

    bool GetGpsSignalHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsSignalHealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGpsSignalHealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


    int GetGpsSignalHealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsSignalHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsSignalHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetGpsSignalHealthForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsSignalHealthForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
