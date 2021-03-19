#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get GPS SV configuration flag for one satellite
    ///
    /// Name Type Description
    /// ---- ---- ---------------------
    /// SvId int  Satellite SV ID 1..32
    ///

    class GetGpsConfigurationCodeForSV;
    typedef std::shared_ptr<GetGpsConfigurationCodeForSV> GetGpsConfigurationCodeForSVPtr;
    
    
    class GetGpsConfigurationCodeForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsConfigurationCodeForSV();

      GetGpsConfigurationCodeForSV(int svId);
  
      static GetGpsConfigurationCodeForSVPtr create(int svId);
      static GetGpsConfigurationCodeForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

