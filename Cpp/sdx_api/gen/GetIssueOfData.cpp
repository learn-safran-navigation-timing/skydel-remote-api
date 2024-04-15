
#include "GetIssueOfData.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIssueOfData
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIssueOfData::CmdName = "GetIssueOfData";
    const char* const GetIssueOfData::Documentation = "Get GPS Issue of data, Ephemeris (IODE) and Issue of data, Clock (IODC)";
    const char* const GetIssueOfData::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetIssueOfData);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIssueOfData);


    GetIssueOfData::GetIssueOfData()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetIssueOfDataPtr GetIssueOfData::create()
    {
      return std::make_shared<GetIssueOfData>();
    }

    GetIssueOfDataPtr GetIssueOfData::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIssueOfData>(ptr);
    }

    bool GetIssueOfData::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetIssueOfData::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIssueOfData::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetIssueOfData::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
