
#include "gen/TestEncryptionLibrary.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of TestEncryptionLibrary
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const TestEncryptionLibrary::CmdName = "TestEncryptionLibrary";
    const char* const TestEncryptionLibrary::Documentation = "Test the specific encryption signal library.";

    REGISTER_COMMAND_FACTORY(TestEncryptionLibrary);


    TestEncryptionLibrary::TestEncryptionLibrary()
      : CommandBase(CmdName)
    {}

    TestEncryptionLibrary::TestEncryptionLibrary(const Sdx::EncryptionSignalType& type)
      : CommandBase(CmdName)
    {

      setType(type);
    }

    TestEncryptionLibraryPtr TestEncryptionLibrary::create(const Sdx::EncryptionSignalType& type)
    {
      return std::make_shared<TestEncryptionLibrary>(type);
    }

    TestEncryptionLibraryPtr TestEncryptionLibrary::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<TestEncryptionLibrary>(ptr);
    }

    bool TestEncryptionLibrary::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::EncryptionSignalType>::is_valid(m_values["Type"])
        ;

    }

    std::string TestEncryptionLibrary::documentation() const { return Documentation; }


    int TestEncryptionLibrary::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE;
    }


    Sdx::EncryptionSignalType TestEncryptionLibrary::type() const
    {
      return parse_json<Sdx::EncryptionSignalType>::parse(m_values["Type"]);
    }

    void TestEncryptionLibrary::setType(const Sdx::EncryptionSignalType& type)
    {
      m_values.AddMember("Type", parse_json<Sdx::EncryptionSignalType>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
