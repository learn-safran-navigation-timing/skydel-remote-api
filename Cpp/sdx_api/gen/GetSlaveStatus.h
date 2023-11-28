#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetSlaveStatus is deprecated since 23.11. You may use GetWorkerInstanceStatus.
    /// 
    /// Request for the slave status, returns a GetSlaveStatusResult
    ///
    /// 
    ///

    class GetSlaveStatus;
    typedef std::shared_ptr<GetSlaveStatus> GetSlaveStatusPtr;
    
    
    class GetSlaveStatus : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;

      static const char* const Deprecated;


      GetSlaveStatus();

      static GetSlaveStatusPtr create();
      static GetSlaveStatusPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual Sdx::optional<std::string> deprecated() const override;

      virtual int executePermission() const override;
    };
    
  }
}

