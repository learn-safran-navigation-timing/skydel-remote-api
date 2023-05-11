
#include "gen/AddCustomSignal.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of AddCustomSignal
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const AddCustomSignal::CmdName = "AddCustomSignal";
    const char* const AddCustomSignal::Documentation = "Adds a custom signal";

    REGISTER_COMMAND_FACTORY(AddCustomSignal);


    AddCustomSignal::AddCustomSignal()
      : CommandBase(CmdName)
    {}

    AddCustomSignal::AddCustomSignal(const std::string& path, const std::string& id)
      : CommandBase(CmdName)
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
