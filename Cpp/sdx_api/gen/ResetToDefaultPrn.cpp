
#include "ResetToDefaultPrn.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ResetToDefaultPrn
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ResetToDefaultPrn::CmdName = "ResetToDefaultPrn";
    const char* const ResetToDefaultPrn::Documentation = "Reset the PRNs of all satellites in specified system, for all signals.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ --------------------------------------------------------------------------\n"
      "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
    const char* const ResetToDefaultPrn::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ResetToDefaultPrn);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ResetToDefaultPrn);


    ResetToDefaultPrn::ResetToDefaultPrn()
      : CommandBase(CmdName, TargetId)
    {}

    ResetToDefaultPrn::ResetToDefaultPrn(const std::string& system)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& ResetToDefaultPrn::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System"}; 
      return names; 
    }


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
