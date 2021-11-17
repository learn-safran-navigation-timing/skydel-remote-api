#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetQzssL1DataHealthForSV.
    ///
    /// Name   Type Description
    /// ------ ---- ---------------------
    /// SvId   int  Satellite SV ID 1..10
    /// Health int  Data health 0..7
    ///

    class GetQzssL1DataHealthForSVResult;
    typedef std::shared_ptr<GetQzssL1DataHealthForSVResult> GetQzssL1DataHealthForSVResultPtr;
    typedef GetQzssL1DataHealthForSVResult GetQzssSatelliteL1DataHealthResult;
    typedef std::shared_ptr<GetQzssSatelliteL1DataHealthResult> GetQzssSatelliteL1DataHealthResultPtr;
    
    class GetQzssL1DataHealthForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssL1DataHealthForSVResult();

      GetQzssL1DataHealthForSVResult(CommandBasePtr relatedCommand, int svId, int health);
  
      static GetQzssL1DataHealthForSVResultPtr create(CommandBasePtr relatedCommand, int svId, int health);
      static GetQzssL1DataHealthForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      int health() const;
      void setHealth(int health);
    };
  }
}

