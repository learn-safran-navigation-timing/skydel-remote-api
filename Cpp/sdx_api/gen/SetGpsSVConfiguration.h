#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GpsSVConfiguration is deprecated since 21.3. You may use GpsConfigurationCodeForSV.
    /// 
    /// Set GPS SV configuration flag for one PRN
    ///
    /// Name     Type Description
    /// -------- ---- --------------------------
    /// Prn      int  Satellite PRN number 1..32
    /// SvConfig int  SV Config 0..4
    ///

    class SetGpsSVConfiguration;
    typedef std::shared_ptr<SetGpsSVConfiguration> SetGpsSVConfigurationPtr;
    
    
    class SetGpsSVConfiguration : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsSVConfiguration();

      SetGpsSVConfiguration(int prn, int svConfig);
  
      static SetGpsSVConfigurationPtr create(int prn, int svConfig);
      static SetGpsSVConfigurationPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** svConfig ****
      int svConfig() const;
      void setSvConfig(int svConfig);
    };
  }
}

