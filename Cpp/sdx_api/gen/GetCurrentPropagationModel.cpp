
#include "GetCurrentPropagationModel.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetCurrentPropagationModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetCurrentPropagationModel::CmdName = "GetCurrentPropagationModel";
    const char* const GetCurrentPropagationModel::Documentation = "Get the current propagation model.";
    const char* const GetCurrentPropagationModel::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetCurrentPropagationModel);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetCurrentPropagationModel);


    GetCurrentPropagationModel::GetCurrentPropagationModel()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetCurrentPropagationModelPtr GetCurrentPropagationModel::create()
    {
      return std::make_shared<GetCurrentPropagationModel>();
    }

    GetCurrentPropagationModelPtr GetCurrentPropagationModel::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetCurrentPropagationModel>(ptr);
    }

    bool GetCurrentPropagationModel::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetCurrentPropagationModel::documentation() const { return Documentation; }

    const std::vector<std::string>& GetCurrentPropagationModel::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetCurrentPropagationModel::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
