#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get whether the spoofer transmitter vehicle yaw, pitch and roll should be forced to zero.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class IsSpoofTxAttitudeToZeroForced;
    typedef std::shared_ptr<IsSpoofTxAttitudeToZeroForced> IsSpoofTxAttitudeToZeroForcedPtr;
    
    
    class IsSpoofTxAttitudeToZeroForced : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsSpoofTxAttitudeToZeroForced();

      IsSpoofTxAttitudeToZeroForced(const std::string& id);

      static IsSpoofTxAttitudeToZeroForcedPtr create(const std::string& id);
      static IsSpoofTxAttitudeToZeroForcedPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

