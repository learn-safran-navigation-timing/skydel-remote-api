
#include "gen/GetElevationMaskBelow.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetElevationMaskBelow
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetElevationMaskBelow::CmdName = "GetElevationMaskBelow";
    const char* const GetElevationMaskBelow::Documentation = "Get elevation mask angle. See command EnableElevationMaskBelow";

    REGISTER_COMMAND_FACTORY(GetElevationMaskBelow);


    GetElevationMaskBelow::GetElevationMaskBelow()
      : CommandBase(CmdName)
    {

    }

    GetElevationMaskBelowPtr GetElevationMaskBelow::create()
    {
      return std::make_shared<GetElevationMaskBelow>();
    }

    GetElevationMaskBelowPtr GetElevationMaskBelow::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetElevationMaskBelow>(ptr);
    }

    bool GetElevationMaskBelow::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetElevationMaskBelow::documentation() const { return Documentation; }


    int GetElevationMaskBelow::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
