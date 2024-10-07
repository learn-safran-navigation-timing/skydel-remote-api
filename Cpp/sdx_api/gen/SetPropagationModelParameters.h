#pragma once

#include <memory>
#include "command_base.h"

#include "gen/PropagationModelType.h"
#include <map>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the parameters for the propagation model.
    ///
    /// Name           Type                 Description
    /// -------------- -------------------- ------------------------------------------------------------------------
    /// Model          PropagationModelType The type of propagation model to edit.
    /// ParamValueDict dict string:double   The propagation model parameters. Leave blank to restore default values.
    ///

    class SetPropagationModelParameters;
    typedef std::shared_ptr<SetPropagationModelParameters> SetPropagationModelParametersPtr;
    
    
    class SetPropagationModelParameters : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetPropagationModelParameters();

      SetPropagationModelParameters(const Sdx::PropagationModelType& model, const std::map<std::string, double>& paramValueDict);

      static SetPropagationModelParametersPtr create(const Sdx::PropagationModelType& model, const std::map<std::string, double>& paramValueDict);
      static SetPropagationModelParametersPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** model ****
      Sdx::PropagationModelType model() const;
      void setModel(const Sdx::PropagationModelType& model);


      // **** paramValueDict ****
      std::map<std::string, double> paramValueDict() const;
      void setParamValueDict(const std::map<std::string, double>& paramValueDict);
    };
    
  }
}

