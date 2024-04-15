#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the config file path currently used by Skydel.
    ///
    /// 
    ///

    class GetCurrentConfigPath;
    typedef std::shared_ptr<GetCurrentConfigPath> GetCurrentConfigPathPtr;
    
    
    class GetCurrentConfigPath : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetCurrentConfigPath();

      static GetCurrentConfigPathPtr create();
      static GetCurrentConfigPathPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

