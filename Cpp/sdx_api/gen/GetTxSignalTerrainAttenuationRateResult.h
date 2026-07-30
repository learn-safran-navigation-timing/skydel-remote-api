#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetTxSignalTerrainAttenuationRate.
    ///
    /// Name Type Description
    /// ---- ---- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Rate int  Rate at which terrain-based attenuation of interference and spoofing signals is recalculated. Accepted values are: 1 Hz, 5 Hz, 10 Hz, 20 Hz, 25 Hz, 40 Hz, and 50 Hz.
    ///

    class GetTxSignalTerrainAttenuationRateResult;
    typedef std::shared_ptr<GetTxSignalTerrainAttenuationRateResult> GetTxSignalTerrainAttenuationRateResultPtr;
    
    
    class GetTxSignalTerrainAttenuationRateResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetTxSignalTerrainAttenuationRateResult();

      GetTxSignalTerrainAttenuationRateResult(int rate);

      GetTxSignalTerrainAttenuationRateResult(CommandBasePtr relatedCommand, int rate);

      static GetTxSignalTerrainAttenuationRateResultPtr create(int rate);

      static GetTxSignalTerrainAttenuationRateResultPtr create(CommandBasePtr relatedCommand, int rate);
      static GetTxSignalTerrainAttenuationRateResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** rate ****
      int rate() const;
      void setRate(int rate);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetTxSignalTerrainAttenuationRateResult);
  }
}

