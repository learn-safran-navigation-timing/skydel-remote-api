#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Removes the spoofer transmitter. See EnableSpoofTx if all you want is to
    /// disable the interference temporarily.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class RemoveSpoofTx;
    typedef std::shared_ptr<RemoveSpoofTx> RemoveSpoofTxPtr;
    
    
    class RemoveSpoofTx : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      RemoveSpoofTx();

      RemoveSpoofTx(const std::string& id);

      static RemoveSpoofTxPtr create(const std::string& id);
      static RemoveSpoofTxPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

