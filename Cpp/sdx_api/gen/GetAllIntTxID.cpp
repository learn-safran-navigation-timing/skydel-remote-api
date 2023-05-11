
#include "gen/GetAllIntTxID.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllIntTxID
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllIntTxID::CmdName = "GetAllIntTxID";
    const char* const GetAllIntTxID::Documentation = "Get the ID of all interferences transmitters.";

    REGISTER_COMMAND_FACTORY(GetAllIntTxID);


    GetAllIntTxID::GetAllIntTxID()
      : CommandBase(CmdName)
    {

    }

    GetAllIntTxIDPtr GetAllIntTxID::create()
    {
      return std::make_shared<GetAllIntTxID>();
    }

    GetAllIntTxIDPtr GetAllIntTxID::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllIntTxID>(ptr);
    }

    bool GetAllIntTxID::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetAllIntTxID::documentation() const { return Documentation; }


    int GetAllIntTxID::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
