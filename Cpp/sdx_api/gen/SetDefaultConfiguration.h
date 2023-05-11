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


      SetDefaultConfiguration();

      static SetDefaultConfigurationPtr create();
      static SetDefaultConfigurationPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

