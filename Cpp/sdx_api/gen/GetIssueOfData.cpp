
#include "gen/GetIssueOfData.h"

#include "command_factory.h"
#include "command_result_factory.h"
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

    REGISTER_COMMAND_FACTORY(GetIssueOfData);


    GetIssueOfData::GetIssueOfData()
      : CommandBase(CmdName)
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


    int GetIssueOfData::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
