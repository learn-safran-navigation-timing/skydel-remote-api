#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <optional>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetIssueOfDataNavIC.
    ///
    /// Name              Type          Description
    /// ----------------- ------------- -------------------------------------------------------
    /// EphemerisAndClock int           Issue of data, ephemeris and clock
    /// OverrideRinex     optional bool If the IODEC overrides the RINEX IODEC, default is True
    ///

    class GetIssueOfDataNavICResult;
    typedef std::shared_ptr<GetIssueOfDataNavICResult> GetIssueOfDataNavICResultPtr;
    
    
    class GetIssueOfDataNavICResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetIssueOfDataNavICResult();

      GetIssueOfDataNavICResult(int ephemerisAndClock, const std::optional<bool>& overrideRinex = {});

      GetIssueOfDataNavICResult(CommandBasePtr relatedCommand, int ephemerisAndClock, const std::optional<bool>& overrideRinex = {});

      static GetIssueOfDataNavICResultPtr create(int ephemerisAndClock, const std::optional<bool>& overrideRinex = {});

      static GetIssueOfDataNavICResultPtr create(CommandBasePtr relatedCommand, int ephemerisAndClock, const std::optional<bool>& overrideRinex = {});
      static GetIssueOfDataNavICResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** ephemerisAndClock ****
      int ephemerisAndClock() const;
      void setEphemerisAndClock(int ephemerisAndClock);


      // **** overrideRinex ****
      std::optional<bool> overrideRinex() const;
      void setOverrideRinex(const std::optional<bool>& overrideRinex);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetIssueOfDataNavICResult);
  }
}

