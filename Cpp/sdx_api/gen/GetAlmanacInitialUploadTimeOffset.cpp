
#include "GetAlmanacInitialUploadTimeOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAlmanacInitialUploadTimeOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAlmanacInitialUploadTimeOffset::CmdName = "GetAlmanacInitialUploadTimeOffset";
    const char* const GetAlmanacInitialUploadTimeOffset::Documentation = "Get next almanac upload time relative to simulation start time.";
    const char* const GetAlmanacInitialUploadTimeOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetAlmanacInitialUploadTimeOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAlmanacInitialUploadTimeOffset);


    GetAlmanacInitialUploadTimeOffset::GetAlmanacInitialUploadTimeOffset()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetAlmanacInitialUploadTimeOffsetPtr GetAlmanacInitialUploadTimeOffset::create()
    {
      return std::make_shared<GetAlmanacInitialUploadTimeOffset>();
    }

    GetAlmanacInitialUploadTimeOffsetPtr GetAlmanacInitialUploadTimeOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAlmanacInitialUploadTimeOffset>(ptr);
    }

    bool GetAlmanacInitialUploadTimeOffset::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetAlmanacInitialUploadTimeOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& GetAlmanacInitialUploadTimeOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetAlmanacInitialUploadTimeOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
