
#include "GetPropagationModelParameters.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPropagationModelParameters
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPropagationModelParameters::CmdName = "GetPropagationModelParameters";
    const char* const GetPropagationModelParameters::Documentation = "Get the parameters for the propagation model.\n"
      "\n"
      "Name       Type                 Description\n"
      "---------- -------------------- ------------------------------------------------------------------------\n"
      "Model      PropagationModelType The type of propagation model to edit.\n"
      "ParamArray array string         The propagation model parameters. Leave blank to restore default values.";
    const char* const GetPropagationModelParameters::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetPropagationModelParameters);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPropagationModelParameters);


    GetPropagationModelParameters::GetPropagationModelParameters()
      : CommandBase(CmdName, TargetId)
    {}

    GetPropagationModelParameters::GetPropagationModelParameters(const Sdx::PropagationModelType& model, const std::vector<std::string>& paramArray)
      : CommandBase(CmdName, TargetId)
    {

      setModel(model);
      setParamArray(paramArray);
    }

    GetPropagationModelParametersPtr GetPropagationModelParameters::create(const Sdx::PropagationModelType& model, const std::vector<std::string>& paramArray)
    {
      return std::make_shared<GetPropagationModelParameters>(model, paramArray);
    }

    GetPropagationModelParametersPtr GetPropagationModelParameters::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPropagationModelParameters>(ptr);
    }

    bool GetPropagationModelParameters::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::PropagationModelType>::is_valid(m_values["Model"])
          && parse_json<std::vector<std::string>>::is_valid(m_values["ParamArray"])
        ;

    }

    std::string GetPropagationModelParameters::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPropagationModelParameters::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Model", "ParamArray"}; 
      return names; 
    }


    int GetPropagationModelParameters::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    Sdx::PropagationModelType GetPropagationModelParameters::model() const
    {
      return parse_json<Sdx::PropagationModelType>::parse(m_values["Model"]);
    }

    void GetPropagationModelParameters::setModel(const Sdx::PropagationModelType& model)
    {
      m_values.AddMember("Model", parse_json<Sdx::PropagationModelType>::format(model, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<std::string> GetPropagationModelParameters::paramArray() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["ParamArray"]);
    }

    void GetPropagationModelParameters::setParamArray(const std::vector<std::string>& paramArray)
    {
      m_values.AddMember("ParamArray", parse_json<std::vector<std::string>>::format(paramArray, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
