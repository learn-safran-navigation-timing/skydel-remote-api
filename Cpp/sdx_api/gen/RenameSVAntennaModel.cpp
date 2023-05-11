
#include "gen/RenameSVAntennaModel.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RenameSVAntennaModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RenameSVAntennaModel::CmdName = "RenameSVAntennaModel";
    const char* const RenameSVAntennaModel::Documentation = "Rename a space vehicle antenna model.";

    REGISTER_COMMAND_FACTORY(RenameSVAntennaModel);


    RenameSVAntennaModel::RenameSVAntennaModel()
      : CommandBase(CmdName)
    {}

    RenameSVAntennaModel::RenameSVAntennaModel(const std::string& name, const std::string& newName, const std::string& system)
      : CommandBase(CmdName)
    {

      setName(name);
      setNewName(newName);
      setSystem(system);
    }

    RenameSVAntennaModelPtr RenameSVAntennaModel::create(const std::string& name, const std::string& newName, const std::string& system)
    {
      return std::make_shared<RenameSVAntennaModel>(name, newName, system);
    }

    RenameSVAntennaModelPtr RenameSVAntennaModel::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RenameSVAntennaModel>(ptr);
    }

    bool RenameSVAntennaModel::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Name"])
          && parse_json<std::string>::is_valid(m_values["NewName"])
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string RenameSVAntennaModel::documentation() const { return Documentation; }


    int RenameSVAntennaModel::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RenameSVAntennaModel::name() const
    {
      return parse_json<std::string>::parse(m_values["Name"]);
    }

    void RenameSVAntennaModel::setName(const std::string& name)
    {
      m_values.AddMember("Name", parse_json<std::string>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string RenameSVAntennaModel::newName() const
    {
      return parse_json<std::string>::parse(m_values["NewName"]);
    }

    void RenameSVAntennaModel::setNewName(const std::string& newName)
    {
      m_values.AddMember("NewName", parse_json<std::string>::format(newName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string RenameSVAntennaModel::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void RenameSVAntennaModel::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
