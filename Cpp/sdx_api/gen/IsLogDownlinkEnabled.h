#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Tells if downlink data Logging is enabled
    ///
    /// 
    ///

    class IsLogDownlinkEnabled;
    typedef std::shared_ptr<IsLogDownlinkEnabled> IsLogDownlinkEnabledPtr;
    
    
    class IsLogDownlinkEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsLogDownlinkEnabled();

      static IsLogDownlinkEnabledPtr create();
      static IsLogDownlinkEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

