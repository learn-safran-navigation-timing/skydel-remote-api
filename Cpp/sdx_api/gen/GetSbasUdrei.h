#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the global UDREI value transmitted by SBAS
    ///
    /// 
    ///

    class GetSbasUdrei;
    typedef std::shared_ptr<GetSbasUdrei> GetSbasUdreiPtr;
    
    
    class GetSbasUdrei : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSbasUdrei();
  
      static GetSbasUdreiPtr create();
      static GetSbasUdreiPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
  }
}

