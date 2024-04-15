
#include "GetDefaultIntTxPersistence.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetDefaultIntTxPersistence
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetDefaultIntTxPersistence::CmdName = "GetDefaultIntTxPersistence";
    const char* const GetDefaultIntTxPersistence::Documentation = "Get whether by default transmitters should keep the modification done during simulation.";
    const char* const GetDefaultIntTxPersistence::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetDefaultIntTxPersistence);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetDefaultIntTxPersistence);


    GetDefaultIntTxPersistence::GetDefaultIntTxPersistence()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetDefaultIntTxPersistencePtr GetDefaultIntTxPersistence::create()
    {
      return std::make_shared<GetDefaultIntTxPersistence>();
    }

    GetDefaultIntTxPersistencePtr GetDefaultIntTxPersistence::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetDefaultIntTxPersistence>(ptr);
    }

    bool GetDefaultIntTxPersistence::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetDefaultIntTxPersistence::documentation() const { return Documentation; }

    const std::vector<std::string>& GetDefaultIntTxPersistence::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetDefaultIntTxPersistence::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
