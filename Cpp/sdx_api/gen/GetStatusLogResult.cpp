
#include "GetStatusLogResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetStatusLogResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetStatusLogResult::CmdName = "GetStatusLogResult";
    const char* const GetStatusLogResult::Documentation = "Result of GetStatusLog.\n"
      "\n"
      "Name    Type            Description\n"
      "------- --------------- ----------------\n"
      "Records array LogRecord The log records.";
    const char* const GetStatusLogResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetStatusLogResult);


    GetStatusLogResult::GetStatusLogResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetStatusLogResult::GetStatusLogResult(const std::vector<Sdx::LogRecord>& records)
      : CommandResult(CmdName, TargetId)
    {

      setRecords(records);
    }

    GetStatusLogResult::GetStatusLogResult(CommandBasePtr relatedCommand, const std::vector<Sdx::LogRecord>& records)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setRecords(records);
    }


    GetStatusLogResultPtr GetStatusLogResult::create(const std::vector<Sdx::LogRecord>& records)
    {
      return std::make_shared<GetStatusLogResult>(records);
    }

    GetStatusLogResultPtr GetStatusLogResult::create(CommandBasePtr relatedCommand, const std::vector<Sdx::LogRecord>& records)
    {
      return std::make_shared<GetStatusLogResult>(relatedCommand, records);
    }

    GetStatusLogResultPtr GetStatusLogResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetStatusLogResult>(ptr);
    }

    bool GetStatusLogResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<Sdx::LogRecord>>::is_valid(m_values["Records"])
        ;

    }

    std::string GetStatusLogResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetStatusLogResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Records"}; 
      return names; 
    }


    std::vector<Sdx::LogRecord> GetStatusLogResult::records() const
    {
      return parse_json<std::vector<Sdx::LogRecord>>::parse(m_values["Records"]);
    }

    void GetStatusLogResult::setRecords(const std::vector<Sdx::LogRecord>& records)
    {
      m_values.AddMember("Records", parse_json<std::vector<Sdx::LogRecord>>::format(records, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
