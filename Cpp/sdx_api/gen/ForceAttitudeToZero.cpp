
#include "ForceAttitudeToZero.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ForceAttitudeToZero
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ForceAttitudeToZero::CmdName = "ForceAttitudeToZero";
    const char* const ForceAttitudeToZero::Documentation = "Set force vehicle yaw, pitch and roll to zero enabled or disabled\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- -----------------------------------------------\n"
      "Enabled bool If true, vehicle won't rotate during simulation";
    const char* const ForceAttitudeToZero::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ForceAttitudeToZero);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ForceAttitudeToZero);


    ForceAttitudeToZero::ForceAttitudeToZero()
      : CommandBase(CmdName, TargetId)
    {}

    ForceAttitudeToZero::ForceAttitudeToZero(bool enabled)
      : CommandBase(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    ForceAttitudeToZeroPtr ForceAttitudeToZero::create(bool enabled)
    {
      return std::make_shared<ForceAttitudeToZero>(enabled);
    }

    ForceAttitudeToZeroPtr ForceAttitudeToZero::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ForceAttitudeToZero>(ptr);
    }

    bool ForceAttitudeToZero::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string ForceAttitudeToZero::documentation() const { return Documentation; }

    const std::vector<std::string>& ForceAttitudeToZero::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


    int ForceAttitudeToZero::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool ForceAttitudeToZero::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void ForceAttitudeToZero::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
