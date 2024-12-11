
#include "SetDynamicRangeOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetDynamicRangeOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetDynamicRangeOffset::CmdName = "SetDynamicRangeOffset";
    const char* const SetDynamicRangeOffset::Documentation = "Set the GNSS dynamic range offset. Changing this value shifts the dynamic power range available for GNSS signals. Increasing this value allows to simulate higher power signals and avoid IQ overflows. The range of the satellite power sliders in the Constellation tab is shifted by this offset.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ----------------------------------------------------------------\n"
      "Offset double Dynamic Range Offset (dB). Value must be between -10 and +45 dB.";
    const char* const SetDynamicRangeOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetDynamicRangeOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetDynamicRangeOffset);


    SetDynamicRangeOffset::SetDynamicRangeOffset()
      : CommandBase(CmdName, TargetId)
    {}

    SetDynamicRangeOffset::SetDynamicRangeOffset(double offset)
      : CommandBase(CmdName, TargetId)
    {

      setOffset(offset);
    }

    SetDynamicRangeOffsetPtr SetDynamicRangeOffset::create(double offset)
    {
      return std::make_shared<SetDynamicRangeOffset>(offset);
    }

    SetDynamicRangeOffsetPtr SetDynamicRangeOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetDynamicRangeOffset>(ptr);
    }

    bool SetDynamicRangeOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["Offset"])
        ;

    }

    std::string SetDynamicRangeOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& SetDynamicRangeOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Offset"}; 
      return names; 
    }


    int SetDynamicRangeOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    double SetDynamicRangeOffset::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void SetDynamicRangeOffset::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
