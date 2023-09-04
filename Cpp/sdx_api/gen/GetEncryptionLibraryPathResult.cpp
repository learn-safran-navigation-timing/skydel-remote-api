
#include "gen/GetEncryptionLibraryPathResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetEncryptionLibraryPathResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetEncryptionLibraryPathResult::CmdName = "GetEncryptionLibraryPathResult";
    const char* const GetEncryptionLibraryPathResult::Documentation = "Result of GetEncryptionLibraryPath.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetEncryptionLibraryPathResult);


    GetEncryptionLibraryPathResult::GetEncryptionLibraryPathResult()
      : CommandResult(CmdName)
    {}

    GetEncryptionLibraryPathResult::GetEncryptionLibraryPathResult(const Sdx::EncryptionSignalType& type, const std::string& path)
      : CommandResult(CmdName)
    {

      setType(type);
      setPath(path);
    }

    GetEncryptionLibraryPathResult::GetEncryptionLibraryPathResult(CommandBasePtr relatedCommand, const Sdx::EncryptionSignalType& type, const std::string& path)
      : CommandResult(CmdName, relatedCommand)
    {

      setType(type);
      setPath(path);
    }


    GetEncryptionLibraryPathResultPtr GetEncryptionLibraryPathResult::create(const Sdx::EncryptionSignalType& type, const std::string& path)
    {
      return std::make_shared<GetEncryptionLibraryPathResult>(type, path);
    }

    GetEncryptionLibraryPathResultPtr GetEncryptionLibraryPathResult::create(CommandBasePtr relatedCommand, const Sdx::EncryptionSignalType& type, const std::string& path)
    {
      return std::make_shared<GetEncryptionLibraryPathResult>(relatedCommand, type, path);
    }

    GetEncryptionLibraryPathResultPtr GetEncryptionLibraryPathResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetEncryptionLibraryPathResult>(ptr);
    }

    bool GetEncryptionLibraryPathResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::EncryptionSignalType>::is_valid(m_values["Type"])
          && parse_json<std::string>::is_valid(m_values["Path"])
        ;

    }

    std::string GetEncryptionLibraryPathResult::documentation() const { return Documentation; }


    Sdx::EncryptionSignalType GetEncryptionLibraryPathResult::type() const
    {
      return parse_json<Sdx::EncryptionSignalType>::parse(m_values["Type"]);
    }

    void GetEncryptionLibraryPathResult::setType(const Sdx::EncryptionSignalType& type)
    {
      m_values.AddMember("Type", parse_json<Sdx::EncryptionSignalType>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetEncryptionLibraryPathResult::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void GetEncryptionLibraryPathResult::setPath(const std::string& path)
    {
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
