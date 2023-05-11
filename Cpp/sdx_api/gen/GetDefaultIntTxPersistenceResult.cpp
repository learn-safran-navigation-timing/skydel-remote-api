
#include "gen/GetDefaultIntTxPersistenceResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetDefaultIntTxPersistenceResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetDefaultIntTxPersistenceResult::CmdName = "GetDefaultIntTxPersistenceResult";
    const char* const GetDefaultIntTxPersistenceResult::Documentation = "Result of GetDefaultIntTxPersistence.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetDefaultIntTxPersistenceResult);


    GetDefaultIntTxPersistenceResult::GetDefaultIntTxPersistenceResult()
      : CommandResult(CmdName)
    {}

    GetDefaultIntTxPersistenceResult::GetDefaultIntTxPersistenceResult(bool defaultValue)
      : CommandResult(CmdName)
    {

      setDefaultValue(defaultValue);
    }

    GetDefaultIntTxPersistenceResult::GetDefaultIntTxPersistenceResult(CommandBasePtr relatedCommand, bool defaultValue)
      : CommandResult(CmdName, relatedCommand)
    {

      setDefaultValue(defaultValue);
    }


    GetDefaultIntTxPersistenceResultPtr GetDefaultIntTxPersistenceResult::create(bool defaultValue)
    {
      return std::make_shared<GetDefaultIntTxPersistenceResult>(defaultValue);
    }

    GetDefaultIntTxPersistenceResultPtr GetDefaultIntTxPersistenceResult::create(CommandBasePtr relatedCommand, bool defaultValue)
    {
      return std::make_shared<GetDefaultIntTxPersistenceResult>(relatedCommand, defaultValue);
    }

    GetDefaultIntTxPersistenceResultPtr GetDefaultIntTxPersistenceResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetDefaultIntTxPersistenceResult>(ptr);
    }

    bool GetDefaultIntTxPersistenceResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["DefaultValue"])
        ;

    }

    std::string GetDefaultIntTxPersistenceResult::documentation() const { return Documentation; }


    bool GetDefaultIntTxPersistenceResult::defaultValue() const
    {
      return parse_json<bool>::parse(m_values["DefaultValue"]);
    }

    void GetDefaultIntTxPersistenceResult::setDefaultValue(bool defaultValue)
    {
      m_values.AddMember("DefaultValue", parse_json<bool>::format(defaultValue, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
