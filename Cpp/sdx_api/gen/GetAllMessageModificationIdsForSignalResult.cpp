
#include "GetAllMessageModificationIdsForSignalResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllMessageModificationIdsForSignalResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllMessageModificationIdsForSignalResult::CmdName = "GetAllMessageModificationIdsForSignalResult";
    const char* const GetAllMessageModificationIdsForSignalResult::Documentation = "Result of GetAllMessageModificationIdsForSignal.\n"
      "\n"
      "Name Type         Description\n"
      "---- ------------ -------------------------------------------------------------------------\n"
      "Ids  array string List of event IDs which will modify the navigation message for this SV ID";
    const char* const GetAllMessageModificationIdsForSignalResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAllMessageModificationIdsForSignalResult);


    GetAllMessageModificationIdsForSignalResult::GetAllMessageModificationIdsForSignalResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetAllMessageModificationIdsForSignalResult::GetAllMessageModificationIdsForSignalResult(const std::vector<std::string>& ids)
      : CommandResult(CmdName, TargetId)
    {

      setIds(ids);
    }

    GetAllMessageModificationIdsForSignalResult::GetAllMessageModificationIdsForSignalResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& GetAllMessageModificationIdsForSignalResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Ids"}; 
      return names; 
    }


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
