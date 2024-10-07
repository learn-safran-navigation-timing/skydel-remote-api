#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the current propagation model.
    ///
    /// 
    ///

    class GetCurrentPropagationModel;
    typedef std::shared_ptr<GetCurrentPropagationModel> GetCurrentPropagationModelPtr;
    
    
    class GetCurrentPropagationModel : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetCurrentPropagationModel();

      static GetCurrentPropagationModelPtr create();
      static GetCurrentPropagationModelPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

