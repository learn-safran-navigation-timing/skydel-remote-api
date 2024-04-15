
#include "GetSyncTimeResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSyncTimeResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSyncTimeResult::CmdName = "GetSyncTimeResult";
    const char* const GetSyncTimeResult::Documentation = "Result of GetSyncTime.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ----------------------------------------\n"
      "Time double Time delay in msec (minimum is 500 msec)";
    const char* const GetSyncTimeResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSyncTimeResult);


    GetSyncTimeResult::GetSyncTimeResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetSyncTimeResult::GetSyncTimeResult(double time)
      : CommandResult(CmdName, TargetId)
    {

      setTime(time);
    }

    GetSyncTimeResult::GetSyncTimeResult(CommandBasePtr relatedCommand, double time)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setTime(time);
    }


    GetSyncTimeResultPtr GetSyncTimeResult::create(double time)
    {
      return std::make_shared<GetSyncTimeResult>(time);
    }

    GetSyncTimeResultPtr GetSyncTimeResult::create(CommandBasePtr relatedCommand, double time)
    {
      return std::make_shared<GetSyncTimeResult>(relatedCommand, time);
    }

    GetSyncTimeResultPtr GetSyncTimeResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSyncTimeResult>(ptr);
    }

    bool GetSyncTimeResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["Time"])
        ;

    }

    std::string GetSyncTimeResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSyncTimeResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Time"}; 
      return names; 
    }


    double GetSyncTimeResult::time() const
    {
      return parse_json<double>::parse(m_values["Time"]);
    }

    void GetSyncTimeResult::setTime(double time)
    {
      m_values.AddMember("Time", parse_json<double>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
