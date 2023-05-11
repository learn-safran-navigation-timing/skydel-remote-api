#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// HIL Tjoin. Value is in milliseconds.
    ///
    /// Name     Type Description
    /// -------- ---- -----------
    /// HilTjoin int  HIL Tjoin.
    ///

    class SetHilTjoin;
    typedef std::shared_ptr<SetHilTjoin> SetHilTjoinPtr;
    
    
    class SetHilTjoin : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetHilTjoin();

      SetHilTjoin(int hilTjoin);

      static SetHilTjoinPtr create(int hilTjoin);
      static SetHilTjoinPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** hilTjoin ****
      int hilTjoin() const;
      void setHilTjoin(int hilTjoin);
    };
    
  }
}

