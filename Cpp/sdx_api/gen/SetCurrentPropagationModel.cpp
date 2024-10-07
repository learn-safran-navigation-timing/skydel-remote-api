
#include "SetCurrentPropagationModel.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetCurrentPropagationModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetCurrentPropagationModel::CmdName = "SetCurrentPropagationModel";
    const char* const SetCurrentPropagationModel::Documentation = "Set the current propagation model.\n"
      "\n"
      "Name  Type                 Description\n"
      "----- -------------------- ---------------------------------------\n"
      "Model PropagationModelType The selected type of propagation model.";
    const char* const SetCurrentPropagationModel::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetCurrentPropagationModel);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetCurrentPropagationModel);


    SetCurrentPropagationModel::SetCurrentPropagationModel()
      : CommandBase(CmdName, TargetId)
    {}

    SetCurrentPropagationModel::SetCurrentPropagationModel(const Sdx::PropagationModelType& model)
      : CommandBase(CmdName, TargetId)
    {

      setModel(model);
    }

    SetCurrentPropagationModelPtr SetCurrentPropagationModel::create(const Sdx::PropagationModelType& model)
    {
      return std::make_shared<SetCurrentPropagationModel>(model);
    }

    SetCurrentPropagationModelPtr SetCurrentPropagationModel::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetCurrentPropagationModel>(ptr);
    }

    bool SetCurrentPropagationModel::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::PropagationModelType>::is_valid(m_values["Model"])
        ;

    }

    std::string SetCurrentPropagationModel::documentation() const { return Documentation; }

    const std::vector<std::string>& SetCurrentPropagationModel::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Model"}; 
      return names; 
    }


    int SetCurrentPropagationModel::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    Sdx::PropagationModelType SetCurrentPropagationModel::model() const
    {
      return parse_json<Sdx::PropagationModelType>::parse(m_values["Model"]);
    }

    void SetCurrentPropagationModel::setModel(const Sdx::PropagationModelType& model)
    {
      m_values.AddMember("Model", parse_json<Sdx::PropagationModelType>::format(model, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
