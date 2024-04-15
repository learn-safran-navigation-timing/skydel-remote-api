#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get a list of paths for all the files in the Configurations folder.
    ///
    /// 
    ///

    class GetConfigPaths;
    typedef std::shared_ptr<GetConfigPaths> GetConfigPathsPtr;
    
    
    class GetConfigPaths : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetConfigPaths();

      static GetConfigPathsPtr create();
      static GetConfigPathsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

