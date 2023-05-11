
#include "gen/RemovePlugInInstance.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemovePlugInInstance
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemovePlugInInstance::CmdName = "RemovePlugInInstance";
    const char* const RemovePlugInInstance::Documentation = "Removes the plug-in instance.";

    REGISTER_COMMAND_FACTORY(RemovePlugInInstance);


    RemovePlugInInstance::RemovePlugInInstance()
      : CommandBase(CmdName)
    {}

    RemovePlugInInstance::RemovePlugInInstance(const std::string& name)
      : CommandBase(CmdName)
    {

      setName(name);
    }

    RemovePlugInInstancePtr RemovePlugInInstance::create(const std::string& name)
    {
      return std::make_shared<RemovePlugInInstance>(name);
    }

    RemovePlugInInstancePtr RemovePlugInInstance::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemovePlugInInstance>(ptr);
    }

    bool RemovePlugInInstance::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Name"])
        ;

    }

    std::string RemovePlugInInstance::documentation() const { return Documentation; }


    int RemovePlugInInstance::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemovePlugInInstance::name() const
    {
      return parse_json<std::string>::parse(m_values["Name"]);
    }

    void RemovePlugInInstance::setName(const std::string& name)
    {
      m_values.AddMember("Name", parse_json<std::string>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
