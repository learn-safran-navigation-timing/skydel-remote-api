#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsSatelliteL1cHealth.
    ///
    /// Name   Type Description
    /// ------ ---- ---------------------------------------------------------------
    /// Prn    int  Satellite PRN number 1..32
    /// Health bool L1C health, false = signal OK, true = signal bad or unavailable
    ///

    class GetGpsSatelliteL1cHealthResult;
    typedef std::shared_ptr<GetGpsSatelliteL1cHealthResult> GetGpsSatelliteL1cHealthResultPtr;
    
    
    class GetGpsSatelliteL1cHealthResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsSatelliteL1cHealthResult();

      GetGpsSatelliteL1cHealthResult(CommandBasePtr relatedCommand, int prn, bool health);
  
      static GetGpsSatelliteL1cHealthResultPtr create(CommandBasePtr relatedCommand, int prn, bool health);
      static GetGpsSatelliteL1cHealthResultPtr dynamicCast(CommandBasePtr ptr);
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

