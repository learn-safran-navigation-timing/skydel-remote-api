
#include "gen/GetEncryptionLibraryPath.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetEncryptionLibraryPath
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetEncryptionLibraryPath::CmdName = "GetEncryptionLibraryPath";
    const char* const GetEncryptionLibraryPath::Documentation = "Get the specific encryption signal library path.";

    REGISTER_COMMAND_FACTORY(GetEncryptionLibraryPath);


    GetEncryptionLibraryPath::GetEncryptionLibraryPath()
      : CommandBase(CmdName)
    {}

    GetEncryptionLibraryPath::GetEncryptionLibraryPath(const Sdx::EncryptionSignalType& type)
      : CommandBase(CmdName)
    {

      setType(type);
    }

    GetEncryptionLibraryPathPtr GetEncryptionLibraryPath::create(const Sdx::EncryptionSignalType& type)
    {
      return std::make_shared<GetEncryptionLibraryPath>(type);
    }

    GetEncryptionLibraryPathPtr GetEncryptionLibraryPath::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetEncryptionLibraryPath>(ptr);
    }

    bool GetEncryptionLibraryPath::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::EncryptionSignalType>::is_valid(m_values["Type"])
        ;

    }

    std::string GetEncryptionLibraryPath::documentation() const { return Documentation; }


    int GetEncryptionLibraryPath::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE;
    }


    Sdx::EncryptionSignalType GetEncryptionLibraryPath::type() const
    {
      return parse_json<Sdx::EncryptionSignalType>::parse(m_values["Type"]);
    }

    void GetEncryptionLibraryPath::setType(const Sdx::EncryptionSignalType& type)
    {
      m_values.AddMember("Type", parse_json<Sdx::EncryptionSignalType>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
