
#include "gen/GetTropoModel.h"

#include "command_factory.h"
#include "command_result_factory.h"
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

    REGISTER_COMMAND_FACTORY(GetTropoModel);


    GetTropoModel::GetTropoModel()
      : CommandBase(CmdName)
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


    int GetTropoModel::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
