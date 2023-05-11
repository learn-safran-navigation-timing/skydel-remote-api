#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the filter for configuration broadcast.
    ///
    /// 
    ///

    class GetConfigBroadcastFilter;
    typedef std::shared_ptr<GetConfigBroadcastFilter> GetConfigBroadcastFilterPtr;
    
    
    class GetConfigBroadcastFilter : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetConfigBroadcastFilter();

      static GetConfigBroadcastFilterPtr create();
      static GetConfigBroadcastFilterPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

