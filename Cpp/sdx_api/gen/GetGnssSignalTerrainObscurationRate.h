#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the rate (in Hz) at which line-of-sight between the receiver and satellites is evaluated for terrain obscuration.
    ///
    /// 
    ///

    class GetGnssSignalTerrainObscurationRate;
    typedef std::shared_ptr<GetGnssSignalTerrainObscurationRate> GetGnssSignalTerrainObscurationRatePtr;
    
    
    class GetGnssSignalTerrainObscurationRate : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetGnssSignalTerrainObscurationRate();

      static GetGnssSignalTerrainObscurationRatePtr create();
      static GetGnssSignalTerrainObscurationRatePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

