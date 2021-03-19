#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsL1cHealthForSV
    ///
    /// Name   Type Description
    /// ------ ---- ---------------------------------------------------------------
    /// SvId   int  Satellite's SV ID 1..32
    /// Health bool L1C health, false = signal OK, true = signal bad or unavailable
    ///

    class GetGpsL1cHealthForSVResult;
    typedef std::shared_ptr<GetGpsL1cHealthForSVResult> GetGpsL1cHealthForSVResultPtr;
    
    
    class GetGpsL1cHealthForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsL1cHealthForSVResult();

      GetGpsL1cHealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health);
  
      static GetGpsL1cHealthForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool health);
      static GetGpsL1cHealthForSVResultPtr dynamicCast(CommandBasePtr ptr);
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

