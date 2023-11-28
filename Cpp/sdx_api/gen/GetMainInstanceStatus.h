#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Request for the main instance status, returns a GetMainInstanceStatusResult
    ///
    /// 
    ///

    class GetMainInstanceStatus;
    typedef std::shared_ptr<GetMainInstanceStatus> GetMainInstanceStatusPtr;
    
    
    class GetMainInstanceStatus : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetMainInstanceStatus();

      static GetMainInstanceStatusPtr create();
      static GetMainInstanceStatusPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

