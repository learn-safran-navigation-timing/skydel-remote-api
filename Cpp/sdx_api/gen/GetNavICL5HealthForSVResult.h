#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetNavICL5HealthForSV
    ///
    /// Name   Type Description
    /// ------ ---- -----------------------------------------------
    /// SvId   int  Satellite SV ID 1..14
    /// Health bool L5 health, false = signal OK, true = signal bad
    ///

    class GetNavICL5HealthForSVResult;
    typedef std::shared_ptr<GetNavICL5HealthForSVResult> GetNavICL5HealthForSVResultPtr;
    typedef GetNavICL5HealthForSVResult GetNavICSatelliteL5HealthResult;
    typedef std::shared_ptr<GetNavICSatelliteL5HealthResult> GetNavICSatelliteL5HealthResultPtr;
    
    class GetNavICL5HealthForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetNavICL5HealthForSVResult();

      GetNavICL5HealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health);
  
      static GetNavICL5HealthForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool health);
      static GetNavICL5HealthForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      bool health() const;
      void setHealth(bool health);
    };
  }
}

