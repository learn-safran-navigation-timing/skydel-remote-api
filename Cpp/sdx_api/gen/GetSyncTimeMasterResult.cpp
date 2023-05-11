
#include "gen/GetSyncTimeMasterResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSyncTimeMasterResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSyncTimeMasterResult::CmdName = "GetSyncTimeMasterResult";
    const char* const GetSyncTimeMasterResult::Documentation = "Result of GetSyncTimeMaster.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetSyncTimeMasterResult);


    GetSyncTimeMasterResult::GetSyncTimeMasterResult()
      : CommandResult(CmdName)
    {}

    GetSyncTimeMasterResult::GetSyncTimeMasterResult(double time)
      : CommandResult(CmdName)
    {

      setTime(time);
    }

    GetSyncTimeMasterResult::GetSyncTimeMasterResult(CommandBasePtr relatedCommand, double time)
      : CommandResult(CmdName, relatedCommand)
    {

      setTime(time);
    }


    GetSyncTimeMasterResultPtr GetSyncTimeMasterResult::create(double time)
    {
      return std::make_shared<GetSyncTimeMasterResult>(time);
    }

    GetSyncTimeMasterResultPtr GetSyncTimeMasterResult::create(CommandBasePtr relatedCommand, double time)
    {
      return std::make_shared<GetSyncTimeMasterResult>(relatedCommand, time);
    }

    GetSyncTimeMasterResultPtr GetSyncTimeMasterResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSyncTimeMasterResult>(ptr);
    }

    bool GetSyncTimeMasterResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["Time"])
        ;

    }

    std::string GetSyncTimeMasterResult::documentation() const { return Documentation; }


    double GetSyncTimeMasterResult::time() const
    {
      return parse_json<double>::parse(m_values["Time"]);
    }

    void GetSyncTimeMasterResult::setTime(double time)
    {
      m_values.AddMember("Time", parse_json<double>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
