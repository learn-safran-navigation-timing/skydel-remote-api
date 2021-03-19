#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetQzssL1HealthForSV
    ///
    /// Name   Type Description
    /// ------ ---- -----------------------------------------------
    /// SvId   int  Satellite SV ID 1..10
    /// Health bool L1 health, false = signal OK, true = signal bad
    ///

    class GetQzssL1HealthForSVResult;
    typedef std::shared_ptr<GetQzssL1HealthForSVResult> GetQzssL1HealthForSVResultPtr;
    typedef GetQzssL1HealthForSVResult GetQzssSatelliteL1HealthResult;
    typedef std::shared_ptr<GetQzssSatelliteL1HealthResult> GetQzssSatelliteL1HealthResultPtr;
    
    class GetQzssL1HealthForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssL1HealthForSVResult();

      GetQzssL1HealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health);
  
      static GetQzssL1HealthForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool health);
      static GetQzssL1HealthForSVResultPtr dynamicCast(CommandBasePtr ptr);
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

