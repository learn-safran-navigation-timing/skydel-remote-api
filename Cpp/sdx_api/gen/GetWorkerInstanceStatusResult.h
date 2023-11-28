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
    /// Result of GetWorkerInstanceStatus.
    ///
    /// Name             Type   Description
    /// ---------------- ------ ----------------------------------------------
    /// IsWorkerInstance bool   True if Skydel is in worker instance mode
    /// IsConnected      bool   True if Skydel is connected to a main instance
    /// HostName         string The host name, empty if not a worker instance
    /// HostPort         int    The host port, 0 if not a worker instance
    ///

    class GetWorkerInstanceStatusResult;
    typedef std::shared_ptr<GetWorkerInstanceStatusResult> GetWorkerInstanceStatusResultPtr;
    
    
    class GetWorkerInstanceStatusResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetWorkerInstanceStatusResult();

      GetWorkerInstanceStatusResult(bool isWorkerInstance, bool isConnected, const std::string& hostName, int hostPort);

      GetWorkerInstanceStatusResult(CommandBasePtr relatedCommand, bool isWorkerInstance, bool isConnected, const std::string& hostName, int hostPort);

      static GetWorkerInstanceStatusResultPtr create(bool isWorkerInstance, bool isConnected, const std::string& hostName, int hostPort);

      static GetWorkerInstanceStatusResultPtr create(CommandBasePtr relatedCommand, bool isWorkerInstance, bool isConnected, const std::string& hostName, int hostPort);
      static GetWorkerInstanceStatusResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** isWorkerInstance ****
      bool isWorkerInstance() const;
      void setIsWorkerInstance(bool isWorkerInstance);


      // **** isConnected ****
      bool isConnected() const;
      void setIsConnected(bool isConnected);


      // **** hostName ****
      std::string hostName() const;
      void setHostName(const std::string& hostName);


      // **** hostPort ****
      int hostPort() const;
      void setHostPort(int hostPort);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetWorkerInstanceStatusResult);
  }
}

