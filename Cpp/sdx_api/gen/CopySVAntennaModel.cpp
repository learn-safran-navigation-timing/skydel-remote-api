
#include "gen/CopySVAntennaModel.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of CopySVAntennaModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const CopySVAntennaModel::CmdName = "CopySVAntennaModel";
    const char* const CopySVAntennaModel::Documentation = "Copy a space vehicle antenna model.";

    REGISTER_COMMAND_FACTORY(CopySVAntennaModel);


    CopySVAntennaModel::CopySVAntennaModel()
      : CommandBase(CmdName)
    {}

    CopySVAntennaModel::CopySVAntennaModel(const std::string& name, const std::string& copyName, const std::string& system)
      : CommandBase(CmdName)
    {

      setName(name);
      setCopyName(copyName);
      setSystem(system);
    }

    CopySVAntennaModelPtr CopySVAntennaModel::create(const std::string& name, const std::string& copyName, const std::string& system)
    {
      return std::make_shared<CopySVAntennaModel>(name, copyName, system);
    }

    CopySVAntennaModelPtr CopySVAntennaModel::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<CopySVAntennaModel>(ptr);
    }

    bool CopySVAntennaModel::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Name"])
          && parse_json<std::string>::is_valid(m_values["CopyName"])
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string CopySVAntennaModel::documentation() const { return Documentation; }


    int CopySVAntennaModel::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string CopySVAntennaModel::name() const
    {
      return parse_json<std::string>::parse(m_values["Name"]);
    }

    void CopySVAntennaModel::setName(const std::string& name)
    {
      m_values.AddMember("Name", parse_json<std::string>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string CopySVAntennaModel::copyName() const
    {
      return parse_json<std::string>::parse(m_values["CopyName"]);
    }

    void CopySVAntennaModel::setCopyName(const std::string& copyName)
    {
      m_values.AddMember("CopyName", parse_json<std::string>::format(copyName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string CopySVAntennaModel::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void CopySVAntennaModel::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
