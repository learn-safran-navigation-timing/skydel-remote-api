#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Reset the default configuration.
    ///
    /// 
    ///

    class ResetDefaultConfiguration;
    typedef std::shared_ptr<ResetDefaultConfiguration> ResetDefaultConfigurationPtr;
    
    
    class ResetDefaultConfiguration : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      ResetDefaultConfiguration();

      static ResetDefaultConfigurationPtr create();
      static ResetDefaultConfigurationPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

