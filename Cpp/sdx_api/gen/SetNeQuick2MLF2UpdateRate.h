#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the update rate of the NeQuick2-MLF2 model.
    ///
    /// Name       Type Description
    /// ---------- ---- ----------------------------
    /// UpdateRate int  The update rate, in seconds.
    ///

    class SetNeQuick2MLF2UpdateRate;
    typedef std::shared_ptr<SetNeQuick2MLF2UpdateRate> SetNeQuick2MLF2UpdateRatePtr;
    
    
    class SetNeQuick2MLF2UpdateRate : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetNeQuick2MLF2UpdateRate();

      SetNeQuick2MLF2UpdateRate(int updateRate);

      static SetNeQuick2MLF2UpdateRatePtr create(int updateRate);
      static SetNeQuick2MLF2UpdateRatePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** updateRate ****
      int updateRate() const;
      void setUpdateRate(int updateRate);
    };
    
  }
}

