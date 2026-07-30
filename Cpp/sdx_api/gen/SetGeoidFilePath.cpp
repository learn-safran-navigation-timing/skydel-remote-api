
#include "SetGeoidFilePath.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGeoidFilePath
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGeoidFilePath::CmdName = "SetGeoidFilePath";
    const char* const SetGeoidFilePath::Documentation = "Set the Geoid file path.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Path string Path to the Geoid file to use.";
    const char* const SetGeoidFilePath::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetGeoidFilePath);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetGeoidFilePath);


    SetGeoidFilePath::SetGeoidFilePath()
      : CommandBase(CmdName, TargetId)
    {}

    SetGeoidFilePath::SetGeoidFilePath(const std::string& path)
      : CommandBase(CmdName, TargetId)
    {

      setPath(path);
    }

    SetGeoidFilePathPtr SetGeoidFilePath::create(const std::string& path)
    {
      return std::make_shared<SetGeoidFilePath>(path);
    }

    SetGeoidFilePathPtr SetGeoidFilePath::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGeoidFilePath>(ptr);
    }

    bool SetGeoidFilePath::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Path"])
        ;

    }

    std::string SetGeoidFilePath::documentation() const { return Documentation; }

    const std::vector<std::string>& SetGeoidFilePath::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Path"}; 
      return names; 
    }


    int SetGeoidFilePath::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE;
    }


    std::string SetGeoidFilePath::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void SetGeoidFilePath::setPath(const std::string& path)
    {
      setValue("Path", parse_json<std::string>::format(path, m_values.GetAllocator()));
    }


  }
}
