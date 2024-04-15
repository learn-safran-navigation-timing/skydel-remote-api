#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set force interference vehicle yaw, pitch and roll to zero enabled or disabled
    ///
    /// Name    Type   Description
    /// ------- ------ ------------------------------------------------------------
    /// Enabled bool   If true, interference vehicle won't rotate during simulation
    /// Id      string Transmitter unique identifier.
    ///

    class ForceIntTxAttitudeToZero;
    typedef std::shared_ptr<ForceIntTxAttitudeToZero> ForceIntTxAttitudeToZeroPtr;
    
    
    class ForceIntTxAttitudeToZero : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      ForceIntTxAttitudeToZero();

      ForceIntTxAttitudeToZero(bool enabled, const std::string& id);

      static ForceIntTxAttitudeToZeroPtr create(bool enabled, const std::string& id);
      static ForceIntTxAttitudeToZeroPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

