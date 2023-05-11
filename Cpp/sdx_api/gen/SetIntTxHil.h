#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set interference transmitter HIL trajectory
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class SetIntTxHil;
    typedef std::shared_ptr<SetIntTxHil> SetIntTxHilPtr;
    
    
    class SetIntTxHil : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetIntTxHil();

      SetIntTxHil(const std::string& id);

      static SetIntTxHilPtr create(const std::string& id);
      static SetIntTxHilPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

