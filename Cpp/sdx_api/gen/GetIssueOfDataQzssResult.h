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
    /// Result of GetIssueOfDataQzss.
    ///
    /// Name          Type          Description
    /// ------------- ------------- ---------------------------------------------------
    /// Clock         int           Issue of data, clock
    /// Ephemeris     int           Issue of data, ephemeris
    /// OverrideRinex optional bool If the IOD overrides the RINEX IOD, default is True
    ///

    class GetIssueOfDataQzssResult;
    typedef std::shared_ptr<GetIssueOfDataQzssResult> GetIssueOfDataQzssResultPtr;
    
    
    class GetIssueOfDataQzssResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetIssueOfDataQzssResult();

      GetIssueOfDataQzssResult(int clock, int ephemeris, const std::optional<bool>& overrideRinex = {});

      GetIssueOfDataQzssResult(CommandBasePtr relatedCommand, int clock, int ephemeris, const std::optional<bool>& overrideRinex = {});

      static GetIssueOfDataQzssResultPtr create(int clock, int ephemeris, const std::optional<bool>& overrideRinex = {});

      static GetIssueOfDataQzssResultPtr create(CommandBasePtr relatedCommand, int clock, int ephemeris, const std::optional<bool>& overrideRinex = {});
      static GetIssueOfDataQzssResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** clock ****
      int clock() const;
      void setClock(int clock);


      // **** ephemeris ****
      int ephemeris() const;
      void setEphemeris(int ephemeris);


      // **** overrideRinex ****
      std::optional<bool> overrideRinex() const;
      void setOverrideRinex(const std::optional<bool>& overrideRinex);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetIssueOfDataQzssResult);
  }
}

