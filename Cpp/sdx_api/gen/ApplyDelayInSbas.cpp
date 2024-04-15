
#include "ApplyDelayInSbas.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ApplyDelayInSbas
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ApplyDelayInSbas::CmdName = "ApplyDelayInSbas";
    const char* const ApplyDelayInSbas::Documentation = "Set whether the ionospheric offsets grid should be used for SBAS corrections in message 26\n"
      "\n"
      "Name      Type Description\n"
      "--------- ---- --------------------------------------------\n"
      "IsEnabled bool True if offsets are applied in Sbas messages";
    const char* const ApplyDelayInSbas::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ApplyDelayInSbas);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ApplyDelayInSbas);


    ApplyDelayInSbas::ApplyDelayInSbas()
      : CommandBase(CmdName, TargetId)
    {}

    ApplyDelayInSbas::ApplyDelayInSbas(bool isEnabled)
      : CommandBase(CmdName, TargetId)
    {

      setIsEnabled(isEnabled);
    }

    ApplyDelayInSbasPtr ApplyDelayInSbas::create(bool isEnabled)
    {
      return std::make_shared<ApplyDelayInSbas>(isEnabled);
    }

    ApplyDelayInSbasPtr ApplyDelayInSbas::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ApplyDelayInSbas>(ptr);
    }

    bool ApplyDelayInSbas::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["IsEnabled"])
        ;

    }

    std::string ApplyDelayInSbas::documentation() const { return Documentation; }

    const std::vector<std::string>& ApplyDelayInSbas::fieldNames() const 
    { 
      static const std::vector<std::string> names {"IsEnabled"}; 
      return names; 
    }


    int ApplyDelayInSbas::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    bool ApplyDelayInSbas::isEnabled() const
    {
      return parse_json<bool>::parse(m_values["IsEnabled"]);
    }

    void ApplyDelayInSbas::setIsEnabled(bool isEnabled)
    {
      m_values.AddMember("IsEnabled", parse_json<bool>::format(isEnabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
