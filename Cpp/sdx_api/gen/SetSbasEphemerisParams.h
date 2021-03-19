#pragma once

#include <memory>
#include "command_base.h"
#include "gen/StringPair.h"
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetSbasEphemerisParams is deprecated since 21.3. You may use SetSbasEphParamForSV.
    /// 
    /// Set parameters for a SBAS satellite ephemeris (runtime modification only available for health parameter)
    ///
    /// Name       Type             Description
    /// ---------- ---------------- -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Prn        int              The satellite's PRN
    /// Parameters array StringPair A list of pair of strings. The first will be the key and has to be from this list: "ClockBias", "RelativeFrequencyBias", "X", "Y", "Z", "VelocityX", "VelocityY", "VelocityZ", "AccelerationX", "AccelerationY", "AccelerationZ", "Health", "URA". The Second argument will be the corresponding value.
    ///

    class SetSbasEphemerisParams;
    typedef std::shared_ptr<SetSbasEphemerisParams> SetSbasEphemerisParamsPtr;
    
    
    class SetSbasEphemerisParams : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSbasEphemerisParams();

      SetSbasEphemerisParams(int prn, const std::vector<Sdx::StringPair>& parameters);
  
      static SetSbasEphemerisParamsPtr create(int prn, const std::vector<Sdx::StringPair>& parameters);
      static SetSbasEphemerisParamsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** parameters ****
      std::vector<Sdx::StringPair> parameters() const;
      void setParameters(const std::vector<Sdx::StringPair>& parameters);
    };
  }
}

