#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get trajectory smoothing for Track or Route enabled or disabled
    ///
    /// 
    ///

    class IsTrajectorySmoothingEnabled;
    typedef std::shared_ptr<IsTrajectorySmoothingEnabled> IsTrajectorySmoothingEnabledPtr;
    
    
    class IsTrajectorySmoothingEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsTrajectorySmoothingEnabled();

      static IsTrajectorySmoothingEnabledPtr create();
      static IsTrajectorySmoothingEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

