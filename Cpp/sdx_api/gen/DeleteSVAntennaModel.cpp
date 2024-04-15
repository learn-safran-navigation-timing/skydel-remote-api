
#include "DeleteSVAntennaModel.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of DeleteSVAntennaModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const DeleteSVAntennaModel::CmdName = "DeleteSVAntennaModel";
    const char* const DeleteSVAntennaModel::Documentation = "Delete a space vehicle antenna model. The default SV antenna model can't be deleted.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ --------------------------------------------------------------------------\n"
      "Name   string SV antenna model name\n"
      "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
    const char* const DeleteSVAntennaModel::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(DeleteSVAntennaModel);
    REGISTER_COMMAND_TO_FACTORY_IMPL(DeleteSVAntennaModel);


    DeleteSVAntennaModel::DeleteSVAntennaModel()
      : CommandBase(CmdName, TargetId)
    {}

    DeleteSVAntennaModel::DeleteSVAntennaModel(const std::string& name, const std::string& system)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& DeleteSVAntennaModel::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Name", "System"}; 
      return names; 
    }


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
