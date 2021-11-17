#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsL2HealthForSV.
    ///
    /// Name   Type Description
    /// ------ ---- --------------------------------------------------------------
    /// SvId   int  Satellite's SV ID 1..32
    /// Health bool L2 health, false = signal OK, true = signal bad or unavailable
    ///

    class GetGpsL2HealthForSVResult;
    typedef std::shared_ptr<GetGpsL2HealthForSVResult> GetGpsL2HealthForSVResultPtr;
    
    
    class GetGpsL2HealthForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsL2HealthForSVResult();

      GetGpsL2HealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health);
  
      static GetGpsL2HealthForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool health);
      static GetGpsL2HealthForSVResultPtr dynamicCast(CommandBasePtr ptr);
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

