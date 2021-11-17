#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetGlonassSatelliteEphemerisHealthFlag is deprecated since 21.3. You may use SetGlonassEphemerisHealthFlagForSV.
    /// 
    /// Set GLONASS satellite Ephemeris Health Flag Bn(ln)
    ///
    /// Name   Type Description
    /// ------ ---- --------------------------------------
    /// Prn    int  Satellite PRN number 1..24
    /// Health bool Status, false = OK, true = Malfunction
    ///

    class SetGlonassSatelliteEphemerisHealthFlag;
    typedef std::shared_ptr<SetGlonassSatelliteEphemerisHealthFlag> SetGlonassSatelliteEphemerisHealthFlagPtr;
    
    
    class SetGlonassSatelliteEphemerisHealthFlag : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGlonassSatelliteEphemerisHealthFlag();

      SetGlonassSatelliteEphemerisHealthFlag(int prn, bool health);
  
      static SetGlonassSatelliteEphemerisHealthFlagPtr create(int prn, bool health);
      static SetGlonassSatelliteEphemerisHealthFlagPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** health ****
      bool health() const;
      void setHealth(bool health);
    };
  }
}

