
#include "GetAllSpoofTxID.h"

#include "command_factory.h"
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
    const char* const GetAllSpoofTxID::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetAllSpoofTxID);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAllSpoofTxID);


    GetAllSpoofTxID::GetAllSpoofTxID()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetAllSpoofTxID::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetAllSpoofTxID::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
