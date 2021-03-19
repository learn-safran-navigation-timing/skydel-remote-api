#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsSVConfiguration
    ///
    /// Name     Type Description
    /// -------- ---- --------------------------
    /// Prn      int  Satellite PRN number 1..32
    /// SvConfig int  SV Config 0..4
    ///

    class GetGpsSVConfigurationResult;
    typedef std::shared_ptr<GetGpsSVConfigurationResult> GetGpsSVConfigurationResultPtr;
    
    
    class GetGpsSVConfigurationResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsSVConfigurationResult();

      GetGpsSVConfigurationResult(CommandBasePtr relatedCommand, int prn, int svConfig);
  
      static GetGpsSVConfigurationResultPtr create(CommandBasePtr relatedCommand, int prn, int svConfig);
      static GetGpsSVConfigurationResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** svConfig ****
      int svConfig() const;
      void setSvConfig(int svConfig);
    };
  }
}

