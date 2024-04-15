
#include "TestEncryptionLibrary.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of TestEncryptionLibrary
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const TestEncryptionLibrary::CmdName = "TestEncryptionLibrary";
    const char* const TestEncryptionLibrary::Documentation = "Test the specific encryption signal library.\n"
      "\n"
      "Name Type                 Description\n"
      "---- -------------------- -----------------------\n"
      "Type EncryptionSignalType Encryption signal type.";
    const char* const TestEncryptionLibrary::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(TestEncryptionLibrary);
    REGISTER_COMMAND_TO_FACTORY_IMPL(TestEncryptionLibrary);


    TestEncryptionLibrary::TestEncryptionLibrary()
      : CommandBase(CmdName, TargetId)
    {}

    TestEncryptionLibrary::TestEncryptionLibrary(const Sdx::EncryptionSignalType& type)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& TestEncryptionLibrary::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Type"}; 
      return names; 
    }


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
