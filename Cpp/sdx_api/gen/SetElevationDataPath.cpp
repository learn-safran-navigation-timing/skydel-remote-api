
#include "SetElevationDataPath.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetElevationDataPath
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetElevationDataPath::CmdName = "SetElevationDataPath";
    const char* const SetElevationDataPath::Documentation = "Set the path to the directory containing the terrain elevation data files.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ---------------------------\n"
      "Path string Path to the elevation data.";
    const char* const SetElevationDataPath::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetElevationDataPath);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetElevationDataPath);


    SetElevationDataPath::SetElevationDataPath()
      : CommandBase(CmdName, TargetId)
    {}

    SetElevationDataPath::SetElevationDataPath(const std::string& path)
      : CommandBase(CmdName, TargetId)
    {

      setPath(path);
    }

    SetElevationDataPathPtr SetElevationDataPath::create(const std::string& path)
    {
      return std::make_shared<SetElevationDataPath>(path);
    }

    SetElevationDataPathPtr SetElevationDataPath::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetElevationDataPath>(ptr);
    }

    bool SetElevationDataPath::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Path"])
        ;

    }

    std::string SetElevationDataPath::documentation() const { return Documentation; }

    const std::vector<std::string>& SetElevationDataPath::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Path"}; 
      return names; 
    }


    int SetElevationDataPath::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE;
    }


    std::string SetElevationDataPath::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void SetElevationDataPath::setPath(const std::string& path)
    {
      setValue("Path", parse_json<std::string>::format(path, m_values.GetAllocator()));
    }


  }
}
