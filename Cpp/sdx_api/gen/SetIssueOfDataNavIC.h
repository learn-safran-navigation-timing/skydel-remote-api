#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set NavIC Issue of data, Ephemeris and Clock (IODEC)
    ///
    /// Name              Type          Description
    /// ----------------- ------------- -------------------------------------------------------
    /// EphemerisAndClock int           Issue of data, ephemeris and clock
    /// OverrideRinex     optional bool If the IODEC overrides the RINEX IODEC, default is True
    ///

    class SetIssueOfDataNavIC;
    typedef std::shared_ptr<SetIssueOfDataNavIC> SetIssueOfDataNavICPtr;
    
    
    class SetIssueOfDataNavIC : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetIssueOfDataNavIC();

      SetIssueOfDataNavIC(int ephemerisAndClock, const Sdx::optional<bool>& overrideRinex = {});

      static SetIssueOfDataNavICPtr create(int ephemerisAndClock, const Sdx::optional<bool>& overrideRinex = {});
      static SetIssueOfDataNavICPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** ephemerisAndClock ****
      int ephemerisAndClock() const;
      void setEphemerisAndClock(int ephemerisAndClock);


      // **** overrideRinex ****
      Sdx::optional<bool> overrideRinex() const;
      void setOverrideRinex(const Sdx::optional<bool>& overrideRinex);
    };
    
  }
}

