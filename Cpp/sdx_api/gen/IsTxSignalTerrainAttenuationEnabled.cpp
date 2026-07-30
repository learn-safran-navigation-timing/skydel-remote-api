
#include "IsTxSignalTerrainAttenuationEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsTxSignalTerrainAttenuationEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsTxSignalTerrainAttenuationEnabled::CmdName = "IsTxSignalTerrainAttenuationEnabled";
    const char* const IsTxSignalTerrainAttenuationEnabled::Documentation = "Tells whether terrain-based attenuation of interference and spoofing signals is enabled.";
    const char* const IsTxSignalTerrainAttenuationEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsTxSignalTerrainAttenuationEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsTxSignalTerrainAttenuationEnabled);


    IsTxSignalTerrainAttenuationEnabled::IsTxSignalTerrainAttenuationEnabled()
      : CommandBase(CmdName, TargetId)
    {

    }

    IsTxSignalTerrainAttenuationEnabledPtr IsTxSignalTerrainAttenuationEnabled::create()
    {
      return std::make_shared<IsTxSignalTerrainAttenuationEnabled>();
    }

    IsTxSignalTerrainAttenuationEnabledPtr IsTxSignalTerrainAttenuationEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsTxSignalTerrainAttenuationEnabled>(ptr);
    }

    bool IsTxSignalTerrainAttenuationEnabled::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsTxSignalTerrainAttenuationEnabled::documentation() const { return Documentation; }

    const std::vector<std::string>& IsTxSignalTerrainAttenuationEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsTxSignalTerrainAttenuationEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
