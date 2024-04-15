
#include "GetDurationResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetDurationResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetDurationResult::CmdName = "GetDurationResult";
    const char* const GetDurationResult::Documentation = "Result of GetDuration.\n"
      "\n"
      "Name   Type Description\n"
      "------ ---- -----------------------\n"
      "Second int  The duration in seconds";
    const char* const GetDurationResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetDurationResult);


    GetDurationResult::GetDurationResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetDurationResult::GetDurationResult(int second)
      : CommandResult(CmdName, TargetId)
    {

      setSecond(second);
    }

    GetDurationResult::GetDurationResult(CommandBasePtr relatedCommand, int second)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSecond(second);
    }


    GetDurationResultPtr GetDurationResult::create(int second)
    {
      return std::make_shared<GetDurationResult>(second);
    }

    GetDurationResultPtr GetDurationResult::create(CommandBasePtr relatedCommand, int second)
    {
      return std::make_shared<GetDurationResult>(relatedCommand, second);
    }

    GetDurationResultPtr GetDurationResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetDurationResult>(ptr);
    }

    bool GetDurationResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Second"])
        ;

    }

    std::string GetDurationResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetDurationResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Second"}; 
      return names; 
    }


    int GetDurationResult::second() const
    {
      return parse_json<int>::parse(m_values["Second"]);
    }

    void GetDurationResult::setSecond(int second)
    {
      m_values.AddMember("Second", parse_json<int>::format(second, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
