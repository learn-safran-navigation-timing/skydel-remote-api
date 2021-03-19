#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command EnableLOS is deprecated since 21.3. You may use EnableLosForSV.
    /// 
    /// Get Direct Line Of Sight signal from satellite enabled or disabled. Generally used when only multipaths signal is visible.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------------------------------------------------------
    /// Prn    int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS and SV ID for QZSS and NavIC.
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    ///

    class IsLOSEnabled;
    typedef std::shared_ptr<IsLOSEnabled> IsLOSEnabledPtr;
    
    
    class IsLOSEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsLOSEnabled();

      IsLOSEnabled(int prn, const std::string& system);
  
      static IsLOSEnabledPtr create(int prn, const std::string& system);
      static IsLOSEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
  }
}

