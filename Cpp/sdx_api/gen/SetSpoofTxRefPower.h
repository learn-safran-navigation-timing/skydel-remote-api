#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the spoofing transmitter reference power.
    ///
    /// Name  Type   Description
    /// ----- ------ ------------------------------
    /// Power double Reference Power (dBm)
    /// Id    string Transmitter unique identifier.
    ///

    class SetSpoofTxRefPower;
    typedef std::shared_ptr<SetSpoofTxRefPower> SetSpoofTxRefPowerPtr;
    
    
    class SetSpoofTxRefPower : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSpoofTxRefPower();

      SetSpoofTxRefPower(double power, const std::string& id);

      static SetSpoofTxRefPowerPtr create(double power, const std::string& id);
      static SetSpoofTxRefPowerPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** power ****
      double power() const;
      void setPower(double power);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

