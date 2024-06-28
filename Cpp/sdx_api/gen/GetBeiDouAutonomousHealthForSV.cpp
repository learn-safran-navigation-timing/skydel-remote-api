
#include "GetBeiDouAutonomousHealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouAutonomousHealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouAutonomousHealthForSV::CmdName = "GetBeiDouAutonomousHealthForSV";
    const char* const GetBeiDouAutonomousHealthForSV::Documentation = "Get BeiDou satellite autonomous health\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetBeiDouAutonomousHealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetBeiDouAutonomousHealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetBeiDouAutonomousHealthForSV);


    GetBeiDouAutonomousHealthForSV::GetBeiDouAutonomousHealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetBeiDouAutonomousHealthForSV::GetBeiDouAutonomousHealthForSV(int svId, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetBeiDouAutonomousHealthForSVPtr GetBeiDouAutonomousHealthForSV::create(int svId, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouAutonomousHealthForSV>(svId, dataSetName);
    }

    GetBeiDouAutonomousHealthForSVPtr GetBeiDouAutonomousHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouAutonomousHealthForSV>(ptr);
    }

    bool GetBeiDouAutonomousHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetBeiDouAutonomousHealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetBeiDouAutonomousHealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


    int GetBeiDouAutonomousHealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetBeiDouAutonomousHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetBeiDouAutonomousHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetBeiDouAutonomousHealthForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetBeiDouAutonomousHealthForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
