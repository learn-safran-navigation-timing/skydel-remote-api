
#include "GetOsnmaTeslaKeySize.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetOsnmaTeslaKeySize
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetOsnmaTeslaKeySize::CmdName = "GetOsnmaTeslaKeySize";
    const char* const GetOsnmaTeslaKeySize::Documentation = "Get OSNMA TESLA key size.";
    const char* const GetOsnmaTeslaKeySize::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetOsnmaTeslaKeySize);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetOsnmaTeslaKeySize);


    GetOsnmaTeslaKeySize::GetOsnmaTeslaKeySize()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetOsnmaTeslaKeySizePtr GetOsnmaTeslaKeySize::create()
    {
      return std::make_shared<GetOsnmaTeslaKeySize>();
    }

    GetOsnmaTeslaKeySizePtr GetOsnmaTeslaKeySize::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetOsnmaTeslaKeySize>(ptr);
    }

    bool GetOsnmaTeslaKeySize::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetOsnmaTeslaKeySize::documentation() const { return Documentation; }

    const std::vector<std::string>& GetOsnmaTeslaKeySize::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetOsnmaTeslaKeySize::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
