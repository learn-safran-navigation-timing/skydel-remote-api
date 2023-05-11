#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set GPS Issue of data, Ephemeris (IODE) and Issue of data, Clock (IODC)
    ///
    /// Name          Type          Description
    /// ------------- ------------- ---------------------------------------------------
    /// Clock         int           Issue of data, clock
    /// Ephemeris     int           Issue of data, ephemeris
    /// OverrideRinex optional bool If the IOD overrides the RINEX IOD, default is True
    ///

    class SetIssueOfData;
    typedef std::shared_ptr<SetIssueOfData> SetIssueOfDataPtr;
    
    
    class SetIssueOfData : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetIssueOfData();

      SetIssueOfData(int clock, int ephemeris, const Sdx::optional<bool>& overrideRinex = {});

      static SetIssueOfDataPtr create(int clock, int ephemeris, const Sdx::optional<bool>& overrideRinex = {});
      static SetIssueOfDataPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

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

