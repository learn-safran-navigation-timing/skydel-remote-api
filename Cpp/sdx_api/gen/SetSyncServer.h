#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set listening port for sync time server.
    ///
    /// Name Type Description
    /// ---- ---- ---------------------
    /// Port int  Listening port number
    ///

    class SetSyncServer;
    typedef std::shared_ptr<SetSyncServer> SetSyncServerPtr;
    
    
    class SetSyncServer : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetSyncServer();

      SetSyncServer(int port);

      static SetSyncServerPtr create(int port);
      static SetSyncServerPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** port ****
      int port() const;
      void setPort(int port);
    };
    
  }
}

