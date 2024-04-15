
#include "GetOsnmaMacLtIdResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetOsnmaMacLtIdResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetOsnmaMacLtIdResult::CmdName = "GetOsnmaMacLtIdResult";
    const char* const GetOsnmaMacLtIdResult::Documentation = "Result of GetOsnmaMacLtId.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ---------------------------------------------------------------------------------------------------------------------------\n"
      "MacLtId int  MAC look-up table ID to get associated ADKD sequences. Accepted IDs are: 27, 28, 31, 33, 34, 35, 36, 37, 38, 39, 40 and 41.\n"
      "             Note: The MAC look-up table can be found in Galileo OSNMA SIS ICD v1.1 - ANNEX C MAC Look-up Table.";
    const char* const GetOsnmaMacLtIdResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetOsnmaMacLtIdResult);


    GetOsnmaMacLtIdResult::GetOsnmaMacLtIdResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetOsnmaMacLtIdResult::GetOsnmaMacLtIdResult(int macLtId)
      : CommandResult(CmdName, TargetId)
    {

      setMacLtId(macLtId);
    }

    GetOsnmaMacLtIdResult::GetOsnmaMacLtIdResult(CommandBasePtr relatedCommand, int macLtId)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setMacLtId(macLtId);
    }


    GetOsnmaMacLtIdResultPtr GetOsnmaMacLtIdResult::create(int macLtId)
    {
      return std::make_shared<GetOsnmaMacLtIdResult>(macLtId);
    }

    GetOsnmaMacLtIdResultPtr GetOsnmaMacLtIdResult::create(CommandBasePtr relatedCommand, int macLtId)
    {
      return std::make_shared<GetOsnmaMacLtIdResult>(relatedCommand, macLtId);
    }

    GetOsnmaMacLtIdResultPtr GetOsnmaMacLtIdResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetOsnmaMacLtIdResult>(ptr);
    }

    bool GetOsnmaMacLtIdResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["MacLtId"])
        ;

    }

    std::string GetOsnmaMacLtIdResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetOsnmaMacLtIdResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"MacLtId"}; 
      return names; 
    }


    int GetOsnmaMacLtIdResult::macLtId() const
    {
      return parse_json<int>::parse(m_values["MacLtId"]);
    }

    void GetOsnmaMacLtIdResult::setMacLtId(int macLtId)
    {
      m_values.AddMember("MacLtId", parse_json<int>::format(macLtId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
