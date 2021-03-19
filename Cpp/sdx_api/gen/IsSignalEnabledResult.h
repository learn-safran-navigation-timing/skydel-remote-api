#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsSignalEnabled
    ///
    /// Name    Type   Description
    /// ------- ------ ----------------------------------------------------------------------------------------------------------
    /// Prn     int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS. SV ID for QZSS and NavIC.
    /// Signal  string Signal key - see command description for possible values
    /// Enabled bool   Signal is enabled when value is True
    ///

    class IsSignalEnabledResult;
    typedef std::shared_ptr<IsSignalEnabledResult> IsSignalEnabledResultPtr;
    
    
    class IsSignalEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSignalEnabledResult();

      IsSignalEnabledResult(CommandBasePtr relatedCommand, int prn, const std::string& signal, bool enabled);
  
      static IsSignalEnabledResultPtr create(CommandBasePtr relatedCommand, int prn, const std::string& signal, bool enabled);
      static IsSignalEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


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

