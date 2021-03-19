#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsSatelliteL1Health
    ///
    /// Name   Type Description
    /// ------ ---- --------------------------------------------------------------
    /// Prn    int  Satellite PRN number 1..32
    /// Health bool L1 health, false = signal OK, true = signal bad or unavailable
    ///

    class GetGpsSatelliteL1HealthResult;
    typedef std::shared_ptr<GetGpsSatelliteL1HealthResult> GetGpsSatelliteL1HealthResultPtr;
    
    
    class GetGpsSatelliteL1HealthResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsSatelliteL1HealthResult();

      GetGpsSatelliteL1HealthResult(CommandBasePtr relatedCommand, int prn, bool health);
  
      static GetGpsSatelliteL1HealthResultPtr create(CommandBasePtr relatedCommand, int prn, bool health);
      static GetGpsSatelliteL1HealthResultPtr dynamicCast(CommandBasePtr ptr);
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

