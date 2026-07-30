
#include "GetElevationDataPath.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetElevationDataPath
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetElevationDataPath::CmdName = "GetElevationDataPath";
    const char* const GetElevationDataPath::Documentation = "Get the path to the directory containing the terrain elevation data files.";
    const char* const GetElevationDataPath::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetElevationDataPath);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetElevationDataPath);


    GetElevationDataPath::GetElevationDataPath()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetElevationDataPathPtr GetElevationDataPath::create()
    {
      return std::make_shared<GetElevationDataPath>();
    }

    GetElevationDataPathPtr GetElevationDataPath::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetElevationDataPath>(ptr);
    }

    bool GetElevationDataPath::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetElevationDataPath::documentation() const { return Documentation; }

    const std::vector<std::string>& GetElevationDataPath::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetElevationDataPath::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE;
    }

  }
}
