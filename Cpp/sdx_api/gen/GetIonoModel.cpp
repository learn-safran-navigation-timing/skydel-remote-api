
#include "GetIonoModel.h"

#include "command_factory.h"
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
    const char* const GetIonoModel::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetIonoModel);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIonoModel);


    GetIonoModel::GetIonoModel()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetIonoModel::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetIonoModel::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
