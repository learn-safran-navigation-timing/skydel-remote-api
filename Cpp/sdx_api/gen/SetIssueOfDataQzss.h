#pragma once

#include <memory>
#include "command_base.h"

#include <optional>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set QZSS Issue of data, Ephemeris (IODE) and Issue of data, Clock (IODC)
    ///
    /// Name          Type          Description
    /// ------------- ------------- ---------------------------------------------------
    /// Clock         int           Issue of data, clock
    /// Ephemeris     int           Issue of data, ephemeris
    /// OverrideRinex optional bool If the IOD overrides the RINEX IOD, default is True
    ///

    class SetIssueOfDataQzss;
    typedef std::shared_ptr<SetIssueOfDataQzss> SetIssueOfDataQzssPtr;
    
    
    class SetIssueOfDataQzss : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetIssueOfDataQzss();

      SetIssueOfDataQzss(int clock, int ephemeris, const std::optional<bool>& overrideRinex = {});

      static SetIssueOfDataQzssPtr create(int clock, int ephemeris, const std::optional<bool>& overrideRinex = {});
      static SetIssueOfDataQzssPtr dynamicCast(CommandBasePtr ptr);
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
      std::optional<bool> overrideRinex() const;
      void setOverrideRinex(const std::optional<bool>& overrideRinex);
    };
    
  }
}

