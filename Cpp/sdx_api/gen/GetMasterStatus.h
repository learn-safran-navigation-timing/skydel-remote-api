#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Request for the master status, returns a GetMasterStatusResult
    ///
    /// 
    ///

    class GetMasterStatus;
    typedef std::shared_ptr<GetMasterStatus> GetMasterStatusPtr;
    
    
    class GetMasterStatus : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetMasterStatus();

      static GetMasterStatusPtr create();
      static GetMasterStatusPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

