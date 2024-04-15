
#include "GetWFAntennaOffset.h"

#include "command_factory.h"
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
    const char* const GetWFAntennaOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetWFAntennaOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetWFAntennaOffset);


    GetWFAntennaOffset::GetWFAntennaOffset()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetWFAntennaOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetWFAntennaOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
