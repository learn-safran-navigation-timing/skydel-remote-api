#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the address of the spoofer instance that will
    /// generate the signal for this spoofer transmitter.
    ///
    /// Name       Type   Description
    /// ---------- ------ ------------------------------
    /// Address    string Remote instance IP address.
    /// InstanceId int    Remote instance ID.
    /// Id         string Transmitter unique identifier.
    ///

    class SetSpoofTxRemoteAddress;
    typedef std::shared_ptr<SetSpoofTxRemoteAddress> SetSpoofTxRemoteAddressPtr;
    
    
    class SetSpoofTxRemoteAddress : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSpoofTxRemoteAddress();

      SetSpoofTxRemoteAddress(const std::string& address, int instanceId, const std::string& id);

      static SetSpoofTxRemoteAddressPtr create(const std::string& address, int instanceId, const std::string& id);
      static SetSpoofTxRemoteAddressPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** address ****
      std::string address() const;
      void setAddress(const std::string& address);


      // **** instanceId ****
      int instanceId() const;
      void setInstanceId(int instanceId);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

