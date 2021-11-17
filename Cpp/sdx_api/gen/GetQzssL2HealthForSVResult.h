#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetQzssL2HealthForSV.
    ///
    /// Name   Type Description
    /// ------ ---- -----------------------------------------------
    /// SvId   int  Satellite SV ID 1..10
    /// Health bool L2 health, false = signal OK, true = signal bad
    ///

    class GetQzssL2HealthForSVResult;
    typedef std::shared_ptr<GetQzssL2HealthForSVResult> GetQzssL2HealthForSVResultPtr;
    typedef GetQzssL2HealthForSVResult GetQzssSatelliteL2HealthResult;
    typedef std::shared_ptr<GetQzssSatelliteL2HealthResult> GetQzssSatelliteL2HealthResultPtr;
    
    class GetQzssL2HealthForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssL2HealthForSVResult();

      GetQzssL2HealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health);
  
      static GetQzssL2HealthForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool health);
      static GetQzssL2HealthForSVResultPtr dynamicCast(CommandBasePtr ptr);
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

