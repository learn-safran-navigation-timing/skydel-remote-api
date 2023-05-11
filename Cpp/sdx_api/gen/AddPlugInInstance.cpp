
#include "gen/AddPlugInInstance.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of AddPlugInInstance
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const AddPlugInInstance::CmdName = "AddPlugInInstance";
    const char* const AddPlugInInstance::Documentation = "Add a plug-in instance of specified type.";

    REGISTER_COMMAND_FACTORY(AddPlugInInstance);


    AddPlugInInstance::AddPlugInInstance()
      : CommandBase(CmdName)
    {}

    AddPlugInInstance::AddPlugInInstance(const std::string& name, const std::string& type)
      : CommandBase(CmdName)
    {

      setName(name);
      setType(type);
    }

    AddPlugInInstancePtr AddPlugInInstance::create(const std::string& name, const std::string& type)
    {
      return std::make_shared<AddPlugInInstance>(name, type);
    }

    AddPlugInInstancePtr AddPlugInInstance::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<AddPlugInInstance>(ptr);
    }

    bool AddPlugInInstance::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Name"])
          && parse_json<std::string>::is_valid(m_values["Type"])
        ;

    }

    std::string AddPlugInInstance::documentation() const { return Documentation; }


    int AddPlugInInstance::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string AddPlugInInstance::name() const
    {
      return parse_json<std::string>::parse(m_values["Name"]);
    }

    void AddPlugInInstance::setName(const std::string& name)
    {
      m_values.AddMember("Name", parse_json<std::string>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string AddPlugInInstance::type() const
    {
      return parse_json<std::string>::parse(m_values["Type"]);
    }

    void AddPlugInInstance::setType(const std::string& type)
    {
      m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
