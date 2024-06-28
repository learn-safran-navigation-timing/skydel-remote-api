#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetMasterStatus is deprecated since 23.11. You may use GetMainInstanceStatus.
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
      static const char* const TargetId;

      static const char* const Deprecated;


      GetMasterStatus();

      static GetMasterStatusPtr create();
      static GetMasterStatusPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual std::optional<std::string> deprecated() const override;

      virtual int executePermission() const override;
    };
    
  }
}

