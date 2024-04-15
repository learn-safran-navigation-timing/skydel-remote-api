#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "sdx_optional.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetAgeOfDataBeiDou.
    ///
    /// Name          Type          Description
    /// ------------- ------------- ---------------------------------------------------
    /// Clock         int           Age of data, clock
    /// Ephemeris     int           Age of data, ephemeris
    /// OverrideRinex optional bool If the AOD overrides the RINEX AOD, default is True
    ///

    class GetAgeOfDataBeiDouResult;
    typedef std::shared_ptr<GetAgeOfDataBeiDouResult> GetAgeOfDataBeiDouResultPtr;
    
    
    class GetAgeOfDataBeiDouResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetAgeOfDataBeiDouResult();

      GetAgeOfDataBeiDouResult(int clock, int ephemeris, const Sdx::optional<bool>& overrideRinex = {});

      GetAgeOfDataBeiDouResult(CommandBasePtr relatedCommand, int clock, int ephemeris, const Sdx::optional<bool>& overrideRinex = {});

      static GetAgeOfDataBeiDouResultPtr create(int clock, int ephemeris, const Sdx::optional<bool>& overrideRinex = {});

      static GetAgeOfDataBeiDouResultPtr create(CommandBasePtr relatedCommand, int clock, int ephemeris, const Sdx::optional<bool>& overrideRinex = {});
      static GetAgeOfDataBeiDouResultPtr dynamicCast(CommandBasePtr ptr);
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
      Sdx::optional<bool> overrideRinex() const;
      void setOverrideRinex(const Sdx::optional<bool>& overrideRinex);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetAgeOfDataBeiDouResult);
  }
}

