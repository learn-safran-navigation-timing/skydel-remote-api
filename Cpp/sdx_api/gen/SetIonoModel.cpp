
#include "gen/SetIonoModel.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIonoModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIonoModel::CmdName = "SetIonoModel";
    const char* const SetIonoModel::Documentation = "Set ionospheric model";

    REGISTER_COMMAND_FACTORY(SetIonoModel);


    SetIonoModel::SetIonoModel()
      : CommandBase(CmdName)
    {}

    SetIonoModel::SetIonoModel(const std::string& model)
      : CommandBase(CmdName)
    {

      setModel(model);
    }

    SetIonoModelPtr SetIonoModel::create(const std::string& model)
    {
      return std::make_shared<SetIonoModel>(model);
    }

    SetIonoModelPtr SetIonoModel::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIonoModel>(ptr);
    }

    bool SetIonoModel::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Model"])
        ;

    }

    std::string SetIonoModel::documentation() const { return Documentation; }


    int SetIonoModel::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetIonoModel::model() const
    {
      return parse_json<std::string>::parse(m_values["Model"]);
    }

    void SetIonoModel::setModel(const std::string& model)
    {
      m_values.AddMember("Model", parse_json<std::string>::format(model, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
