#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get force interference vehicle yaw, pitch and roll to zero enabled or disabled
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class IsIntTxAttitudeToZeroForced;
    typedef std::shared_ptr<IsIntTxAttitudeToZeroForced> IsIntTxAttitudeToZeroForcedPtr;
    
    
    class IsIntTxAttitudeToZeroForced : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsIntTxAttitudeToZeroForced();

      IsIntTxAttitudeToZeroForced(const std::string& id);

      static IsIntTxAttitudeToZeroForcedPtr create(const std::string& id);
      static IsIntTxAttitudeToZeroForcedPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

