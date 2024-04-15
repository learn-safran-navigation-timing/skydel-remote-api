#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set spoofer transmitter HIL trajectory
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class SetSpoofTxHil;
    typedef std::shared_ptr<SetSpoofTxHil> SetSpoofTxHilPtr;
    
    
    class SetSpoofTxHil : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetSpoofTxHil();

      SetSpoofTxHil(const std::string& id);

      static SetSpoofTxHilPtr create(const std::string& id);
      static SetSpoofTxHilPtr dynamicCast(CommandBasePtr ptr);
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

