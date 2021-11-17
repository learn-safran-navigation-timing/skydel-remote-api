#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsL5HealthForSV.
    ///
    /// Name   Type Description
    /// ------ ---- --------------------------------------------------------------
    /// SvId   int  Satellite's SV ID 1..32
    /// Health bool L5 health, false = signal OK, true = signal bad or unavailable
    ///

    class GetGpsL5HealthForSVResult;
    typedef std::shared_ptr<GetGpsL5HealthForSVResult> GetGpsL5HealthForSVResultPtr;
    
    
    class GetGpsL5HealthForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsL5HealthForSVResult();

      GetGpsL5HealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health);
  
      static GetGpsL5HealthForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool health);
      static GetGpsL5HealthForSVResultPtr dynamicCast(CommandBasePtr ptr);
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

