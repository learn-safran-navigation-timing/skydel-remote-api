#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set current configuration as default configuration.
    ///
    /// 
    ///

    class SetDefaultConfiguration;
    typedef std::shared_ptr<SetDefaultConfiguration> SetDefaultConfigurationPtr;
    
    
    class SetDefaultConfiguration : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetDefaultConfiguration();

      static SetDefaultConfigurationPtr create();
      static SetDefaultConfigurationPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

