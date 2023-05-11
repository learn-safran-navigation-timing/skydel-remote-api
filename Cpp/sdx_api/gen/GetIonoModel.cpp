
#include "gen/GetIonoModel.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoModel::CmdName = "GetIonoModel";
    const char* const GetIonoModel::Documentation = "Get ionospheric model";

    REGISTER_COMMAND_FACTORY(GetIonoModel);


    GetIonoModel::GetIonoModel()
      : CommandBase(CmdName)
    {

    }

    GetIonoModelPtr GetIonoModel::create()
    {
      return std::make_shared<GetIonoModel>();
    }

    GetIonoModelPtr GetIonoModel::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIonoModel>(ptr);
    }

    bool GetIonoModel::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetIonoModel::documentation() const { return Documentation; }


    int GetIonoModel::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
