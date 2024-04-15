
#include "RemoveAllPseudorangeRamp.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveAllPseudorangeRamp
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveAllPseudorangeRamp::CmdName = "RemoveAllPseudorangeRamp";
    const char* const RemoveAllPseudorangeRamp::Documentation = "Please note the command RemoveAllPseudorangeRamp is deprecated since 21.3. You may use RemoveAllPseudorangeRampForSystem.\n"
      "\n"
      "Remove all PSR Ramps for all satellites of the specified system.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ --------------------------------------------------------------------------\n"
      "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
    const char* const RemoveAllPseudorangeRamp::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RemoveAllPseudorangeRamp);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RemoveAllPseudorangeRamp);


    RemoveAllPseudorangeRamp::RemoveAllPseudorangeRamp()
      : CommandBase(CmdName, TargetId)
    {}

    RemoveAllPseudorangeRamp::RemoveAllPseudorangeRamp(const std::string& system)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& RemoveAllPseudorangeRamp::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System"}; 
      return names; 
    }


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
