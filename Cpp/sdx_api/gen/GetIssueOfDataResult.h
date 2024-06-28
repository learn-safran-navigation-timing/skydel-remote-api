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
    /// Result of GetIssueOfData.
    ///
    /// Name          Type          Description
    /// ------------- ------------- ---------------------------------------------------
    /// Clock         int           Issue of data, clock
    /// Ephemeris     int           Issue of data, ephemeris
    /// OverrideRinex optional bool If the IOD overrides the RINEX IOD, default is True
    ///

    class GetIssueOfDataResult;
    typedef std::shared_ptr<GetIssueOfDataResult> GetIssueOfDataResultPtr;
    
    
    class GetIssueOfDataResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetIssueOfDataResult();

      GetIssueOfDataResult(int clock, int ephemeris, const std::optional<bool>& overrideRinex = {});

      GetIssueOfDataResult(CommandBasePtr relatedCommand, int clock, int ephemeris, const std::optional<bool>& overrideRinex = {});

      static GetIssueOfDataResultPtr create(int clock, int ephemeris, const std::optional<bool>& overrideRinex = {});

      static GetIssueOfDataResultPtr create(CommandBasePtr relatedCommand, int clock, int ephemeris, const std::optional<bool>& overrideRinex = {});
      static GetIssueOfDataResultPtr dynamicCast(CommandBasePtr ptr);
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
    REGISTER_COMMAND_TO_FACTORY_DECL(GetIssueOfDataResult);
  }
}

