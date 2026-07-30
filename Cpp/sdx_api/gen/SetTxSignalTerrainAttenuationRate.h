#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the rate (in Hz) at which terrain-based attenuation of interference and spoofing signals is recalculated.
    ///
    /// Name Type Description
    /// ---- ---- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Rate int  Rate at which terrain-based attenuation of interference and spoofing signals is recalculated. Accepted values are: 1 Hz, 5 Hz, 10 Hz, 20 Hz, 25 Hz, 40 Hz, and 50 Hz.
    ///

    class SetTxSignalTerrainAttenuationRate;
    typedef std::shared_ptr<SetTxSignalTerrainAttenuationRate> SetTxSignalTerrainAttenuationRatePtr;
    
    
    class SetTxSignalTerrainAttenuationRate : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetTxSignalTerrainAttenuationRate();

      SetTxSignalTerrainAttenuationRate(int rate);

      static SetTxSignalTerrainAttenuationRatePtr create(int rate);
      static SetTxSignalTerrainAttenuationRatePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** rate ****
      int rate() const;
      void setRate(int rate);
    };
    
  }
}

