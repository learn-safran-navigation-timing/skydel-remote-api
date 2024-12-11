
#include "GetDynamicRangeOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetDynamicRangeOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetDynamicRangeOffset::CmdName = "GetDynamicRangeOffset";
    const char* const GetDynamicRangeOffset::Documentation = "Get the GNSS dynamic range offset. Changing this value shifts the dynamic power range available for GNSS signals. Increasing this value allows to simulate higher power signals and avoid IQ overflows. The range of the satellite power sliders in the Constellation tab is shifted by this offset.";
    const char* const GetDynamicRangeOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetDynamicRangeOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetDynamicRangeOffset);


    GetDynamicRangeOffset::GetDynamicRangeOffset()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetDynamicRangeOffsetPtr GetDynamicRangeOffset::create()
    {
      return std::make_shared<GetDynamicRangeOffset>();
    }

    GetDynamicRangeOffsetPtr GetDynamicRangeOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetDynamicRangeOffset>(ptr);
    }

    bool GetDynamicRangeOffset::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetDynamicRangeOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& GetDynamicRangeOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetDynamicRangeOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
