
#include "gen/GetWFAntennaOffset.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetWFAntennaOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetWFAntennaOffset::CmdName = "GetWFAntennaOffset";
    const char* const GetWFAntennaOffset::Documentation = "Get the WF antenna offset infos.";

    REGISTER_COMMAND_FACTORY(GetWFAntennaOffset);


    GetWFAntennaOffset::GetWFAntennaOffset()
      : CommandBase(CmdName)
    {

    }

    GetWFAntennaOffsetPtr GetWFAntennaOffset::create()
    {
      return std::make_shared<GetWFAntennaOffset>();
    }

    GetWFAntennaOffsetPtr GetWFAntennaOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetWFAntennaOffset>(ptr);
    }

    bool GetWFAntennaOffset::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetWFAntennaOffset::documentation() const { return Documentation; }


    int GetWFAntennaOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
