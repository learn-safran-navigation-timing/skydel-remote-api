#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Tells if raw data logging is enabled.
    ///
    /// 
    ///

    class IsLogRawEnabled;
    typedef std::shared_ptr<IsLogRawEnabled> IsLogRawEnabledPtr;
    
    
    class IsLogRawEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsLogRawEnabled();

      static IsLogRawEnabledPtr create();
      static IsLogRawEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

