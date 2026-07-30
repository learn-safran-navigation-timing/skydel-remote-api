#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the update rate of the NeQuick2-MLF2 model.
    ///
    /// 
    ///

    class GetNeQuick2MLF2UpdateRate;
    typedef std::shared_ptr<GetNeQuick2MLF2UpdateRate> GetNeQuick2MLF2UpdateRatePtr;
    
    
    class GetNeQuick2MLF2UpdateRate : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetNeQuick2MLF2UpdateRate();

      static GetNeQuick2MLF2UpdateRatePtr create();
      static GetNeQuick2MLF2UpdateRatePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

