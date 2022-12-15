#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSpoofTxRemoteAddress.
    ///
    /// Name       Type   Description
    /// ---------- ------ ------------------------------
    /// Address    string Remote instance IP address.
    /// InstanceId int    Remote instance ID.
    /// Id         string Transmitter unique identifier.
    ///

    class GetSpoofTxRemoteAddressResult;
    typedef std::shared_ptr<GetSpoofTxRemoteAddressResult> GetSpoofTxRemoteAddressResultPtr;
    
    
    class GetSpoofTxRemoteAddressResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSpoofTxRemoteAddressResult();

      GetSpoofTxRemoteAddressResult(CommandBasePtr relatedCommand, const std::string& address, int instanceId, const std::string& id);
  
      static GetSpoofTxRemoteAddressResultPtr create(CommandBasePtr relatedCommand, const std::string& address, int instanceId, const std::string& id);
      static GetSpoofTxRemoteAddressResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


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
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetSpoofTxRemoteAddressResult);
  }
}

