
#include "GetEncryptionLibraryPath.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetEncryptionLibraryPath
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetEncryptionLibraryPath::CmdName = "GetEncryptionLibraryPath";
    const char* const GetEncryptionLibraryPath::Documentation = "Get the specific encryption signal library path.\n"
      "\n"
      "Name Type                 Description\n"
      "---- -------------------- -----------------------\n"
      "Type EncryptionSignalType Encryption signal type.";
    const char* const GetEncryptionLibraryPath::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetEncryptionLibraryPath);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetEncryptionLibraryPath);


    GetEncryptionLibraryPath::GetEncryptionLibraryPath()
      : CommandBase(CmdName, TargetId)
    {}

    GetEncryptionLibraryPath::GetEncryptionLibraryPath(const Sdx::EncryptionSignalType& type)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetEncryptionLibraryPath::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Type"}; 
      return names; 
    }


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
