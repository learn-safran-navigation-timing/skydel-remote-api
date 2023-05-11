
#include "gen/GetIonoModelResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoModelResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoModelResult::CmdName = "GetIonoModelResult";
    const char* const GetIonoModelResult::Documentation = "Result of GetIonoModel.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetIonoModelResult);


    GetIonoModelResult::GetIonoModelResult()
      : CommandResult(CmdName)
    {}

    GetIonoModelResult::GetIonoModelResult(const std::string& model)
      : CommandResult(CmdName)
    {

      setModel(model);
    }

    GetIonoModelResult::GetIonoModelResult(CommandBasePtr relatedCommand, const std::string& model)
      : CommandResult(CmdName, relatedCommand)
    {

      setModel(model);
    }


    GetIonoModelResultPtr GetIonoModelResult::create(const std::string& model)
    {
      return std::make_shared<GetIonoModelResult>(model);
    }

    GetIonoModelResultPtr GetIonoModelResult::create(CommandBasePtr relatedCommand, const std::string& model)
    {
      return std::make_shared<GetIonoModelResult>(relatedCommand, model);
    }

    GetIonoModelResultPtr GetIonoModelResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIonoModelResult>(ptr);
    }

    bool GetIonoModelResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Model"])
        ;

    }

    std::string GetIonoModelResult::documentation() const { return Documentation; }


    std::string GetIonoModelResult::model() const
    {
      return parse_json<std::string>::parse(m_values["Model"]);
    }

    void GetIonoModelResult::setModel(const std::string& model)
    {
      m_values.AddMember("Model", parse_json<std::string>::format(model, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
