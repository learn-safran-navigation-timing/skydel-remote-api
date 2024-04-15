
#include "GetElevationMaskAbove.h"

#include "command_factory.h"
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
    const char* const GetElevationMaskAbove::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetElevationMaskAbove);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetElevationMaskAbove);


    GetElevationMaskAbove::GetElevationMaskAbove()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetElevationMaskAbove::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetElevationMaskAbove::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
