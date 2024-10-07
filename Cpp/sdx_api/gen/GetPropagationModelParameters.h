#pragma once

#include <memory>
#include "command_base.h"

#include "gen/PropagationModelType.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the parameters for the propagation model.
    ///
    /// Name       Type                 Description
    /// ---------- -------------------- ------------------------------------------------------------------------
    /// Model      PropagationModelType The type of propagation model to edit.
    /// ParamArray array string         The propagation model parameters. Leave blank to restore default values.
    ///

    class GetPropagationModelParameters;
    typedef std::shared_ptr<GetPropagationModelParameters> GetPropagationModelParametersPtr;
    
    
    class GetPropagationModelParameters : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetPropagationModelParameters();

      GetPropagationModelParameters(const Sdx::PropagationModelType& model, const std::vector<std::string>& paramArray);

      static GetPropagationModelParametersPtr create(const Sdx::PropagationModelType& model, const std::vector<std::string>& paramArray);
      static GetPropagationModelParametersPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** model ****
      Sdx::PropagationModelType model() const;
      void setModel(const Sdx::PropagationModelType& model);


      // **** paramArray ****
      std::vector<std::string> paramArray() const;
      void setParamArray(const std::vector<std::string>& paramArray);
    };
    
  }
}

