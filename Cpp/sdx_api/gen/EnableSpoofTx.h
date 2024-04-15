#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable/Disable the spoofer.
    ///
    /// Name    Type   Description
    /// ------- ------ ------------------------------------------------
    /// Enabled bool   Enable (true) or disable (false) the transmitter
    /// Id      string Transmitter unique identifier.
    ///

    class EnableSpoofTx;
    typedef std::shared_ptr<EnableSpoofTx> EnableSpoofTxPtr;
    
    
    class EnableSpoofTx : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EnableSpoofTx();

      EnableSpoofTx(bool enabled, const std::string& id);

      static EnableSpoofTxPtr create(bool enabled, const std::string& id);
      static EnableSpoofTxPtr dynamicCast(CommandBasePtr ptr);
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

