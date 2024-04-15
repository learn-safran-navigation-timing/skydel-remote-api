#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the ephemeris update interval in seconds.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------
    /// System string "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
    ///

    class GetEphemerisUpdateInterval;
    typedef std::shared_ptr<GetEphemerisUpdateInterval> GetEphemerisUpdateIntervalPtr;
    
    
    class GetEphemerisUpdateInterval : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetEphemerisUpdateInterval();

      GetEphemerisUpdateInterval(const std::string& system);

      static GetEphemerisUpdateIntervalPtr create(const std::string& system);
      static GetEphemerisUpdateIntervalPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
    
  }
}

