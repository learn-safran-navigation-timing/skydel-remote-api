#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetMainInstanceStatus.
    ///
    /// Name                    Type Description
    /// ----------------------- ---- --------------------------------------------
    /// IsMainInstance          bool True if Skydel is in main instance mode
    /// WorkerInstanceConnected int  The number of connected worker instances
    /// Port                    int  The listening port, 0 if not a main instance
    ///

    class GetMainInstanceStatusResult;
    typedef std::shared_ptr<GetMainInstanceStatusResult> GetMainInstanceStatusResultPtr;
    
    
    class GetMainInstanceStatusResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetMainInstanceStatusResult();

      GetMainInstanceStatusResult(bool isMainInstance, int workerInstanceConnected, int port);

      GetMainInstanceStatusResult(CommandBasePtr relatedCommand, bool isMainInstance, int workerInstanceConnected, int port);

      static GetMainInstanceStatusResultPtr create(bool isMainInstance, int workerInstanceConnected, int port);

      static GetMainInstanceStatusResultPtr create(CommandBasePtr relatedCommand, bool isMainInstance, int workerInstanceConnected, int port);
      static GetMainInstanceStatusResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** isMainInstance ****
      bool isMainInstance() const;
      void setIsMainInstance(bool isMainInstance);


      // **** workerInstanceConnected ****
      int workerInstanceConnected() const;
      void setWorkerInstanceConnected(int workerInstanceConnected);


      // **** port ****
      int port() const;
      void setPort(int port);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetMainInstanceStatusResult);
  }
}

