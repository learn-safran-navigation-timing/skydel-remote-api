
#include "GetPropagationModelParametersResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPropagationModelParametersResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPropagationModelParametersResult::CmdName = "GetPropagationModelParametersResult";
    const char* const GetPropagationModelParametersResult::Documentation = "Result of GetPropagationModelParameters.\n"
      "\n"
      "Name           Type                 Description\n"
      "-------------- -------------------- ------------------------------------------------------------------------\n"
      "Model          PropagationModelType The type of propagation model to edit.\n"
      "ParamValueDict dict string:double   The propagation model parameters. Leave blank to restore default values.";
    const char* const GetPropagationModelParametersResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPropagationModelParametersResult);


    GetPropagationModelParametersResult::GetPropagationModelParametersResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetPropagationModelParametersResult::GetPropagationModelParametersResult(const Sdx::PropagationModelType& model, const std::map<std::string, double>& paramValueDict)
      : CommandResult(CmdName, TargetId)
    {

      setModel(model);
      setParamValueDict(paramValueDict);
    }

    GetPropagationModelParametersResult::GetPropagationModelParametersResult(CommandBasePtr relatedCommand, const Sdx::PropagationModelType& model, const std::map<std::string, double>& paramValueDict)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setModel(model);
      setParamValueDict(paramValueDict);
    }


    GetPropagationModelParametersResultPtr GetPropagationModelParametersResult::create(const Sdx::PropagationModelType& model, const std::map<std::string, double>& paramValueDict)
    {
      return std::make_shared<GetPropagationModelParametersResult>(model, paramValueDict);
    }

    GetPropagationModelParametersResultPtr GetPropagationModelParametersResult::create(CommandBasePtr relatedCommand, const Sdx::PropagationModelType& model, const std::map<std::string, double>& paramValueDict)
    {
      return std::make_shared<GetPropagationModelParametersResult>(relatedCommand, model, paramValueDict);
    }

    GetPropagationModelParametersResultPtr GetPropagationModelParametersResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPropagationModelParametersResult>(ptr);
    }

    bool GetPropagationModelParametersResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::PropagationModelType>::is_valid(m_values["Model"])
          && parse_json<std::map<std::string, double>>::is_valid(m_values["ParamValueDict"])
        ;

    }

    std::string GetPropagationModelParametersResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPropagationModelParametersResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Model", "ParamValueDict"}; 
      return names; 
    }


    Sdx::PropagationModelType GetPropagationModelParametersResult::model() const
    {
      return parse_json<Sdx::PropagationModelType>::parse(m_values["Model"]);
    }

    void GetPropagationModelParametersResult::setModel(const Sdx::PropagationModelType& model)
    {
      m_values.AddMember("Model", parse_json<Sdx::PropagationModelType>::format(model, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::map<std::string, double> GetPropagationModelParametersResult::paramValueDict() const
    {
      return parse_json<std::map<std::string, double>>::parse(m_values["ParamValueDict"]);
    }

    void GetPropagationModelParametersResult::setParamValueDict(const std::map<std::string, double>& paramValueDict)
    {
      m_values.AddMember("ParamValueDict", parse_json<std::map<std::string, double>>::format(paramValueDict, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
