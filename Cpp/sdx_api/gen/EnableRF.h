#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command EnableRF is deprecated since 21.3. You may use EnableRFOutputForSV.
    /// 
    /// Enable (or disable) RF output for specified satellite PRN. Use PRN 0 to enabled/disable all satellites.
    ///
    /// Name    Type   Description
    /// ------- ------ ----------------------------------------------------------------------------------------------------------
    /// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Prn     int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS. SV ID for QZSS and NavIC.
    /// Enabled bool   RF is enabled when value is True
    ///

    class EnableRF;
    typedef std::shared_ptr<EnableRF> EnableRFPtr;
    
    
    class EnableRF : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnableRF();

      EnableRF(const std::string& system, int prn, bool enabled);
  
      static EnableRFPtr create(const std::string& system, int prn, bool enabled);
      static EnableRFPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
  }
}

