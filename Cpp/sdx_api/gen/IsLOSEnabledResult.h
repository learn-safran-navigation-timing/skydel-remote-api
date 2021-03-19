#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsLOSEnabled
    ///
    /// Name    Type   Description
    /// ------- ------ -------------------------------------------------------------------------------------------------------------
    /// Prn     int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS and SV ID for QZSS and NavIC.
    /// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Enabled bool   Direct Line of Sight enabled or not
    ///

    class IsLOSEnabledResult;
    typedef std::shared_ptr<IsLOSEnabledResult> IsLOSEnabledResultPtr;
    
    
    class IsLOSEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsLOSEnabledResult();

      IsLOSEnabledResult(CommandBasePtr relatedCommand, int prn, const std::string& system, bool enabled);
  
      static IsLOSEnabledResultPtr create(CommandBasePtr relatedCommand, int prn, const std::string& system, bool enabled);
      static IsLOSEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


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

