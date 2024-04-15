
#include "AddCustomSignal.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of AddCustomSignal
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const AddCustomSignal::CmdName = "AddCustomSignal";
    const char* const AddCustomSignal::Documentation = "Adds a custom signal\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------------------------\n"
      "Path string Path to the custom signal XML file\n"
      "Id   string Unique identifier automatically set by simulator";
    const char* const AddCustomSignal::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(AddCustomSignal);
    REGISTER_COMMAND_TO_FACTORY_IMPL(AddCustomSignal);


    AddCustomSignal::AddCustomSignal()
      : CommandBase(CmdName, TargetId)
    {}

    AddCustomSignal::AddCustomSignal(const std::string& path, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setPath(path);
      setId(id);
    }

    AddCustomSignalPtr AddCustomSignal::create(const std::string& path, const std::string& id)
    {
      return std::make_shared<AddCustomSignal>(path, id);
    }

    AddCustomSignalPtr AddCustomSignal::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<AddCustomSignal>(ptr);
    }

    bool AddCustomSignal::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Path"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string AddCustomSignal::documentation() const { return Documentation; }

    const std::vector<std::string>& AddCustomSignal::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Path", "Id"}; 
      return names; 
    }


    int AddCustomSignal::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string AddCustomSignal::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void AddCustomSignal::setPath(const std::string& path)
    {
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string AddCustomSignal::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void AddCustomSignal::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
