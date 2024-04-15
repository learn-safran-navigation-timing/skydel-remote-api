
#include "GetTropoModelResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetTropoModelResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetTropoModelResult::CmdName = "GetTropoModelResult";
    const char* const GetTropoModelResult::Documentation = "Result of GetTropoModel.\n"
      "\n"
      "Name  Type   Description\n"
      "----- ------ -----------------------------------------------------------------\n"
      "Model string Tropospheric model (\"None\", \"Saastamoinen\", \"Stanag\" or \"DO-229\")";
    const char* const GetTropoModelResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetTropoModelResult);


    GetTropoModelResult::GetTropoModelResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetTropoModelResult::GetTropoModelResult(const std::string& model)
      : CommandResult(CmdName, TargetId)
    {

      setModel(model);
    }

    GetTropoModelResult::GetTropoModelResult(CommandBasePtr relatedCommand, const std::string& model)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setModel(model);
    }


    GetTropoModelResultPtr GetTropoModelResult::create(const std::string& model)
    {
      return std::make_shared<GetTropoModelResult>(model);
    }

    GetTropoModelResultPtr GetTropoModelResult::create(CommandBasePtr relatedCommand, const std::string& model)
    {
      return std::make_shared<GetTropoModelResult>(relatedCommand, model);
    }

    GetTropoModelResultPtr GetTropoModelResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetTropoModelResult>(ptr);
    }

    bool GetTropoModelResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Model"])
        ;

    }

    std::string GetTropoModelResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetTropoModelResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Model"}; 
      return names; 
    }


    std::string GetTropoModelResult::model() const
    {
      return parse_json<std::string>::parse(m_values["Model"]);
    }

    void GetTropoModelResult::setModel(const std::string& model)
    {
      m_values.AddMember("Model", parse_json<std::string>::format(model, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
