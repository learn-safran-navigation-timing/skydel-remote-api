#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGnssSignalTerrainObscurationRate.
    ///
    /// Name Type Description
    /// ---- ---- -----------------------------------------------------------------------------------------------------------------------------------------------------
    /// Rate int  Rate at which line-of-sight between the receiver and satellites is evaluated. Accepted values are: 1 Hz, 5 Hz, 10 Hz, 20 Hz, 25 Hz, 40 Hz, and 50 Hz.
    ///

    class GetGnssSignalTerrainObscurationRateResult;
    typedef std::shared_ptr<GetGnssSignalTerrainObscurationRateResult> GetGnssSignalTerrainObscurationRateResultPtr;
    
    
    class GetGnssSignalTerrainObscurationRateResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetGnssSignalTerrainObscurationRateResult();

      GetGnssSignalTerrainObscurationRateResult(int rate);

      GetGnssSignalTerrainObscurationRateResult(CommandBasePtr relatedCommand, int rate);

      static GetGnssSignalTerrainObscurationRateResultPtr create(int rate);

      static GetGnssSignalTerrainObscurationRateResultPtr create(CommandBasePtr relatedCommand, int rate);
      static GetGnssSignalTerrainObscurationRateResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** rate ****
      int rate() const;
      void setRate(int rate);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetGnssSignalTerrainObscurationRateResult);
  }
}

