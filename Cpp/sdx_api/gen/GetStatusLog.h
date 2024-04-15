#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Returns the status log in a GetStatusLogResult and clears it
    ///
    /// 
    ///

    class GetStatusLog;
    typedef std::shared_ptr<GetStatusLog> GetStatusLogPtr;
    
    
    class GetStatusLog : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetStatusLog();

      static GetStatusLogPtr create();
      static GetStatusLogPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

