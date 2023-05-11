#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get whether the ionospheric offsets grid should be used for SBAS corrections in message 26
    ///
    /// 
    ///

    class IsDelayAppliedInSbas;
    typedef std::shared_ptr<IsDelayAppliedInSbas> IsDelayAppliedInSbasPtr;
    
    
    class IsDelayAppliedInSbas : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsDelayAppliedInSbas();

      static IsDelayAppliedInSbasPtr create();
      static IsDelayAppliedInSbasPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

