
#include "GetTxSignalTerrainAttenuationRate.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetTxSignalTerrainAttenuationRate
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetTxSignalTerrainAttenuationRate::CmdName = "GetTxSignalTerrainAttenuationRate";
    const char* const GetTxSignalTerrainAttenuationRate::Documentation = "Get the rate (in Hz) at which terrain-based attenuation of interference and spoofing signals is recalculated.";
    const char* const GetTxSignalTerrainAttenuationRate::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetTxSignalTerrainAttenuationRate);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetTxSignalTerrainAttenuationRate);


    GetTxSignalTerrainAttenuationRate::GetTxSignalTerrainAttenuationRate()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetTxSignalTerrainAttenuationRatePtr GetTxSignalTerrainAttenuationRate::create()
    {
      return std::make_shared<GetTxSignalTerrainAttenuationRate>();
    }

    GetTxSignalTerrainAttenuationRatePtr GetTxSignalTerrainAttenuationRate::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetTxSignalTerrainAttenuationRate>(ptr);
    }

    bool GetTxSignalTerrainAttenuationRate::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetTxSignalTerrainAttenuationRate::documentation() const { return Documentation; }

    const std::vector<std::string>& GetTxSignalTerrainAttenuationRate::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetTxSignalTerrainAttenuationRate::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
