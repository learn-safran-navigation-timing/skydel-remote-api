
#include "GetTropoModel.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetTropoModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetTropoModel::CmdName = "GetTropoModel";
    const char* const GetTropoModel::Documentation = "Get tropospheric model";
    const char* const GetTropoModel::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetTropoModel);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetTropoModel);


    GetTropoModel::GetTropoModel()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetTropoModelPtr GetTropoModel::create()
    {
      return std::make_shared<GetTropoModel>();
    }

    GetTropoModelPtr GetTropoModel::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetTropoModel>(ptr);
    }

    bool GetTropoModel::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetTropoModel::documentation() const { return Documentation; }

    const std::vector<std::string>& GetTropoModel::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetTropoModel::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
