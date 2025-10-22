
#include "SetDektecTimeOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetDektecTimeOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetDektecTimeOffset::CmdName = "SetDektecTimeOffset";
    const char* const SetDektecTimeOffset::Documentation = "Set a time offset in nanoseconds to be applied to a Dektec radio.\n"
      "\n"
      "Name       Type Description\n"
      "---------- ---- ------------------------------------\n"
      "Output     int  Output index (zero based).\n"
      "TimeOffset int  Time offset to apply in nanoseconds.";
    const char* const SetDektecTimeOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetDektecTimeOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetDektecTimeOffset);


    SetDektecTimeOffset::SetDektecTimeOffset()
      : CommandBase(CmdName, TargetId)
    {}

    SetDektecTimeOffset::SetDektecTimeOffset(int output, int timeOffset)
      : CommandBase(CmdName, TargetId)
    {

      setOutput(output);
      setTimeOffset(timeOffset);
    }

    SetDektecTimeOffsetPtr SetDektecTimeOffset::create(int output, int timeOffset)
    {
      return std::make_shared<SetDektecTimeOffset>(output, timeOffset);
    }

    SetDektecTimeOffsetPtr SetDektecTimeOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetDektecTimeOffset>(ptr);
    }

    bool SetDektecTimeOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Output"])
          && parse_json<int>::is_valid(m_values["TimeOffset"])
        ;

    }

    std::string SetDektecTimeOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& SetDektecTimeOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Output", "TimeOffset"}; 
      return names; 
    }


    int SetDektecTimeOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetDektecTimeOffset::output() const
    {
      return parse_json<int>::parse(m_values["Output"]);
    }

    void SetDektecTimeOffset::setOutput(int output)
    {
      m_values.AddMember("Output", parse_json<int>::format(output, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetDektecTimeOffset::timeOffset() const
    {
      return parse_json<int>::parse(m_values["TimeOffset"]);
    }

    void SetDektecTimeOffset::setTimeOffset(int timeOffset)
    {
      m_values.AddMember("TimeOffset", parse_json<int>::format(timeOffset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
