#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get OSNMA MAC function.
    ///
    /// 
    ///

    class GetOsnmaMacFunction;
    typedef std::shared_ptr<GetOsnmaMacFunction> GetOsnmaMacFunctionPtr;
    
    
    class GetOsnmaMacFunction : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetOsnmaMacFunction();

      static GetOsnmaMacFunctionPtr create();
      static GetOsnmaMacFunctionPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

