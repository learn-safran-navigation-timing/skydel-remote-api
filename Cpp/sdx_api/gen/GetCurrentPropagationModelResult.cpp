
#include "GetCurrentPropagationModelResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetCurrentPropagationModelResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetCurrentPropagationModelResult::CmdName = "GetCurrentPropagationModelResult";
    const char* const GetCurrentPropagationModelResult::Documentation = "Result of GetCurrentPropagationModel.\n"
      "\n"
      "Name  Type                 Description\n"
      "----- -------------------- ---------------------------------------\n"
      "Model PropagationModelType The selected type of propagation model.";
    const char* const GetCurrentPropagationModelResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetCurrentPropagationModelResult);


    GetCurrentPropagationModelResult::GetCurrentPropagationModelResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetCurrentPropagationModelResult::GetCurrentPropagationModelResult(const Sdx::PropagationModelType& model)
      : CommandResult(CmdName, TargetId)
    {

      setModel(model);
    }

    GetCurrentPropagationModelResult::GetCurrentPropagationModelResult(CommandBasePtr relatedCommand, const Sdx::PropagationModelType& model)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setModel(model);
    }


    GetCurrentPropagationModelResultPtr GetCurrentPropagationModelResult::create(const Sdx::PropagationModelType& model)
    {
      return std::make_shared<GetCurrentPropagationModelResult>(model);
    }

    GetCurrentPropagationModelResultPtr GetCurrentPropagationModelResult::create(CommandBasePtr relatedCommand, const Sdx::PropagationModelType& model)
    {
      return std::make_shared<GetCurrentPropagationModelResult>(relatedCommand, model);
    }

    GetCurrentPropagationModelResultPtr GetCurrentPropagationModelResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetCurrentPropagationModelResult>(ptr);
    }

    bool GetCurrentPropagationModelResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::PropagationModelType>::is_valid(m_values["Model"])
        ;

    }

    std::string GetCurrentPropagationModelResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetCurrentPropagationModelResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Model"}; 
      return names; 
    }


    Sdx::PropagationModelType GetCurrentPropagationModelResult::model() const
    {
      return parse_json<Sdx::PropagationModelType>::parse(m_values["Model"]);
    }

    void GetCurrentPropagationModelResult::setModel(const Sdx::PropagationModelType& model)
    {
      m_values.AddMember("Model", parse_json<Sdx::PropagationModelType>::format(model, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
