
#include "SetDefaultIntTxPersistence.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetDefaultIntTxPersistence
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetDefaultIntTxPersistence::CmdName = "SetDefaultIntTxPersistence";
    const char* const SetDefaultIntTxPersistence::Documentation = "Set whether by default transmitters should keep the modification done during simulation.\n"
      "\n"
      "Name         Type Description\n"
      "------------ ---- --------------------------------------------------------------------------------\n"
      "DefaultValue bool True if jammers should keep the modifications done during simulation by default.";
    const char* const SetDefaultIntTxPersistence::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetDefaultIntTxPersistence);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetDefaultIntTxPersistence);


    SetDefaultIntTxPersistence::SetDefaultIntTxPersistence()
      : CommandBase(CmdName, TargetId)
    {}

    SetDefaultIntTxPersistence::SetDefaultIntTxPersistence(bool defaultValue)
      : CommandBase(CmdName, TargetId)
    {

      setDefaultValue(defaultValue);
    }

    SetDefaultIntTxPersistencePtr SetDefaultIntTxPersistence::create(bool defaultValue)
    {
      return std::make_shared<SetDefaultIntTxPersistence>(defaultValue);
    }

    SetDefaultIntTxPersistencePtr SetDefaultIntTxPersistence::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetDefaultIntTxPersistence>(ptr);
    }

    bool SetDefaultIntTxPersistence::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["DefaultValue"])
        ;

    }

    std::string SetDefaultIntTxPersistence::documentation() const { return Documentation; }

    const std::vector<std::string>& SetDefaultIntTxPersistence::fieldNames() const 
    { 
      static const std::vector<std::string> names {"DefaultValue"}; 
      return names; 
    }


    int SetDefaultIntTxPersistence::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool SetDefaultIntTxPersistence::defaultValue() const
    {
      return parse_json<bool>::parse(m_values["DefaultValue"]);
    }

    void SetDefaultIntTxPersistence::setDefaultValue(bool defaultValue)
    {
      m_values.AddMember("DefaultValue", parse_json<bool>::format(defaultValue, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
