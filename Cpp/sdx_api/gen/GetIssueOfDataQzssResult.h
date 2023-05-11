#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include "sdx_optional.h"

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


      GetIssueOfDataQzssResult();

      GetIssueOfDataQzssResult(int clock, int ephemeris, const Sdx::optional<bool>& overrideRinex = {});

      GetIssueOfDataQzssResult(CommandBasePtr relatedCommand, int clock, int ephemeris, const Sdx::optional<bool>& overrideRinex = {});

      static GetIssueOfDataQzssResultPtr create(int clock, int ephemeris, const Sdx::optional<bool>& overrideRinex = {});

      static GetIssueOfDataQzssResultPtr create(CommandBasePtr relatedCommand, int clock, int ephemeris, const Sdx::optional<bool>& overrideRinex = {});
      static GetIssueOfDataQzssResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** clock ****
      int clock() const;
      void setClock(int clock);


      // **** ephemeris ****
      int ephemeris() const;
      void setEphemeris(int ephemeris);


      // **** overrideRinex ****
      Sdx::optional<bool> overrideRinex() const;
      void setOverrideRinex(const Sdx::optional<bool>& overrideRinex);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetIssueOfDataQzssResult);
  }
}

