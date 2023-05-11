
#include "gen/GetAllSpoofTxID.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllSpoofTxID
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllSpoofTxID::CmdName = "GetAllSpoofTxID";
    const char* const GetAllSpoofTxID::Documentation = "Get the ID of all spoofer transmitters.";

    REGISTER_COMMAND_FACTORY(GetAllSpoofTxID);


    GetAllSpoofTxID::GetAllSpoofTxID()
      : CommandBase(CmdName)
    {

    }

    GetAllSpoofTxIDPtr GetAllSpoofTxID::create()
    {
      return std::make_shared<GetAllSpoofTxID>();
    }

    GetAllSpoofTxIDPtr GetAllSpoofTxID::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllSpoofTxID>(ptr);
    }

    bool GetAllSpoofTxID::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetAllSpoofTxID::documentation() const { return Documentation; }


    int GetAllSpoofTxID::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
