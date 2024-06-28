
#include "GetNavICL1HealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNavICL1HealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNavICL1HealthForSV::CmdName = "GetNavICL1HealthForSV";
    const char* const GetNavICL1HealthForSV::Documentation = "Get NavIC L1 health (Health of L1 signal)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..14, or use 0 to apply new value to all satellites.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetNavICL1HealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetNavICL1HealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetNavICL1HealthForSV);


    GetNavICL1HealthForSV::GetNavICL1HealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetNavICL1HealthForSV::GetNavICL1HealthForSV(int svId, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetNavICL1HealthForSVPtr GetNavICL1HealthForSV::create(int svId, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetNavICL1HealthForSV>(svId, dataSetName);
    }

    GetNavICL1HealthForSVPtr GetNavICL1HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNavICL1HealthForSV>(ptr);
    }

    bool GetNavICL1HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetNavICL1HealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetNavICL1HealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


    int GetNavICL1HealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetNavICL1HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetNavICL1HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetNavICL1HealthForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetNavICL1HealthForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
