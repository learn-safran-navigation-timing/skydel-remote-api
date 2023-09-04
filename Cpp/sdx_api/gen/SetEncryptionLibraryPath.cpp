
#include "gen/SetEncryptionLibraryPath.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetEncryptionLibraryPath
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetEncryptionLibraryPath::CmdName = "SetEncryptionLibraryPath";
    const char* const SetEncryptionLibraryPath::Documentation = "Set the specific encryption signal library path.";

    REGISTER_COMMAND_FACTORY(SetEncryptionLibraryPath);


    SetEncryptionLibraryPath::SetEncryptionLibraryPath()
      : CommandBase(CmdName)
    {}

    SetEncryptionLibraryPath::SetEncryptionLibraryPath(const Sdx::EncryptionSignalType& type, const std::string& path)
      : CommandBase(CmdName)
    {

      setType(type);
      setPath(path);
    }

    SetEncryptionLibraryPathPtr SetEncryptionLibraryPath::create(const Sdx::EncryptionSignalType& type, const std::string& path)
    {
      return std::make_shared<SetEncryptionLibraryPath>(type, path);
    }

    SetEncryptionLibraryPathPtr SetEncryptionLibraryPath::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetEncryptionLibraryPath>(ptr);
    }

    bool SetEncryptionLibraryPath::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::EncryptionSignalType>::is_valid(m_values["Type"])
          && parse_json<std::string>::is_valid(m_values["Path"])
        ;

    }

    std::string SetEncryptionLibraryPath::documentation() const { return Documentation; }


    int SetEncryptionLibraryPath::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE;
    }


    Sdx::EncryptionSignalType SetEncryptionLibraryPath::type() const
    {
      return parse_json<Sdx::EncryptionSignalType>::parse(m_values["Type"]);
    }

    void SetEncryptionLibraryPath::setType(const Sdx::EncryptionSignalType& type)
    {
      m_values.AddMember("Type", parse_json<Sdx::EncryptionSignalType>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetEncryptionLibraryPath::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void SetEncryptionLibraryPath::setPath(const std::string& path)
    {
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
