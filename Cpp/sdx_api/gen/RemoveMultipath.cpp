
#include "gen/RemoveMultipath.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveMultipath
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveMultipath::CmdName = "RemoveMultipath";
    const char* const RemoveMultipath::Documentation = "Removes a multipath signal.";

    REGISTER_COMMAND_FACTORY(RemoveMultipath);


    RemoveMultipath::RemoveMultipath()
      : CommandBase(CmdName)
    {}

    RemoveMultipath::RemoveMultipath(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    RemoveMultipathPtr RemoveMultipath::create(const std::string& id)
    {
      return std::make_shared<RemoveMultipath>(id);
    }

    RemoveMultipathPtr RemoveMultipath::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveMultipath>(ptr);
    }

    bool RemoveMultipath::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemoveMultipath::documentation() const { return Documentation; }


    int RemoveMultipath::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string RemoveMultipath::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemoveMultipath::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
