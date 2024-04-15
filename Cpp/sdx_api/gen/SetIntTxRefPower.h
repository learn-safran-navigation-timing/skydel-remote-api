#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the interference transmitter reference power.
    ///
    /// Name  Type   Description
    /// ----- ------ ------------------------------
    /// Power double Reference Power (dBm)
    /// Id    string Transmitter unique identifier.
    ///

    class SetIntTxRefPower;
    typedef std::shared_ptr<SetIntTxRefPower> SetIntTxRefPowerPtr;
    
    
    class SetIntTxRefPower : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetIntTxRefPower();

      SetIntTxRefPower(double power, const std::string& id);

      static SetIntTxRefPowerPtr create(double power, const std::string& id);
      static SetIntTxRefPowerPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

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

