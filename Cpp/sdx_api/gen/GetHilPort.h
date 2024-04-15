#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get Hardware in the loop trajectory server port.
    ///
    /// 
    ///

    class GetHilPort;
    typedef std::shared_ptr<GetHilPort> GetHilPortPtr;
    
    
    class GetHilPort : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetHilPort();

      static GetHilPortPtr create();
      static GetHilPortPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

