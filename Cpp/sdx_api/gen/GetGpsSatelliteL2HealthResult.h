#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsSatelliteL2Health
    ///
    /// Name   Type Description
    /// ------ ---- --------------------------------------------------------------
    /// Prn    int  Satellite PRN number 1..32
    /// Health bool L2 health, false = signal OK, true = signal bad or unavailable
    ///

    class GetGpsSatelliteL2HealthResult;
    typedef std::shared_ptr<GetGpsSatelliteL2HealthResult> GetGpsSatelliteL2HealthResultPtr;
    
    
    class GetGpsSatelliteL2HealthResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsSatelliteL2HealthResult();

      GetGpsSatelliteL2HealthResult(CommandBasePtr relatedCommand, int prn, bool health);
  
      static GetGpsSatelliteL2HealthResultPtr create(CommandBasePtr relatedCommand, int prn, bool health);
      static GetGpsSatelliteL2HealthResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** health ****
      bool health() const;
      void setHealth(bool health);
    };
  }
}

