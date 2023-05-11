
#include "gen/IsSbasLongTermCorrectionsEnabledFor.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSbasLongTermCorrectionsEnabledFor
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSbasLongTermCorrectionsEnabledFor::CmdName = "IsSbasLongTermCorrectionsEnabledFor";
    const char* const IsSbasLongTermCorrectionsEnabledFor::Documentation = "Get whether ephemeris errors for this constellation should be compensated in SBAS long term corrections.";

    REGISTER_COMMAND_FACTORY(IsSbasLongTermCorrectionsEnabledFor);


    IsSbasLongTermCorrectionsEnabledFor::IsSbasLongTermCorrectionsEnabledFor()
      : CommandBase(CmdName)
    {}

    IsSbasLongTermCorrectionsEnabledFor::IsSbasLongTermCorrectionsEnabledFor(const std::string& system)
      : CommandBase(CmdName)
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
