
#include "SetOsnmaMacLtId.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetOsnmaMacLtId
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetOsnmaMacLtId::CmdName = "SetOsnmaMacLtId";
    const char* const SetOsnmaMacLtId::Documentation = "Set OSNMA MAC look-up table ID.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ---------------------------------------------------------------------------------------------------------------------------\n"
      "MacLtId int  MAC look-up table ID to get associated ADKD sequences. Accepted IDs are: 27, 28, 31, 33, 34, 35, 36, 37, 38, 39, 40 and 41.\n"
      "             Note: The MAC look-up table can be found in Galileo OSNMA SIS ICD v1.1 - ANNEX C MAC Look-up Table.";
    const char* const SetOsnmaMacLtId::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetOsnmaMacLtId);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetOsnmaMacLtId);


    SetOsnmaMacLtId::SetOsnmaMacLtId()
      : CommandBase(CmdName, TargetId)
    {}

    SetOsnmaMacLtId::SetOsnmaMacLtId(int macLtId)
      : CommandBase(CmdName, TargetId)
    {

      setMacLtId(macLtId);
    }

    SetOsnmaMacLtIdPtr SetOsnmaMacLtId::create(int macLtId)
    {
      return std::make_shared<SetOsnmaMacLtId>(macLtId);
    }

    SetOsnmaMacLtIdPtr SetOsnmaMacLtId::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetOsnmaMacLtId>(ptr);
    }

    bool SetOsnmaMacLtId::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["MacLtId"])
        ;

    }

    std::string SetOsnmaMacLtId::documentation() const { return Documentation; }

    const std::vector<std::string>& SetOsnmaMacLtId::fieldNames() const 
    { 
      static const std::vector<std::string> names {"MacLtId"}; 
      return names; 
    }


    int SetOsnmaMacLtId::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetOsnmaMacLtId::macLtId() const
    {
      return parse_json<int>::parse(m_values["MacLtId"]);
    }

    void SetOsnmaMacLtId::setMacLtId(int macLtId)
    {
      m_values.AddMember("MacLtId", parse_json<int>::format(macLtId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
