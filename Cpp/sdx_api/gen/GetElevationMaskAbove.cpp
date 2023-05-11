
#include "gen/GetElevationMaskAbove.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetElevationMaskAbove
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetElevationMaskAbove::CmdName = "GetElevationMaskAbove";
    const char* const GetElevationMaskAbove::Documentation = "Get elevation mask angle. See command EnableElevationMaskAbove";

    REGISTER_COMMAND_FACTORY(GetElevationMaskAbove);


    GetElevationMaskAbove::GetElevationMaskAbove()
      : CommandBase(CmdName)
    {

    }

    GetElevationMaskAbovePtr GetElevationMaskAbove::create()
    {
      return std::make_shared<GetElevationMaskAbove>();
    }

    GetElevationMaskAbovePtr GetElevationMaskAbove::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetElevationMaskAbove>(ptr);
    }

    bool GetElevationMaskAbove::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetElevationMaskAbove::documentation() const { return Documentation; }


    int GetElevationMaskAbove::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
