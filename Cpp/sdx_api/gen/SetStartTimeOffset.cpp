
#include "gen/SetStartTimeOffset.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetStartTimeOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetStartTimeOffset::CmdName = "SetStartTimeOffset";
    const char* const SetStartTimeOffset::Documentation = "Set offset between the simulated GPS time and time given by GPS Timing receiver when using GPS Timing receiver to set the start time of the simulation.\nThis value has no effect when GPS start time is \"custom\" or \"computer\".";

    REGISTER_COMMAND_FACTORY(SetStartTimeOffset);


    SetStartTimeOffset::SetStartTimeOffset()
      : CommandBase(CmdName)
    {}

    SetStartTimeOffset::SetStartTimeOffset(int offset)
      : CommandBase(CmdName)
    {

      setOffset(offset);
    }

    SetStartTimeOffsetPtr SetStartTimeOffset::create(int offset)
    {
      return std::make_shared<SetStartTimeOffset>(offset);
    }

    SetStartTimeOffsetPtr SetStartTimeOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetStartTimeOffset>(ptr);
    }

    bool SetStartTimeOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Offset"])
        ;

    }

    std::string SetStartTimeOffset::documentation() const { return Documentation; }


    int SetStartTimeOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetStartTimeOffset::offset() const
    {
      return parse_json<int>::parse(m_values["Offset"]);
    }

    void SetStartTimeOffset::setOffset(int offset)
    {
      m_values.AddMember("Offset", parse_json<int>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
