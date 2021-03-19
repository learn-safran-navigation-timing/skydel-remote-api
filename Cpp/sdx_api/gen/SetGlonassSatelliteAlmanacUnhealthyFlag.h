#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GlonassSatelliteAlmanacUnhealthyFlag is deprecated since 21.3. You may use GlonassAlmanacUnhealthyFlagForSV.
    /// 
    /// Set GLONASS satellite Almanac Unhealthy Flag Cn
    ///
    /// Name   Type Description
    /// ------ ---- ----------------------------------------------------------
    /// Prn    int  Satellite PRN number 1..24
    /// Health bool Status, false = Non-operability, true = Operability (Good)
    ///

    class SetGlonassSatelliteAlmanacUnhealthyFlag;
    typedef std::shared_ptr<SetGlonassSatelliteAlmanacUnhealthyFlag> SetGlonassSatelliteAlmanacUnhealthyFlagPtr;
    
    
    class SetGlonassSatelliteAlmanacUnhealthyFlag : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGlonassSatelliteAlmanacUnhealthyFlag();

      SetGlonassSatelliteAlmanacUnhealthyFlag(int prn, bool health);
  
      static SetGlonassSatelliteAlmanacUnhealthyFlagPtr create(int prn, bool health);
      static SetGlonassSatelliteAlmanacUnhealthyFlagPtr dynamicCast(CommandBasePtr ptr);
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

