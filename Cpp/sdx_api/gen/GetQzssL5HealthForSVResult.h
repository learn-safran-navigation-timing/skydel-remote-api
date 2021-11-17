#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetQzssL5HealthForSV.
    ///
    /// Name   Type Description
    /// ------ ---- -----------------------------------------------
    /// SvId   int  Satellite SV ID 1..10
    /// Health bool L5 health, false = signal OK, true = signal bad
    ///

    class GetQzssL5HealthForSVResult;
    typedef std::shared_ptr<GetQzssL5HealthForSVResult> GetQzssL5HealthForSVResultPtr;
    typedef GetQzssL5HealthForSVResult GetQzssSatelliteL5HealthResult;
    typedef std::shared_ptr<GetQzssSatelliteL5HealthResult> GetQzssSatelliteL5HealthResultPtr;
    
    class GetQzssL5HealthForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssL5HealthForSVResult();

      GetQzssL5HealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health);
  
      static GetQzssL5HealthForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool health);
      static GetQzssL5HealthForSVResultPtr dynamicCast(CommandBasePtr ptr);
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

