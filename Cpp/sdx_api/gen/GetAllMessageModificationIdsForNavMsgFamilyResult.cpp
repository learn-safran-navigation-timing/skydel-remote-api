
#include "gen/GetAllMessageModificationIdsForNavMsgFamilyResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllMessageModificationIdsForNavMsgFamilyResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllMessageModificationIdsForNavMsgFamilyResult::CmdName = "GetAllMessageModificationIdsForNavMsgFamilyResult";
    const char* const GetAllMessageModificationIdsForNavMsgFamilyResult::Documentation = "Result of GetAllMessageModificationIdsForNavMsgFamily.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetAllMessageModificationIdsForNavMsgFamilyResult);


    GetAllMessageModificationIdsForNavMsgFamilyResult::GetAllMessageModificationIdsForNavMsgFamilyResult()
      : CommandResult(CmdName)
    {}

    GetAllMessageModificationIdsForNavMsgFamilyResult::GetAllMessageModificationIdsForNavMsgFamilyResult(const std::vector<std::string>& ids)
      : CommandResult(CmdName)
    {

      setIds(ids);
    }

    GetAllMessageModificationIdsForNavMsgFamilyResult::GetAllMessageModificationIdsForNavMsgFamilyResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
      : CommandResult(CmdName, relatedCommand)
    {

      setIds(ids);
    }


    GetAllMessageModificationIdsForNavMsgFamilyResultPtr GetAllMessageModificationIdsForNavMsgFamilyResult::create(const std::vector<std::string>& ids)
    {
      return std::make_shared<GetAllMessageModificationIdsForNavMsgFamilyResult>(ids);
    }

    GetAllMessageModificationIdsForNavMsgFamilyResultPtr GetAllMessageModificationIdsForNavMsgFamilyResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
    {
      return std::make_shared<GetAllMessageModificationIdsForNavMsgFamilyResult>(relatedCommand, ids);
    }

    GetAllMessageModificationIdsForNavMsgFamilyResultPtr GetAllMessageModificationIdsForNavMsgFamilyResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllMessageModificationIdsForNavMsgFamilyResult>(ptr);
    }

    bool GetAllMessageModificationIdsForNavMsgFamilyResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Ids"])
        ;

    }

    std::string GetAllMessageModificationIdsForNavMsgFamilyResult::documentation() const { return Documentation; }


    std::vector<std::string> GetAllMessageModificationIdsForNavMsgFamilyResult::ids() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Ids"]);
    }

    void GetAllMessageModificationIdsForNavMsgFamilyResult::setIds(const std::vector<std::string>& ids)
    {
      m_values.AddMember("Ids", parse_json<std::vector<std::string>>::format(ids, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
