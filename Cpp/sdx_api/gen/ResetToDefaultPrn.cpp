
#include "gen/ResetToDefaultPrn.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ResetToDefaultPrn
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ResetToDefaultPrn::CmdName = "ResetToDefaultPrn";
    const char* const ResetToDefaultPrn::Documentation = "Reset the PRNs of all satellites in specified system, for all signals.";

    REGISTER_COMMAND_FACTORY(ResetToDefaultPrn);


    ResetToDefaultPrn::ResetToDefaultPrn()
      : CommandBase(CmdName)
    {}

    ResetToDefaultPrn::ResetToDefaultPrn(const std::string& system)
      : CommandBase(CmdName)
    {

      setSystem(system);
    }

    ResetToDefaultPrnPtr ResetToDefaultPrn::create(const std::string& system)
    {
      return std::make_shared<ResetToDefaultPrn>(system);
    }

    ResetToDefaultPrnPtr ResetToDefaultPrn::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ResetToDefaultPrn>(ptr);
    }

    bool ResetToDefaultPrn::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string ResetToDefaultPrn::documentation() const { return Documentation; }


    int ResetToDefaultPrn::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string ResetToDefaultPrn::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void ResetToDefaultPrn::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
