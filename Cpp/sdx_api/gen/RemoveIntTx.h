#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Removes the interference transmitter. See EnableIntTx if all you want is to
    /// disable the interference temporarily.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class RemoveIntTx;
    typedef std::shared_ptr<RemoveIntTx> RemoveIntTxPtr;
    
    
    class RemoveIntTx : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      RemoveIntTx();

      RemoveIntTx(const std::string& id);

      static RemoveIntTxPtr create(const std::string& id);
      static RemoveIntTxPtr dynamicCast(CommandBasePtr ptr);
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

