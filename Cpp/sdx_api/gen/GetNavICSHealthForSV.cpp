
#include "GetNavICSHealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNavICSHealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNavICSHealthForSV::CmdName = "GetNavICSHealthForSV";
    const char* const GetNavICSHealthForSV::Documentation = "Get NavIC S health (Health of S signal)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..14, or use 0 to apply new value to all satellites.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetNavICSHealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetNavICSHealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetNavICSHealthForSV);


    GetNavICSHealthForSV::GetNavICSHealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetNavICSHealthForSV::GetNavICSHealthForSV(int svId, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetNavICSHealthForSVPtr GetNavICSHealthForSV::create(int svId, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetNavICSHealthForSV>(svId, dataSetName);
    }

    GetNavICSHealthForSVPtr GetNavICSHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNavICSHealthForSV>(ptr);
    }

    bool GetNavICSHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetNavICSHealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetNavICSHealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


    int GetNavICSHealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetNavICSHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetNavICSHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetNavICSHealthForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetNavICSHealthForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
