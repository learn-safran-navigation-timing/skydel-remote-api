#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get Logging of NMEA for the simulated position enable/disable.
    /// If a receiver is connected, that NMEA is saved as well.
    ///
    /// 
    ///

    class IsLogNmeaEnabled;
    typedef std::shared_ptr<IsLogNmeaEnabled> IsLogNmeaEnabledPtr;
    
    
    class IsLogNmeaEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsLogNmeaEnabled();

      static IsLogNmeaEnabledPtr create();
      static IsLogNmeaEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

