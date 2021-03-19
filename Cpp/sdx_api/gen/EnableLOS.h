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
    /// Set Direct Line Of Sight signal from satellite enabled or disabled. Generally used when only multipaths signal is visible.
    ///
    /// Name    Type   Description
    /// ------- ------ -------------------------------------------------------------------------------------------------------------
    /// Prn     int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS and SV ID for QZSS and NavIC.
    /// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Enabled bool   Direct Line of Sight enabled or not
    ///

    class EnableLOS;
    typedef std::shared_ptr<EnableLOS> EnableLOSPtr;
    
    
    class EnableLOS : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnableLOS();

      EnableLOS(int prn, const std::string& system, bool enabled);
  
      static EnableLOSPtr create(int prn, const std::string& system, bool enabled);
      static EnableLOSPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
  }
}

