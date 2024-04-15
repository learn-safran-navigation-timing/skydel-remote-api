#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable (or disable) extrapolation of the almanac from the ephemeris in Dynamic SV Data mode.
    /// When disabled, use PushDynamicAlmanacData to push the almanac data
    ///
    /// Name    Type Description
    /// ------- ---- -------------------------------
    /// Enabled bool State of almanac extrapolation.
    ///

    class EnableAlmanacExtrapolationFromEphemeris;
    typedef std::shared_ptr<EnableAlmanacExtrapolationFromEphemeris> EnableAlmanacExtrapolationFromEphemerisPtr;
    
    
    class EnableAlmanacExtrapolationFromEphemeris : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EnableAlmanacExtrapolationFromEphemeris();

      EnableAlmanacExtrapolationFromEphemeris(bool enabled);

      static EnableAlmanacExtrapolationFromEphemerisPtr create(bool enabled);
      static EnableAlmanacExtrapolationFromEphemerisPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

