
#include "gen/RemoveAllPseudorangeRamp.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveAllPseudorangeRamp
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveAllPseudorangeRamp::CmdName = "RemoveAllPseudorangeRamp";
    const char* const RemoveAllPseudorangeRamp::Documentation = "Please note the command RemoveAllPseudorangeRamp is deprecated since 21.3. You may use RemoveAllPseudorangeRampForSystem.\n\nRemove all PSR Ramps for all satellites of the specified system.";

    REGISTER_COMMAND_FACTORY(RemoveAllPseudorangeRamp);


    RemoveAllPseudorangeRamp::RemoveAllPseudorangeRamp()
      : CommandBase(CmdName)
    {}

    RemoveAllPseudorangeRamp::RemoveAllPseudorangeRamp(const std::string& system)
      : CommandBase(CmdName)
    {

      setSystem(system);
    }

    RemoveAllPseudorangeRampPtr RemoveAllPseudorangeRamp::create(const std::string& system)
    {
      return std::make_shared<RemoveAllPseudorangeRamp>(system);
    }

    RemoveAllPseudorangeRampPtr RemoveAllPseudorangeRamp::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveAllPseudorangeRamp>(ptr);
    }

    bool RemoveAllPseudorangeRamp::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string RemoveAllPseudorangeRamp::documentation() const { return Documentation; }


    int RemoveAllPseudorangeRamp::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveAllPseudorangeRamp::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void RemoveAllPseudorangeRamp::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
