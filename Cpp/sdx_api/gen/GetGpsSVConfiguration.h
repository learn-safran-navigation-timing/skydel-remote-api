#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetGpsSVConfiguration is deprecated since 21.3. You may use GetGpsConfigurationCodeForSV.
    /// 
    /// Get GPS SV configuration flag for one PRN
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..32
    ///

    class GetGpsSVConfiguration;
    typedef std::shared_ptr<GetGpsSVConfiguration> GetGpsSVConfigurationPtr;
    
    
    class GetGpsSVConfiguration : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsSVConfiguration();

      GetGpsSVConfiguration(int prn);
  
      static GetGpsSVConfigurationPtr create(int prn);
      static GetGpsSVConfigurationPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

