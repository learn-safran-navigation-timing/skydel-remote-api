
#include "GetBeiDouHealthStatusForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouHealthStatusForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouHealthStatusForSV::CmdName = "GetBeiDouHealthStatusForSV";
    const char* const GetBeiDouHealthStatusForSV::Documentation = "Get BeiDou satellite health status\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetBeiDouHealthStatusForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetBeiDouHealthStatusForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetBeiDouHealthStatusForSV);


    GetBeiDouHealthStatusForSV::GetBeiDouHealthStatusForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetBeiDouHealthStatusForSV::GetBeiDouHealthStatusForSV(int svId, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetBeiDouHealthStatusForSVPtr GetBeiDouHealthStatusForSV::create(int svId, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouHealthStatusForSV>(svId, dataSetName);
    }

    GetBeiDouHealthStatusForSVPtr GetBeiDouHealthStatusForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouHealthStatusForSV>(ptr);
    }

    bool GetBeiDouHealthStatusForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetBeiDouHealthStatusForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetBeiDouHealthStatusForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


    int GetBeiDouHealthStatusForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetBeiDouHealthStatusForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetBeiDouHealthStatusForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetBeiDouHealthStatusForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetBeiDouHealthStatusForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
