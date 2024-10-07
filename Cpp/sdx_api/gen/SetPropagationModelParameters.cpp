
#include "SetPropagationModelParameters.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPropagationModelParameters
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPropagationModelParameters::CmdName = "SetPropagationModelParameters";
    const char* const SetPropagationModelParameters::Documentation = "Set the parameters for the propagation model.\n"
      "\n"
      "Name           Type                 Description\n"
      "-------------- -------------------- ------------------------------------------------------------------------\n"
      "Model          PropagationModelType The type of propagation model to edit.\n"
      "ParamValueDict dict string:double   The propagation model parameters. Leave blank to restore default values.";
    const char* const SetPropagationModelParameters::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetPropagationModelParameters);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetPropagationModelParameters);


    SetPropagationModelParameters::SetPropagationModelParameters()
      : CommandBase(CmdName, TargetId)
    {}

    SetPropagationModelParameters::SetPropagationModelParameters(const Sdx::PropagationModelType& model, const std::map<std::string, double>& paramValueDict)
      : CommandBase(CmdName, TargetId)
    {

      setModel(model);
      setParamValueDict(paramValueDict);
    }

    SetPropagationModelParametersPtr SetPropagationModelParameters::create(const Sdx::PropagationModelType& model, const std::map<std::string, double>& paramValueDict)
    {
      return std::make_shared<SetPropagationModelParameters>(model, paramValueDict);
    }

    SetPropagationModelParametersPtr SetPropagationModelParameters::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetPropagationModelParameters>(ptr);
    }

    bool SetPropagationModelParameters::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::PropagationModelType>::is_valid(m_values["Model"])
          && parse_json<std::map<std::string, double>>::is_valid(m_values["ParamValueDict"])
        ;

    }

    std::string SetPropagationModelParameters::documentation() const { return Documentation; }

    const std::vector<std::string>& SetPropagationModelParameters::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Model", "ParamValueDict"}; 
      return names; 
    }


    int SetPropagationModelParameters::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    Sdx::PropagationModelType SetPropagationModelParameters::model() const
    {
      return parse_json<Sdx::PropagationModelType>::parse(m_values["Model"]);
    }

    void SetPropagationModelParameters::setModel(const Sdx::PropagationModelType& model)
    {
      m_values.AddMember("Model", parse_json<Sdx::PropagationModelType>::format(model, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::map<std::string, double> SetPropagationModelParameters::paramValueDict() const
    {
      return parse_json<std::map<std::string, double>>::parse(m_values["ParamValueDict"]);
    }

    void SetPropagationModelParameters::setParamValueDict(const std::map<std::string, double>& paramValueDict)
    {
      m_values.AddMember("ParamValueDict", parse_json<std::map<std::string, double>>::format(paramValueDict, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
