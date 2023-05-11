
#include "gen/GetAllMessageModificationIdsForSignalResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllMessageModificationIdsForSignalResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllMessageModificationIdsForSignalResult::CmdName = "GetAllMessageModificationIdsForSignalResult";
    const char* const GetAllMessageModificationIdsForSignalResult::Documentation = "Result of GetAllMessageModificationIdsForSignal.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetAllMessageModificationIdsForSignalResult);


    GetAllMessageModificationIdsForSignalResult::GetAllMessageModificationIdsForSignalResult()
      : CommandResult(CmdName)
    {}

    GetAllMessageModificationIdsForSignalResult::GetAllMessageModificationIdsForSignalResult(const std::vector<std::string>& ids)
      : CommandResult(CmdName)
    {

      setIds(ids);
    }

    GetAllMessageModificationIdsForSignalResult::GetAllMessageModificationIdsForSignalResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
      : CommandResult(CmdName, relatedCommand)
    {

      setIds(ids);
    }


    GetAllMessageModificationIdsForSignalResultPtr GetAllMessageModificationIdsForSignalResult::create(const std::vector<std::string>& ids)
    {
      return std::make_shared<GetAllMessageModificationIdsForSignalResult>(ids);
    }

    GetAllMessageModificationIdsForSignalResultPtr GetAllMessageModificationIdsForSignalResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
    {
      return std::make_shared<GetAllMessageModificationIdsForSignalResult>(relatedCommand, ids);
    }

    GetAllMessageModificationIdsForSignalResultPtr GetAllMessageModificationIdsForSignalResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllMessageModificationIdsForSignalResult>(ptr);
    }

    bool GetAllMessageModificationIdsForSignalResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Ids"])
        ;

    }

    std::string GetAllMessageModificationIdsForSignalResult::documentation() const { return Documentation; }


    std::vector<std::string> GetAllMessageModificationIdsForSignalResult::ids() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Ids"]);
    }

    void GetAllMessageModificationIdsForSignalResult::setIds(const std::vector<std::string>& ids)
    {
      m_values.AddMember("Ids", parse_json<std::vector<std::string>>::format(ids, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
