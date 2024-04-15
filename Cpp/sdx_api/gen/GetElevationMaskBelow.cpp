
#include "GetElevationMaskBelow.h"

#include "command_factory.h"
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
    const char* const GetElevationMaskBelow::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetElevationMaskBelow);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetElevationMaskBelow);


    GetElevationMaskBelow::GetElevationMaskBelow()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetElevationMaskBelow::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetElevationMaskBelow::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
