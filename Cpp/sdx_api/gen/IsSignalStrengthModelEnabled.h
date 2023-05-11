#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get signal strength model Enable/Disable which affect satellite transmission strength based on their elevation angle
    ///
    /// 
    ///

    class IsSignalStrengthModelEnabled;
    typedef std::shared_ptr<IsSignalStrengthModelEnabled> IsSignalStrengthModelEnabledPtr;
    
    
    class IsSignalStrengthModelEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSignalStrengthModelEnabled();

      static IsSignalStrengthModelEnabledPtr create();
      static IsSignalStrengthModelEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

