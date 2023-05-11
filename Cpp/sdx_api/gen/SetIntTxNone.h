#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set an undefined trajectory to a transmitter, thus preventing it to be modulated (default value).
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class SetIntTxNone;
    typedef std::shared_ptr<SetIntTxNone> SetIntTxNonePtr;
    
    
    class SetIntTxNone : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetIntTxNone();

      SetIntTxNone(const std::string& id);

      static SetIntTxNonePtr create(const std::string& id);
      static SetIntTxNonePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

