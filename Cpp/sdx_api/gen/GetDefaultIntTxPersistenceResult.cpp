
#include "GetDefaultIntTxPersistenceResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetDefaultIntTxPersistenceResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetDefaultIntTxPersistenceResult::CmdName = "GetDefaultIntTxPersistenceResult";
    const char* const GetDefaultIntTxPersistenceResult::Documentation = "Result of GetDefaultIntTxPersistence.\n"
      "\n"
      "Name         Type Description\n"
      "------------ ---- --------------------------------------------------------------------------------\n"
      "DefaultValue bool True if jammers should keep the modifications done during simulation by default.";
    const char* const GetDefaultIntTxPersistenceResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetDefaultIntTxPersistenceResult);


    GetDefaultIntTxPersistenceResult::GetDefaultIntTxPersistenceResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetDefaultIntTxPersistenceResult::GetDefaultIntTxPersistenceResult(bool defaultValue)
      : CommandResult(CmdName, TargetId)
    {

      setDefaultValue(defaultValue);
    }

    GetDefaultIntTxPersistenceResult::GetDefaultIntTxPersistenceResult(CommandBasePtr relatedCommand, bool defaultValue)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& GetDefaultIntTxPersistenceResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"DefaultValue"}; 
      return names; 
    }


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
