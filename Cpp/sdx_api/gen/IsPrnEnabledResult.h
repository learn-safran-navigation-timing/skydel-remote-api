#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsPrnEnabled
    ///
    /// Name    Type   Description
    /// ------- ------ ----------------------------------------------------------------------------------------------------------
    /// System  string The satellite's constellation. Can be "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Prn     int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS. SV ID for QZSS and NavIC.
    /// Enabled bool   The satellite will be present/absent from the constellation
    ///

    class IsPrnEnabledResult;
    typedef std::shared_ptr<IsPrnEnabledResult> IsPrnEnabledResultPtr;
    
    
    class IsPrnEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsPrnEnabledResult();

      IsPrnEnabledResult(CommandBasePtr relatedCommand, const std::string& system, int prn, bool enabled);
  
      static IsPrnEnabledResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int prn, bool enabled);
      static IsPrnEnabledResultPtr dynamicCast(CommandBasePtr ptr);
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

