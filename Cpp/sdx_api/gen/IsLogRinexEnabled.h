#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Tells if ephemeris data Logging is enabled
    ///
    /// 
    ///

    class IsLogRinexEnabled;
    typedef std::shared_ptr<IsLogRinexEnabled> IsLogRinexEnabledPtr;
    
    
    class IsLogRinexEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsLogRinexEnabled();

      static IsLogRinexEnabledPtr create();
      static IsLogRinexEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

