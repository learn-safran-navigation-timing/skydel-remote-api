
#include "gen/EnableMultipath.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableMultipath
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableMultipath::CmdName = "EnableMultipath";
    const char* const EnableMultipath::Documentation = "Enable/Disable a multipath signal.";

    REGISTER_COMMAND_FACTORY(EnableMultipath);


    EnableMultipath::EnableMultipath()
      : CommandBase(CmdName)
    {}

    EnableMultipath::EnableMultipath(bool enabled, const std::string& id)
      : CommandBase(CmdName)
    {

      setEnabled(enabled);
      setId(id);
    }

    EnableMultipathPtr EnableMultipath::create(bool enabled, const std::string& id)
    {
      return std::make_shared<EnableMultipath>(enabled, id);
    }

    EnableMultipathPtr EnableMultipath::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableMultipath>(ptr);
    }

    bool EnableMultipath::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string EnableMultipath::documentation() const { return Documentation; }


    int EnableMultipath::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    bool EnableMultipath::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableMultipath::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string EnableMultipath::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void EnableMultipath::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
