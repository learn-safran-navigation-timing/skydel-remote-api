
#include "GetQzssL1DataHealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssL1DataHealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssL1DataHealthForSV::CmdName = "GetQzssL1DataHealthForSV";
    const char* const GetQzssL1DataHealthForSV::Documentation = "Get QZSS L1 C/A nav data health\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetQzssL1DataHealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetQzssL1DataHealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssL1DataHealthForSV);


    GetQzssL1DataHealthForSV::GetQzssL1DataHealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetQzssL1DataHealthForSV::GetQzssL1DataHealthForSV(int svId, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetQzssL1DataHealthForSVPtr GetQzssL1DataHealthForSV::create(int svId, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssL1DataHealthForSV>(svId, dataSetName);
    }

    GetQzssL1DataHealthForSVPtr GetQzssL1DataHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssL1DataHealthForSV>(ptr);
    }

    bool GetQzssL1DataHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssL1DataHealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetQzssL1DataHealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


    int GetQzssL1DataHealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssL1DataHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssL1DataHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetQzssL1DataHealthForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssL1DataHealthForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
