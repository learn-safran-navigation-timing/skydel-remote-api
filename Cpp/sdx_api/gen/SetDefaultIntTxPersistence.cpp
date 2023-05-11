
#include "gen/SetDefaultIntTxPersistence.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetDefaultIntTxPersistence
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetDefaultIntTxPersistence::CmdName = "SetDefaultIntTxPersistence";
    const char* const SetDefaultIntTxPersistence::Documentation = "Set wether by default transmitters should keep the modification done during simulation.";

    REGISTER_COMMAND_FACTORY(SetDefaultIntTxPersistence);


    SetDefaultIntTxPersistence::SetDefaultIntTxPersistence()
      : CommandBase(CmdName)
    {}

    SetDefaultIntTxPersistence::SetDefaultIntTxPersistence(bool defaultValue)
      : CommandBase(CmdName)
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
