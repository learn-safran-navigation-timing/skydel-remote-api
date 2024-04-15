
#include "GetQzssL1SAugmentationsResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssL1SAugmentationsResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssL1SAugmentationsResult::CmdName = "GetQzssL1SAugmentationsResult";
    const char* const GetQzssL1SAugmentationsResult::Documentation = "Result of GetQzssL1SAugmentations.\n"
      "\n"
      "Name Type         Description\n"
      "---- ------------ --------------------------------------\n"
      "Ids  array string List of IDs of QZSS L1S augmentations.";
    const char* const GetQzssL1SAugmentationsResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssL1SAugmentationsResult);


    GetQzssL1SAugmentationsResult::GetQzssL1SAugmentationsResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetQzssL1SAugmentationsResult::GetQzssL1SAugmentationsResult(const std::vector<std::string>& ids)
      : CommandResult(CmdName, TargetId)
    {

      setIds(ids);
    }

    GetQzssL1SAugmentationsResult::GetQzssL1SAugmentationsResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setIds(ids);
    }


    GetQzssL1SAugmentationsResultPtr GetQzssL1SAugmentationsResult::create(const std::vector<std::string>& ids)
    {
      return std::make_shared<GetQzssL1SAugmentationsResult>(ids);
    }

    GetQzssL1SAugmentationsResultPtr GetQzssL1SAugmentationsResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
    {
      return std::make_shared<GetQzssL1SAugmentationsResult>(relatedCommand, ids);
    }

    GetQzssL1SAugmentationsResultPtr GetQzssL1SAugmentationsResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssL1SAugmentationsResult>(ptr);
    }

    bool GetQzssL1SAugmentationsResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Ids"])
        ;

    }

    std::string GetQzssL1SAugmentationsResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetQzssL1SAugmentationsResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Ids"}; 
      return names; 
    }


    std::vector<std::string> GetQzssL1SAugmentationsResult::ids() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Ids"]);
    }

    void GetQzssL1SAugmentationsResult::setIds(const std::vector<std::string>& ids)
    {
      m_values.AddMember("Ids", parse_json<std::vector<std::string>>::format(ids, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
