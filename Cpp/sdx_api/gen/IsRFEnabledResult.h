#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsRFEnabled.
    ///
    /// Name    Type   Description
    /// ------- ------ ----------------------------------------------------------------------------------------------------------
    /// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Prn     int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS. SV ID for QZSS and NavIC.
    /// Enabled bool   RF is enabled when value is True
    ///

    class IsRFEnabledResult;
    typedef std::shared_ptr<IsRFEnabledResult> IsRFEnabledResultPtr;
    
    
    class IsRFEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsRFEnabledResult();

      IsRFEnabledResult(CommandBasePtr relatedCommand, const std::string& system, int prn, bool enabled);
  
      static IsRFEnabledResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int prn, bool enabled);
      static IsRFEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


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

