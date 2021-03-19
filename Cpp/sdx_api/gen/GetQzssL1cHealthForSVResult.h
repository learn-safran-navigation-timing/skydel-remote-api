#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetQzssL1cHealthForSV
    ///
    /// Name   Type Description
    /// ------ ---- ------------------------------------------------
    /// SvId   int  Satellite SV ID 1..10
    /// Health bool L1C health, false = signal OK, true = signal bad
    ///

    class GetQzssL1cHealthForSVResult;
    typedef std::shared_ptr<GetQzssL1cHealthForSVResult> GetQzssL1cHealthForSVResultPtr;
    typedef GetQzssL1cHealthForSVResult GetQzssSatelliteL1cHealthResult;
    typedef std::shared_ptr<GetQzssSatelliteL1cHealthResult> GetQzssSatelliteL1cHealthResultPtr;
    
    class GetQzssL1cHealthForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssL1cHealthForSVResult();

      GetQzssL1cHealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health);
  
      static GetQzssL1cHealthForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool health);
      static GetQzssL1cHealthForSVResultPtr dynamicCast(CommandBasePtr ptr);
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

