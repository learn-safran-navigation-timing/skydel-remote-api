#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Rename a transmitter.
    ///
    /// Name      Type   Description
    /// --------- ------ -------------------------------
    /// UsualName string Usual name for the transmitter.
    /// Id        string Transmitter unique identifier.
    ///

    class RenameIntTx;
    typedef std::shared_ptr<RenameIntTx> RenameIntTxPtr;
    
    
    class RenameIntTx : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      RenameIntTx();

      RenameIntTx(const std::string& usualName, const std::string& id);

      static RenameIntTxPtr create(const std::string& usualName, const std::string& id);
      static RenameIntTxPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** usualName ****
      std::string usualName() const;
      void setUsualName(const std::string& usualName);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

