#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set a spoofer transmitter. For set : the transmitter Id parameter is not set (empty string),
    /// Skydel will assign a unique Id to the transmitter. If the Id is set and already used by Skydel, the
    /// command will fail.
    ///
    /// Name       Type   Description
    /// ---------- ------ ------------------------------------------------
    /// UsualName  string Usual name for the transmitter.
    /// Enabled    bool   Enable (true) or disable (false) the transmitter
    /// Address    string Remote instance IP address.
    /// InstanceId int    Remote instance ID.
    /// Id         string Transmitter unique identifier.
    ///

    class AddSpoofTx;
    typedef std::shared_ptr<AddSpoofTx> AddSpoofTxPtr;
    
    
    class AddSpoofTx : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      AddSpoofTx();

      AddSpoofTx(const std::string& usualName, bool enabled, const std::string& address, int instanceId, const std::string& id);

      static AddSpoofTxPtr create(const std::string& usualName, bool enabled, const std::string& address, int instanceId, const std::string& id);
      static AddSpoofTxPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** usualName ****
      std::string usualName() const;
      void setUsualName(const std::string& usualName);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


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

