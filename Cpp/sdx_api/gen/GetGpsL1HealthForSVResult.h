#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsL1HealthForSV
    ///
    /// Name   Type Description
    /// ------ ---- --------------------------------------------------------------
    /// SvId   int  Satellite's SV ID 1..32
    /// Health bool L1 health, false = signal OK, true = signal bad or unavailable
    ///

    class GetGpsL1HealthForSVResult;
    typedef std::shared_ptr<GetGpsL1HealthForSVResult> GetGpsL1HealthForSVResultPtr;
    
    
    class GetGpsL1HealthForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsL1HealthForSVResult();

      GetGpsL1HealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health);
  
      static GetGpsL1HealthForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool health);
      static GetGpsL1HealthForSVResultPtr dynamicCast(CommandBasePtr ptr);
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

