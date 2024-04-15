#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the address of the spoofer instance that will
    /// generate the signal for this spoofer transmitter.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class GetSpoofTxRemoteAddress;
    typedef std::shared_ptr<GetSpoofTxRemoteAddress> GetSpoofTxRemoteAddressPtr;
    
    
    class GetSpoofTxRemoteAddress : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSpoofTxRemoteAddress();

      GetSpoofTxRemoteAddress(const std::string& id);

      static GetSpoofTxRemoteAddressPtr create(const std::string& id);
      static GetSpoofTxRemoteAddressPtr dynamicCast(CommandBasePtr ptr);
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

