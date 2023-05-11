
#include "gen/DeleteSVAntennaModel.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of DeleteSVAntennaModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const DeleteSVAntennaModel::CmdName = "DeleteSVAntennaModel";
    const char* const DeleteSVAntennaModel::Documentation = "Delete a space vehicle antenna model. The default SV antenna model can't be deleted.";

    REGISTER_COMMAND_FACTORY(DeleteSVAntennaModel);


    DeleteSVAntennaModel::DeleteSVAntennaModel()
      : CommandBase(CmdName)
    {}

    DeleteSVAntennaModel::DeleteSVAntennaModel(const std::string& name, const std::string& system)
      : CommandBase(CmdName)
    {

      setName(name);
      setSystem(system);
    }

    DeleteSVAntennaModelPtr DeleteSVAntennaModel::create(const std::string& name, const std::string& system)
    {
      return std::make_shared<DeleteSVAntennaModel>(name, system);
    }

    DeleteSVAntennaModelPtr DeleteSVAntennaModel::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<DeleteSVAntennaModel>(ptr);
    }

    bool DeleteSVAntennaModel::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Name"])
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string DeleteSVAntennaModel::documentation() const { return Documentation; }


    int DeleteSVAntennaModel::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string DeleteSVAntennaModel::name() const
    {
      return parse_json<std::string>::parse(m_values["Name"]);
    }

    void DeleteSVAntennaModel::setName(const std::string& name)
    {
      m_values.AddMember("Name", parse_json<std::string>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string DeleteSVAntennaModel::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void DeleteSVAntennaModel::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
