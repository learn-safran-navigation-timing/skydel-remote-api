
#include "GetBeiDouCNavHealthInfoForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouCNavHealthInfoForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouCNavHealthInfoForSV::CmdName = "GetBeiDouCNavHealthInfoForSV";
    const char* const GetBeiDouCNavHealthInfoForSV::Documentation = "Get BeiDou CNav satellite health info\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetBeiDouCNavHealthInfoForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetBeiDouCNavHealthInfoForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetBeiDouCNavHealthInfoForSV);


    GetBeiDouCNavHealthInfoForSV::GetBeiDouCNavHealthInfoForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetBeiDouCNavHealthInfoForSV::GetBeiDouCNavHealthInfoForSV(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetBeiDouCNavHealthInfoForSVPtr GetBeiDouCNavHealthInfoForSV::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouCNavHealthInfoForSV>(svId, dataSetName);
    }

    GetBeiDouCNavHealthInfoForSVPtr GetBeiDouCNavHealthInfoForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouCNavHealthInfoForSV>(ptr);
    }

    bool GetBeiDouCNavHealthInfoForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetBeiDouCNavHealthInfoForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetBeiDouCNavHealthInfoForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


    int GetBeiDouCNavHealthInfoForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetBeiDouCNavHealthInfoForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetBeiDouCNavHealthInfoForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetBeiDouCNavHealthInfoForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetBeiDouCNavHealthInfoForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
