
#include "ImportWFAntenna.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ImportWFAntenna
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ImportWFAntenna::CmdName = "ImportWFAntenna";
    const char* const ImportWFAntenna::Documentation = "Import Wavefront Antenna settings from an XML file.\n"
      "\n"
      "Name     Type   Description\n"
      "-------- ------ -----------------------------------------\n"
      "FilePath string File path for Wavefront Antenna settings.";
    const char* const ImportWFAntenna::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ImportWFAntenna);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ImportWFAntenna);


    ImportWFAntenna::ImportWFAntenna()
      : CommandBase(CmdName, TargetId)
    {}

    ImportWFAntenna::ImportWFAntenna(const std::string& filePath)
      : CommandBase(CmdName, TargetId)
    {

      setFilePath(filePath);
    }

    ImportWFAntennaPtr ImportWFAntenna::create(const std::string& filePath)
    {
      return std::make_shared<ImportWFAntenna>(filePath);
    }

    ImportWFAntennaPtr ImportWFAntenna::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ImportWFAntenna>(ptr);
    }

    bool ImportWFAntenna::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["FilePath"])
        ;

    }

    std::string ImportWFAntenna::documentation() const { return Documentation; }

    const std::vector<std::string>& ImportWFAntenna::fieldNames() const 
    { 
      static const std::vector<std::string> names {"FilePath"}; 
      return names; 
    }


    int ImportWFAntenna::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string ImportWFAntenna::filePath() const
    {
      return parse_json<std::string>::parse(m_values["FilePath"]);
    }

    void ImportWFAntenna::setFilePath(const std::string& filePath)
    {
      m_values.AddMember("FilePath", parse_json<std::string>::format(filePath, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
