#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the rate (in Hz) at which line-of-sight between the receiver and satellites is evaluated for terrain obscuration.
    ///
    /// Name Type Description
    /// ---- ---- -----------------------------------------------------------------------------------------------------------------------------------------------------
    /// Rate int  Rate at which line-of-sight between the receiver and satellites is evaluated. Accepted values are: 1 Hz, 5 Hz, 10 Hz, 20 Hz, 25 Hz, 40 Hz, and 50 Hz.
    ///

    class SetGnssSignalTerrainObscurationRate;
    typedef std::shared_ptr<SetGnssSignalTerrainObscurationRate> SetGnssSignalTerrainObscurationRatePtr;
    
    
    class SetGnssSignalTerrainObscurationRate : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetGnssSignalTerrainObscurationRate();

      SetGnssSignalTerrainObscurationRate(int rate);

      static SetGnssSignalTerrainObscurationRatePtr create(int rate);
      static SetGnssSignalTerrainObscurationRatePtr dynamicCast(CommandBasePtr ptr);
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

