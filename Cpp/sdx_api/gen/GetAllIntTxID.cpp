
#include "GetAllIntTxID.h"

#include "command_factory.h"
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
    const char* const GetAllIntTxID::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetAllIntTxID);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAllIntTxID);


    GetAllIntTxID::GetAllIntTxID()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetAllIntTxID::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetAllIntTxID::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
