
#include "GetQzssL1cHealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssL1cHealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssL1cHealthForSV::CmdName = "GetQzssL1cHealthForSV";
    const char* const GetQzssL1cHealthForSV::Documentation = "Get QZSS L1C health (Health of L1C signal)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetQzssL1cHealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetQzssL1cHealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssL1cHealthForSV);


    GetQzssL1cHealthForSV::GetQzssL1cHealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetQzssL1cHealthForSV::GetQzssL1cHealthForSV(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetQzssL1cHealthForSVPtr GetQzssL1cHealthForSV::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssL1cHealthForSV>(svId, dataSetName);
    }

    GetQzssL1cHealthForSVPtr GetQzssL1cHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssL1cHealthForSV>(ptr);
    }

    bool GetQzssL1cHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssL1cHealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetQzssL1cHealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


    int GetQzssL1cHealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssL1cHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssL1cHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssL1cHealthForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssL1cHealthForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
