#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GlonassSatelliteEphemerisHealthFlag is deprecated since 21.3. You may use GlonassEphemerisHealthFlagForSV.
    /// 
    /// Get GLONASS satellite Ephemeris Health Flag Bn(ln)
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..24
    ///

    class GetGlonassSatelliteEphemerisHealthFlag;
    typedef std::shared_ptr<GetGlonassSatelliteEphemerisHealthFlag> GetGlonassSatelliteEphemerisHealthFlagPtr;
    
    
    class GetGlonassSatelliteEphemerisHealthFlag : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGlonassSatelliteEphemerisHealthFlag();

      GetGlonassSatelliteEphemerisHealthFlag(int prn);
  
      static GetGlonassSatelliteEphemerisHealthFlagPtr create(int prn);
      static GetGlonassSatelliteEphemerisHealthFlagPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

