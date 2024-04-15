
#include "GetAllMessageModificationIdsForNavMsgFamilyResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllMessageModificationIdsForNavMsgFamilyResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllMessageModificationIdsForNavMsgFamilyResult::CmdName = "GetAllMessageModificationIdsForNavMsgFamilyResult";
    const char* const GetAllMessageModificationIdsForNavMsgFamilyResult::Documentation = "Result of GetAllMessageModificationIdsForNavMsgFamily.\n"
      "\n"
      "Name Type         Description\n"
      "---- ------------ -------------------------------------------------------------------------\n"
      "Ids  array string List of event IDs which will modify the navigation message for this SV ID";
    const char* const GetAllMessageModificationIdsForNavMsgFamilyResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAllMessageModificationIdsForNavMsgFamilyResult);


    GetAllMessageModificationIdsForNavMsgFamilyResult::GetAllMessageModificationIdsForNavMsgFamilyResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetAllMessageModificationIdsForNavMsgFamilyResult::GetAllMessageModificationIdsForNavMsgFamilyResult(const std::vector<std::string>& ids)
      : CommandResult(CmdName, TargetId)
    {

      setIds(ids);
    }

    GetAllMessageModificationIdsForNavMsgFamilyResult::GetAllMessageModificationIdsForNavMsgFamilyResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& GetAllMessageModificationIdsForNavMsgFamilyResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Ids"}; 
      return names; 
    }


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
