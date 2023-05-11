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


      IsTrajectorySmoothingEnabled();

      static IsTrajectorySmoothingEnabledPtr create();
      static IsTrajectorySmoothingEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

