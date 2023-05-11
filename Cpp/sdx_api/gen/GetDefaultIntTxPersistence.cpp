
#include "gen/GetDefaultIntTxPersistence.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetDefaultIntTxPersistence
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetDefaultIntTxPersistence::CmdName = "GetDefaultIntTxPersistence";
    const char* const GetDefaultIntTxPersistence::Documentation = "Get wether by default transmitters should keep the modification done during simulation.";

    REGISTER_COMMAND_FACTORY(GetDefaultIntTxPersistence);


    GetDefaultIntTxPersistence::GetDefaultIntTxPersistence()
      : CommandBase(CmdName)
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


    int GetDefaultIntTxPersistence::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
