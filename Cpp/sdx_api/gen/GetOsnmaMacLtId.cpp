
#include "GetOsnmaMacLtId.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetOsnmaMacLtId
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetOsnmaMacLtId::CmdName = "GetOsnmaMacLtId";
    const char* const GetOsnmaMacLtId::Documentation = "Get OSNMA MAC look-up table ID.";
    const char* const GetOsnmaMacLtId::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetOsnmaMacLtId);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetOsnmaMacLtId);


    GetOsnmaMacLtId::GetOsnmaMacLtId()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetOsnmaMacLtIdPtr GetOsnmaMacLtId::create()
    {
      return std::make_shared<GetOsnmaMacLtId>();
    }

    GetOsnmaMacLtIdPtr GetOsnmaMacLtId::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetOsnmaMacLtId>(ptr);
    }

    bool GetOsnmaMacLtId::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetOsnmaMacLtId::documentation() const { return Documentation; }

    const std::vector<std::string>& GetOsnmaMacLtId::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetOsnmaMacLtId::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
