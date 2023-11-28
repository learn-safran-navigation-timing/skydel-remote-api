
#include "gen/GetSyncTimeMainInstanceResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSyncTimeMainInstanceResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSyncTimeMainInstanceResult::CmdName = "GetSyncTimeMainInstanceResult";
    const char* const GetSyncTimeMainInstanceResult::Documentation = "Result of GetSyncTimeMainInstance.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetSyncTimeMainInstanceResult);


    GetSyncTimeMainInstanceResult::GetSyncTimeMainInstanceResult()
      : CommandResult(CmdName)
    {}

    GetSyncTimeMainInstanceResult::GetSyncTimeMainInstanceResult(double time)
      : CommandResult(CmdName)
    {

      setTime(time);
    }

    GetSyncTimeMainInstanceResult::GetSyncTimeMainInstanceResult(CommandBasePtr relatedCommand, double time)
      : CommandResult(CmdName, relatedCommand)
    {

      setTime(time);
    }


    GetSyncTimeMainInstanceResultPtr GetSyncTimeMainInstanceResult::create(double time)
    {
      return std::make_shared<GetSyncTimeMainInstanceResult>(time);
    }

    GetSyncTimeMainInstanceResultPtr GetSyncTimeMainInstanceResult::create(CommandBasePtr relatedCommand, double time)
    {
      return std::make_shared<GetSyncTimeMainInstanceResult>(relatedCommand, time);
    }

    GetSyncTimeMainInstanceResultPtr GetSyncTimeMainInstanceResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSyncTimeMainInstanceResult>(ptr);
    }

    bool GetSyncTimeMainInstanceResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["Time"])
        ;

    }

    std::string GetSyncTimeMainInstanceResult::documentation() const { return Documentation; }


    double GetSyncTimeMainInstanceResult::time() const
    {
      return parse_json<double>::parse(m_values["Time"]);
    }

    void GetSyncTimeMainInstanceResult::setTime(double time)
    {
      m_values.AddMember("Time", parse_json<double>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
