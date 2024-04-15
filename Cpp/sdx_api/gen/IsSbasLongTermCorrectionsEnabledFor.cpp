
#include "IsSbasLongTermCorrectionsEnabledFor.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSbasLongTermCorrectionsEnabledFor
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSbasLongTermCorrectionsEnabledFor::CmdName = "IsSbasLongTermCorrectionsEnabledFor";
    const char* const IsSbasLongTermCorrectionsEnabledFor::Documentation = "Get whether ephemeris errors for this constellation should be compensated in SBAS long term corrections.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ -------------------------------------\n"
      "System string As of today, only \"GPS\" is supported.";
    const char* const IsSbasLongTermCorrectionsEnabledFor::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsSbasLongTermCorrectionsEnabledFor);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSbasLongTermCorrectionsEnabledFor);


    IsSbasLongTermCorrectionsEnabledFor::IsSbasLongTermCorrectionsEnabledFor()
      : CommandBase(CmdName, TargetId)
    {}

    IsSbasLongTermCorrectionsEnabledFor::IsSbasLongTermCorrectionsEnabledFor(const std::string& system)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
    }

    IsSbasLongTermCorrectionsEnabledForPtr IsSbasLongTermCorrectionsEnabledFor::create(const std::string& system)
    {
      return std::make_shared<IsSbasLongTermCorrectionsEnabledFor>(system);
    }

    IsSbasLongTermCorrectionsEnabledForPtr IsSbasLongTermCorrectionsEnabledFor::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSbasLongTermCorrectionsEnabledFor>(ptr);
    }

    bool IsSbasLongTermCorrectionsEnabledFor::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string IsSbasLongTermCorrectionsEnabledFor::documentation() const { return Documentation; }

    const std::vector<std::string>& IsSbasLongTermCorrectionsEnabledFor::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System"}; 
      return names; 
    }


    int IsSbasLongTermCorrectionsEnabledFor::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    std::string IsSbasLongTermCorrectionsEnabledFor::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsSbasLongTermCorrectionsEnabledFor::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
