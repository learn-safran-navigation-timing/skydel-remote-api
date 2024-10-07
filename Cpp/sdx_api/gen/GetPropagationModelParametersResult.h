#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "gen/PropagationModelType.h"
#include <map>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetPropagationModelParameters.
    ///
    /// Name           Type                 Description
    /// -------------- -------------------- ------------------------------------------------------------------------
    /// Model          PropagationModelType The type of propagation model to edit.
    /// ParamValueDict dict string:double   The propagation model parameters. Leave blank to restore default values.
    ///

    class GetPropagationModelParametersResult;
    typedef std::shared_ptr<GetPropagationModelParametersResult> GetPropagationModelParametersResultPtr;
    
    
    class GetPropagationModelParametersResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetPropagationModelParametersResult();

      GetPropagationModelParametersResult(const Sdx::PropagationModelType& model, const std::map<std::string, double>& paramValueDict);

      GetPropagationModelParametersResult(CommandBasePtr relatedCommand, const Sdx::PropagationModelType& model, const std::map<std::string, double>& paramValueDict);

      static GetPropagationModelParametersResultPtr create(const Sdx::PropagationModelType& model, const std::map<std::string, double>& paramValueDict);

      static GetPropagationModelParametersResultPtr create(CommandBasePtr relatedCommand, const Sdx::PropagationModelType& model, const std::map<std::string, double>& paramValueDict);
      static GetPropagationModelParametersResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** model ****
      Sdx::PropagationModelType model() const;
      void setModel(const Sdx::PropagationModelType& model);


      // **** paramValueDict ****
      std::map<std::string, double> paramValueDict() const;
      void setParamValueDict(const std::map<std::string, double>& paramValueDict);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetPropagationModelParametersResult);
  }
}

