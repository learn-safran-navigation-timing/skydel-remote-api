#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the rate (in Hz) at which terrain-based attenuation of interference and spoofing signals is recalculated.
    ///
    /// 
    ///

    class GetTxSignalTerrainAttenuationRate;
    typedef std::shared_ptr<GetTxSignalTerrainAttenuationRate> GetTxSignalTerrainAttenuationRatePtr;
    
    
    class GetTxSignalTerrainAttenuationRate : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetTxSignalTerrainAttenuationRate();

      static GetTxSignalTerrainAttenuationRatePtr create();
      static GetTxSignalTerrainAttenuationRatePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

