#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get Skydel version.
    ///
    /// 
    ///

    class GetVersion;
    typedef std::shared_ptr<GetVersion> GetVersionPtr;
    
    
    class GetVersion : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetVersion();

      static GetVersionPtr create();
      static GetVersionPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

