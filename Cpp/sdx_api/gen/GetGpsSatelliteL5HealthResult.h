#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsSatelliteL5Health.
    ///
    /// Name   Type Description
    /// ------ ---- --------------------------------------------------------------
    /// Prn    int  Satellite PRN number 1..32
    /// Health bool L5 health, false = signal OK, true = signal bad or unavailable
    ///

    class GetGpsSatelliteL5HealthResult;
    typedef std::shared_ptr<GetGpsSatelliteL5HealthResult> GetGpsSatelliteL5HealthResultPtr;
    
    
    class GetGpsSatelliteL5HealthResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsSatelliteL5HealthResult();

      GetGpsSatelliteL5HealthResult(CommandBasePtr relatedCommand, int prn, bool health);
  
      static GetGpsSatelliteL5HealthResultPtr create(CommandBasePtr relatedCommand, int prn, bool health);
      static GetGpsSatelliteL5HealthResultPtr dynamicCast(CommandBasePtr ptr);
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

