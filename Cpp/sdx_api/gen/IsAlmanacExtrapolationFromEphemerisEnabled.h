#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get state of almanac extrapolation from ephemeris in Dynamic SV data.
    ///
    /// 
    ///

    class IsAlmanacExtrapolationFromEphemerisEnabled;
    typedef std::shared_ptr<IsAlmanacExtrapolationFromEphemerisEnabled> IsAlmanacExtrapolationFromEphemerisEnabledPtr;
    
    
    class IsAlmanacExtrapolationFromEphemerisEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsAlmanacExtrapolationFromEphemerisEnabled();

      static IsAlmanacExtrapolationFromEphemerisEnabledPtr create();
      static IsAlmanacExtrapolationFromEphemerisEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

