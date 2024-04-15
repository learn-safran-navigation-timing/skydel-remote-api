
#include "SetStatusLogMaxEntriesCount.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetStatusLogMaxEntriesCount
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetStatusLogMaxEntriesCount::CmdName = "SetStatusLogMaxEntriesCount";
    const char* const SetStatusLogMaxEntriesCount::Documentation = "When SetStatusLogMaxEntriesCountMode is set to \"Custom\", this commands sets the maximum number of entries in the Status Log. Default value is 1000 entries.\n"
      "\n"
      "Name     Type Description\n"
      "-------- ---- --------------------------\n"
      "MaxCount int  Maximum number of entries.";
    const char* const SetStatusLogMaxEntriesCount::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetStatusLogMaxEntriesCount);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetStatusLogMaxEntriesCount);


    SetStatusLogMaxEntriesCount::SetStatusLogMaxEntriesCount()
      : CommandBase(CmdName, TargetId)
    {}

    SetStatusLogMaxEntriesCount::SetStatusLogMaxEntriesCount(int maxCount)
      : CommandBase(CmdName, TargetId)
    {

      setMaxCount(maxCount);
    }

    SetStatusLogMaxEntriesCountPtr SetStatusLogMaxEntriesCount::create(int maxCount)
    {
      return std::make_shared<SetStatusLogMaxEntriesCount>(maxCount);
    }

    SetStatusLogMaxEntriesCountPtr SetStatusLogMaxEntriesCount::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetStatusLogMaxEntriesCount>(ptr);
    }

    bool SetStatusLogMaxEntriesCount::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["MaxCount"])
        ;

    }

    std::string SetStatusLogMaxEntriesCount::documentation() const { return Documentation; }

    const std::vector<std::string>& SetStatusLogMaxEntriesCount::fieldNames() const 
    { 
      static const std::vector<std::string> names {"MaxCount"}; 
      return names; 
    }


    int SetStatusLogMaxEntriesCount::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    int SetStatusLogMaxEntriesCount::maxCount() const
    {
      return parse_json<int>::parse(m_values["MaxCount"]);
    }

    void SetStatusLogMaxEntriesCount::setMaxCount(int maxCount)
    {
      m_values.AddMember("MaxCount", parse_json<int>::format(maxCount, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
