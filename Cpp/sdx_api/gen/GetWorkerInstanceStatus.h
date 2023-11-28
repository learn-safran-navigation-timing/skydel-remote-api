#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Request for the worker instance status, returns a GetWorkerInstanceStatusResult
    ///
    /// 
    ///

    class GetWorkerInstanceStatus;
    typedef std::shared_ptr<GetWorkerInstanceStatus> GetWorkerInstanceStatusPtr;
    
    
    class GetWorkerInstanceStatus : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetWorkerInstanceStatus();

      static GetWorkerInstanceStatusPtr create();
      static GetWorkerInstanceStatusPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

