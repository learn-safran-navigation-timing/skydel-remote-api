
#include "gen/SetTropoModel.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetTropoModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetTropoModel::CmdName = "SetTropoModel";
    const char* const SetTropoModel::Documentation = "Set tropospheric model";

    REGISTER_COMMAND_FACTORY(SetTropoModel);


    SetTropoModel::SetTropoModel()
      : CommandBase(CmdName)
    {}

    SetTropoModel::SetTropoModel(const std::string& model)
      : CommandBase(CmdName)
    {

      setModel(model);
    }

    SetTropoModelPtr SetTropoModel::create(const std::string& model)
    {
      return std::make_shared<SetTropoModel>(model);
    }

    SetTropoModelPtr SetTropoModel::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetTropoModel>(ptr);
    }

    bool SetTropoModel::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Model"])
        ;

    }

    std::string SetTropoModel::documentation() const { return Documentation; }


    int SetTropoModel::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetTropoModel::model() const
    {
      return parse_json<std::string>::parse(m_values["Model"]);
    }

    void SetTropoModel::setModel(const std::string& model)
    {
      m_values.AddMember("Model", parse_json<std::string>::format(model, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
