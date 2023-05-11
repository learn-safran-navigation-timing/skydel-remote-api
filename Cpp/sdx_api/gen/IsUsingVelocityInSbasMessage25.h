#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get whether SBAS message 25 should send velocity corrections
    ///
    /// 
    ///

    class IsUsingVelocityInSbasMessage25;
    typedef std::shared_ptr<IsUsingVelocityInSbasMessage25> IsUsingVelocityInSbasMessage25Ptr;
    
    
    class IsUsingVelocityInSbasMessage25 : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsUsingVelocityInSbasMessage25();

      static IsUsingVelocityInSbasMessage25Ptr create();
      static IsUsingVelocityInSbasMessage25Ptr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

