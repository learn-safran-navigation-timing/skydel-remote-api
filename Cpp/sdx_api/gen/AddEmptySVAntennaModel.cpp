
#include "gen/AddEmptySVAntennaModel.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of AddEmptySVAntennaModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const AddEmptySVAntennaModel::CmdName = "AddEmptySVAntennaModel";
    const char* const AddEmptySVAntennaModel::Documentation = "Create an empty space vehicle antenna model.";

    REGISTER_COMMAND_FACTORY(AddEmptySVAntennaModel);


    AddEmptySVAntennaModel::AddEmptySVAntennaModel()
      : CommandBase(CmdName)
    {}

    AddEmptySVAntennaModel::AddEmptySVAntennaModel(const std::string& name, const std::string& system)
      : CommandBase(CmdName)
    {

      setName(name);
      setSystem(system);
    }

    AddEmptySVAntennaModelPtr AddEmptySVAntennaModel::create(const std::string& name, const std::string& system)
    {
      return std::make_shared<AddEmptySVAntennaModel>(name, system);
    }

    AddEmptySVAntennaModelPtr AddEmptySVAntennaModel::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<AddEmptySVAntennaModel>(ptr);
    }

    bool AddEmptySVAntennaModel::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Name"])
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string AddEmptySVAntennaModel::documentation() const { return Documentation; }


    int AddEmptySVAntennaModel::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string AddEmptySVAntennaModel::name() const
    {
      return parse_json<std::string>::parse(m_values["Name"]);
    }

    void AddEmptySVAntennaModel::setName(const std::string& name)
    {
      m_values.AddMember("Name", parse_json<std::string>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string AddEmptySVAntennaModel::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void AddEmptySVAntennaModel::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
