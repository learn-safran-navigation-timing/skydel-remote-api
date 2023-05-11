#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command ResetAllSatPower is deprecated since 21.7. You may use ResetManualPowerOffsets.
    /// 
    /// Reset power offset for all satellites is specified system to default value
    ///
    /// Name   Type   Description
    /// ------ ------ -----------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC".
    ///

    class ResetAllSatPower;
    typedef std::shared_ptr<ResetAllSatPower> ResetAllSatPowerPtr;
    
    
    class ResetAllSatPower : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ResetAllSatPower();

      ResetAllSatPower(const std::string& system);

      static ResetAllSatPowerPtr create(const std::string& system);
      static ResetAllSatPowerPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
    
  }
}

