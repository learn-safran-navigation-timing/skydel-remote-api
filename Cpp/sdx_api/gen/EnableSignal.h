#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command EnableSignal is deprecated since 21.3. You may use EnableSignalForSV.
    /// 
    /// Enable (or disable) signal for specified satellite. Use PRN 0 to enabled/disable all satellites.
    /// QZSS uses SVID instead of PRN.
    /// Allowed signal keys: "L1CA", "L1C", "L1P", "L1M", "L2C", "L2P", "L2M", "L5",
    ///                      "G1", "G2", "E1", "E5a", "E5b", "B1", "B2", "B1C", "B2a",
    ///                      "SBAS", "QZSSL1CA", "QZSSL1C", "QZSSL5", "QZSSL1S", "QZSSL5S",
    ///                      "NAVICL5"
    ///
    /// Name    Type   Description
    /// ------- ------ ----------------------------------------------------------------------------------------------------------
    /// Prn     int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS. SV ID for QZSS and NavIC.
    /// Signal  string Signal key - see command description for possible values
    /// Enabled bool   Signal is enabled when value is True
    ///

    class EnableSignal;
    typedef std::shared_ptr<EnableSignal> EnableSignalPtr;
    
    
    class EnableSignal : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnableSignal();

      EnableSignal(int prn, const std::string& signal, bool enabled);
  
      static EnableSignalPtr create(int prn, const std::string& signal, bool enabled);
      static EnableSignalPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
  }
}

