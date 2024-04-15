
#include "GetVersion.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVersion
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVersion::CmdName = "GetVersion";
    const char* const GetVersion::Documentation = "Get Skydel version.";
    const char* const GetVersion::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetVersion);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetVersion);


    GetVersion::GetVersion()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetVersionPtr GetVersion::create()
    {
      return std::make_shared<GetVersion>();
    }

    GetVersionPtr GetVersion::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVersion>(ptr);
    }

    bool GetVersion::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetVersion::documentation() const { return Documentation; }

    const std::vector<std::string>& GetVersion::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetVersion::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
