#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
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


      GetSlaveStatus();

      static GetSlaveStatusPtr create();
      static GetSlaveStatusPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

