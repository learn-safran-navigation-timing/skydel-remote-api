#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set whether the spoofer transmitter vehicle yaw, pitch and roll should be forced to zero.
    ///
    /// Name    Type   Description
    /// ------- ------ -------------------------------------------------------------------
    /// Enabled bool   If true, spoofer transmitter vehicle won't rotate during simulation
    /// Id      string Transmitter unique identifier.
    ///

    class ForceSpoofTxAttitudeToZero;
    typedef std::shared_ptr<ForceSpoofTxAttitudeToZero> ForceSpoofTxAttitudeToZeroPtr;
    
    
    class ForceSpoofTxAttitudeToZero : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      ForceSpoofTxAttitudeToZero();

      ForceSpoofTxAttitudeToZero(bool enabled, const std::string& id);

      static ForceSpoofTxAttitudeToZeroPtr create(bool enabled, const std::string& id);
      static ForceSpoofTxAttitudeToZeroPtr dynamicCast(CommandBasePtr ptr);
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

