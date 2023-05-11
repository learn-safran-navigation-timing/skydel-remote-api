#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Rename a spoofer.
    ///
    /// Name      Type   Description
    /// --------- ------ -------------------------------
    /// UsualName string Usual name for the transmitter.
    /// Id        string Transmitter unique identifier.
    ///

    class RenameSpoofTx;
    typedef std::shared_ptr<RenameSpoofTx> RenameSpoofTxPtr;
    
    
    class RenameSpoofTx : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      RenameSpoofTx();

      RenameSpoofTx(const std::string& usualName, const std::string& id);

      static RenameSpoofTxPtr create(const std::string& usualName, const std::string& id);
      static RenameSpoofTxPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

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

