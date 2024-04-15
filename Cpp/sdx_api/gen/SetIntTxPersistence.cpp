
#include "SetIntTxPersistence.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxPersistence
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxPersistence::CmdName = "SetIntTxPersistence";
    const char* const SetIntTxPersistence::Documentation = "Set whether the transmitter should keep the modifications done during the simulation.\n"
      "\n"
      "Name        Type   Description\n"
      "----------- ------ ------------------------------------------------------\n"
      "Persistence bool   True to keep the modifications, false to discard them.\n"
      "Id          string Transmitter unique identifier.";
    const char* const SetIntTxPersistence::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetIntTxPersistence);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetIntTxPersistence);


    SetIntTxPersistence::SetIntTxPersistence()
      : CommandBase(CmdName, TargetId)
    {}

    SetIntTxPersistence::SetIntTxPersistence(bool persistence, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setPersistence(persistence);
      setId(id);
    }

    SetIntTxPersistencePtr SetIntTxPersistence::create(bool persistence, const std::string& id)
    {
      return std::make_shared<SetIntTxPersistence>(persistence, id);
    }

    SetIntTxPersistencePtr SetIntTxPersistence::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIntTxPersistence>(ptr);
    }

    bool SetIntTxPersistence::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Persistence"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetIntTxPersistence::documentation() const { return Documentation; }

    const std::vector<std::string>& SetIntTxPersistence::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Persistence", "Id"}; 
      return names; 
    }


    int SetIntTxPersistence::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    bool SetIntTxPersistence::persistence() const
    {
      return parse_json<bool>::parse(m_values["Persistence"]);
    }

    void SetIntTxPersistence::setPersistence(bool persistence)
    {
      m_values.AddMember("Persistence", parse_json<bool>::format(persistence, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxPersistence::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetIntTxPersistence::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
