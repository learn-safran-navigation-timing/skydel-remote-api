#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Tells if data received on the HIL API logging is enabled
    ///
    /// 
    ///

    class IsLogHILInputEnabled;
    typedef std::shared_ptr<IsLogHILInputEnabled> IsLogHILInputEnabledPtr;
    
    
    class IsLogHILInputEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsLogHILInputEnabled();

      static IsLogHILInputEnabledPtr create();
      static IsLogHILInputEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

