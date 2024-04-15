#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set BeiDou Age of data, Ephemeris (AODE) and Age of data, Clock (AODC)
    ///
    /// Name          Type          Description
    /// ------------- ------------- ---------------------------------------------------
    /// Clock         int           Age of data, clock
    /// Ephemeris     int           Age of data, ephemeris
    /// OverrideRinex optional bool If the AOD overrides the RINEX AOD, default is True
    ///

    class SetAgeOfDataBeiDou;
    typedef std::shared_ptr<SetAgeOfDataBeiDou> SetAgeOfDataBeiDouPtr;
    
    
    class SetAgeOfDataBeiDou : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetAgeOfDataBeiDou();

      SetAgeOfDataBeiDou(int clock, int ephemeris, const Sdx::optional<bool>& overrideRinex = {});

      static SetAgeOfDataBeiDouPtr create(int clock, int ephemeris, const Sdx::optional<bool>& overrideRinex = {});
      static SetAgeOfDataBeiDouPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


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
    
  }
}

