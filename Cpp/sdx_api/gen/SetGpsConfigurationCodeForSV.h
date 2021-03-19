#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set GPS SV configuration flag for one satellite
    ///
    /// Name     Type Description
    /// -------- ---- ---------------------
    /// SvId     int  Satellite SV ID 1..32
    /// SvConfig int  SV Config 0..4
    ///

    class SetGpsConfigurationCodeForSV;
    typedef std::shared_ptr<SetGpsConfigurationCodeForSV> SetGpsConfigurationCodeForSVPtr;
    
    
    class SetGpsConfigurationCodeForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsConfigurationCodeForSV();

      SetGpsConfigurationCodeForSV(int svId, int svConfig);
  
      static SetGpsConfigurationCodeForSVPtr create(int svId, int svConfig);
      static SetGpsConfigurationCodeForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** svConfig ****
      int svConfig() const;
      void setSvConfig(int svConfig);
    };
  }
}

