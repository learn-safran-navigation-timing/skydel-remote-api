#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set host and port to connect to sync time server.
    ///
    /// Name Type   Description
    /// ---- ------ ----------------
    /// Host string Host address
    /// Port int    Host port number
    ///

    class SetSyncClient;
    typedef std::shared_ptr<SetSyncClient> SetSyncClientPtr;
    
    
    class SetSyncClient : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSyncClient();

      SetSyncClient(const std::string& host, int port);

      static SetSyncClientPtr create(const std::string& host, int port);
      static SetSyncClientPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** host ****
      std::string host() const;
      void setHost(const std::string& host);


      // **** port ****
      int port() const;
      void setPort(int port);
    };
    
  }
}

