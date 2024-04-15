
#include "GetGpsConfigurationForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsConfigurationForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsConfigurationForEachSV::CmdName = "GetGpsConfigurationForEachSV";
    const char* const GetGpsConfigurationForEachSV::Documentation = "Get GPS SV configuration flag for each SVs\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetGpsConfigurationForEachSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGpsConfigurationForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGpsConfigurationForEachSV);


    GetGpsConfigurationForEachSV::GetGpsConfigurationForEachSV(const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setDataSetName(dataSetName);
    }

    GetGpsConfigurationForEachSVPtr GetGpsConfigurationForEachSV::create(const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsConfigurationForEachSV>(dataSetName);
    }

    GetGpsConfigurationForEachSVPtr GetGpsConfigurationForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsConfigurationForEachSV>(ptr);
    }

    bool GetGpsConfigurationForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsConfigurationForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGpsConfigurationForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"DataSetName"}; 
      return names; 
    }


    int GetGpsConfigurationForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    Sdx::optional<std::string> GetGpsConfigurationForEachSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsConfigurationForEachSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
