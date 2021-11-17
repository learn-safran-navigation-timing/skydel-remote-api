#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command IsPrnEnabled is deprecated since 21.3. You may use IsSVEnabled.
    /// 
    /// Get  enabled or disabled satellite for this constellation.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------------------------------------------------
    /// System string The satellite's constellation. Can be "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Prn    int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS. SV ID for QZSS and NavIC.
    ///

    class IsPrnEnabled;
    typedef std::shared_ptr<IsPrnEnabled> IsPrnEnabledPtr;
    
    
    class IsPrnEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsPrnEnabled();

      IsPrnEnabled(const std::string& system, int prn);
  
      static IsPrnEnabledPtr create(const std::string& system, int prn);
      static IsPrnEnabledPtr dynamicCast(CommandBasePtr ptr);
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

