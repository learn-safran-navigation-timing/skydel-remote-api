
#include "GetAllModulationTargetsResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllModulationTargetsResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllModulationTargetsResult::CmdName = "GetAllModulationTargetsResult";
    const char* const GetAllModulationTargetsResult::Documentation = "Result of GetAllModulationTargets.\n"
      "\n"
      "Name Type         Description\n"
      "---- ------------ ---------------\n"
      "Ids  array string list of all IDs";
    const char* const GetAllModulationTargetsResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAllModulationTargetsResult);


    GetAllModulationTargetsResult::GetAllModulationTargetsResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetAllModulationTargetsResult::GetAllModulationTargetsResult(const std::vector<std::string>& ids)
      : CommandResult(CmdName, TargetId)
    {

      setIds(ids);
    }

    GetAllModulationTargetsResult::GetAllModulationTargetsResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setIds(ids);
    }


    GetAllModulationTargetsResultPtr GetAllModulationTargetsResult::create(const std::vector<std::string>& ids)
    {
      return std::make_shared<GetAllModulationTargetsResult>(ids);
    }

    GetAllModulationTargetsResultPtr GetAllModulationTargetsResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
    {
      return std::make_shared<GetAllModulationTargetsResult>(relatedCommand, ids);
    }

    GetAllModulationTargetsResultPtr GetAllModulationTargetsResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllModulationTargetsResult>(ptr);
    }

    bool GetAllModulationTargetsResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Ids"])
        ;

    }

    std::string GetAllModulationTargetsResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetAllModulationTargetsResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Ids"}; 
      return names; 
    }


    std::vector<std::string> GetAllModulationTargetsResult::ids() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Ids"]);
    }

    void GetAllModulationTargetsResult::setIds(const std::vector<std::string>& ids)
    {
      m_values.AddMember("Ids", parse_json<std::vector<std::string>>::format(ids, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
