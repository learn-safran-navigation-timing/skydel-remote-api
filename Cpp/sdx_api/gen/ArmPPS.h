#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Arm the system for further PPS synchronization instructions.
    ///
    /// 
    ///

    class ArmPPS;
    typedef std::shared_ptr<ArmPPS> ArmPPSPtr;
    
    
    class ArmPPS : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ArmPPS();

      static ArmPPSPtr create();
      static ArmPPSPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

