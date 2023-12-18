#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the ephemeris update interval in seconds.
    ///
    /// Name     Type   Description
    /// -------- ------ -----------------------------------------------------------------------------------------------------------------------
    /// System   string "GPS", "Galileo", "BeiDou", "QZSS" or "NavIC"
    /// Interval int    Interval duration in sec. Accepted range is [1..604800]. Must be a divider of the number of seconds in a week (604800).
    ///

    class SetEphemerisUpdateInterval;
    typedef std::shared_ptr<SetEphemerisUpdateInterval> SetEphemerisUpdateIntervalPtr;
    
    
    class SetEphemerisUpdateInterval : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetEphemerisUpdateInterval();

      SetEphemerisUpdateInterval(const std::string& system, int interval);

      static SetEphemerisUpdateIntervalPtr create(const std::string& system, int interval);
      static SetEphemerisUpdateIntervalPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** interval ****
      int interval() const;
      void setInterval(int interval);
    };
    
  }
}

