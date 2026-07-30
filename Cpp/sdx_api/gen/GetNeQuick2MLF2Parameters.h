#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the parameters of the NeQuick2-MLF2 model.
    ///
    /// 
    ///

    class GetNeQuick2MLF2Parameters;
    typedef std::shared_ptr<GetNeQuick2MLF2Parameters> GetNeQuick2MLF2ParametersPtr;
    
    
    class GetNeQuick2MLF2Parameters : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetNeQuick2MLF2Parameters();

      static GetNeQuick2MLF2ParametersPtr create();
      static GetNeQuick2MLF2ParametersPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

