#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsConfigurationCodeForSV.
    ///
    /// Name     Type Description
    /// -------- ---- ---------------------
    /// SvId     int  Satellite SV ID 1..32
    /// SvConfig int  SV Config 0..4
    ///

    class GetGpsConfigurationCodeForSVResult;
    typedef std::shared_ptr<GetGpsConfigurationCodeForSVResult> GetGpsConfigurationCodeForSVResultPtr;
    
    
    class GetGpsConfigurationCodeForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsConfigurationCodeForSVResult();

      GetGpsConfigurationCodeForSVResult(CommandBasePtr relatedCommand, int svId, int svConfig);
  
      static GetGpsConfigurationCodeForSVResultPtr create(CommandBasePtr relatedCommand, int svId, int svConfig);
      static GetGpsConfigurationCodeForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** svConfig ****
      int svConfig() const;
      void setSvConfig(int svConfig);
    };
  }
}

