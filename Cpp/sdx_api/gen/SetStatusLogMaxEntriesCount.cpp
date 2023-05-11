
#include "gen/SetStatusLogMaxEntriesCount.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetStatusLogMaxEntriesCount
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetStatusLogMaxEntriesCount::CmdName = "SetStatusLogMaxEntriesCount";
    const char* const SetStatusLogMaxEntriesCount::Documentation = "When SetStatusLogMaxEntriesCountMode is set to \"Custom\", this commands sets the maximum number of entries in the Status Log. Default value is 1000 entries.";

    REGISTER_COMMAND_FACTORY(SetStatusLogMaxEntriesCount);


    SetStatusLogMaxEntriesCount::SetStatusLogMaxEntriesCount()
      : CommandBase(CmdName)
    {}

    SetStatusLogMaxEntriesCount::SetStatusLogMaxEntriesCount(int maxCount)
      : CommandBase(CmdName)
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
