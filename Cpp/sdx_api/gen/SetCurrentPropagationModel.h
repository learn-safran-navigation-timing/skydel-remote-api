#pragma once

#include <memory>
#include "command_base.h"

#include "gen/PropagationModelType.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the current propagation model.
    ///
    /// Name  Type                 Description
    /// ----- -------------------- ---------------------------------------
    /// Model PropagationModelType The selected type of propagation model.
    ///

    class SetCurrentPropagationModel;
    typedef std::shared_ptr<SetCurrentPropagationModel> SetCurrentPropagationModelPtr;
    
    
    class SetCurrentPropagationModel : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetCurrentPropagationModel();

      SetCurrentPropagationModel(const Sdx::PropagationModelType& model);

      static SetCurrentPropagationModelPtr create(const Sdx::PropagationModelType& model);
      static SetCurrentPropagationModelPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** model ****
      Sdx::PropagationModelType model() const;
      void setModel(const Sdx::PropagationModelType& model);
    };
    
  }
}

