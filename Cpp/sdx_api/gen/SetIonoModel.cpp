
#include "SetIonoModel.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIonoModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIonoModel::CmdName = "SetIonoModel";
    const char* const SetIonoModel::Documentation = "Set ionospheric model\n"
      "\n"
      "Name  Type   Description\n"
      "----- ------ ------------------------------------------------------------------\n"
      "Model string Ionospheric model (\"None\", \"Klobuchar\", \"Spacecraft\" or \"NeQuick\")";
    const char* const SetIonoModel::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetIonoModel);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetIonoModel);


    SetIonoModel::SetIonoModel()
      : CommandBase(CmdName, TargetId)
    {}

    SetIonoModel::SetIonoModel(const std::string& model)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& SetIonoModel::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Model"}; 
      return names; 
    }


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
