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
    /// Tells if the RF is enabled or disabled for the specified satellite.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Prn    int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS. SV ID for QZSS and NavIC.
    ///

    class IsRFEnabled;
    typedef std::shared_ptr<IsRFEnabled> IsRFEnabledPtr;
    
    
    class IsRFEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsRFEnabled();

      IsRFEnabled(const std::string& system, int prn);
  
      static IsRFEnabledPtr create(const std::string& system, int prn);
      static IsRFEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

