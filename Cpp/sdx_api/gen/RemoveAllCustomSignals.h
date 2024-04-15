#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Removes all the custom signals
    ///
    /// 
    ///

    class RemoveAllCustomSignals;
    typedef std::shared_ptr<RemoveAllCustomSignals> RemoveAllCustomSignalsPtr;
    
    
    class RemoveAllCustomSignals : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      RemoveAllCustomSignals();

      static RemoveAllCustomSignalsPtr create();
      static RemoveAllCustomSignalsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

