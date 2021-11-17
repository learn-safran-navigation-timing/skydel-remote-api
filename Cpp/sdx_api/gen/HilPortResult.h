#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetHilPort.
    ///
    /// Name Type Description
    /// ---- ---- ---------------
    /// Port int  Hil Server Port
    ///

    class HilPortResult;
    typedef std::shared_ptr<HilPortResult> HilPortResultPtr;
    
    
    class HilPortResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      HilPortResult();

      HilPortResult(CommandBasePtr relatedCommand, int port);
  
      static HilPortResultPtr create(CommandBasePtr relatedCommand, int port);
      static HilPortResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** port ****
      int port() const;
      void setPort(int port);
    };
  }
}

