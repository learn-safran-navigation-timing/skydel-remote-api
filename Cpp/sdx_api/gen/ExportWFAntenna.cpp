
#include "gen/ExportWFAntenna.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ExportWFAntenna
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ExportWFAntenna::CmdName = "ExportWFAntenna";
    const char* const ExportWFAntenna::Documentation = "Export Wavefront Antenna settings to an XML file.";

    REGISTER_COMMAND_FACTORY(ExportWFAntenna);


    ExportWFAntenna::ExportWFAntenna()
      : CommandBase(CmdName)
    {}

    ExportWFAntenna::ExportWFAntenna(const std::string& filePath, bool overwriteFile)
      : CommandBase(CmdName)
    {

      setFilePath(filePath);
      setOverwriteFile(overwriteFile);
    }

    ExportWFAntennaPtr ExportWFAntenna::create(const std::string& filePath, bool overwriteFile)
    {
      return std::make_shared<ExportWFAntenna>(filePath, overwriteFile);
    }

    ExportWFAntennaPtr ExportWFAntenna::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ExportWFAntenna>(ptr);
    }

    bool ExportWFAntenna::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["FilePath"])
          && parse_json<bool>::is_valid(m_values["OverwriteFile"])
        ;

    }

    std::string ExportWFAntenna::documentation() const { return Documentation; }


    int ExportWFAntenna::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string ExportWFAntenna::filePath() const
    {
      return parse_json<std::string>::parse(m_values["FilePath"]);
    }

    void ExportWFAntenna::setFilePath(const std::string& filePath)
    {
      m_values.AddMember("FilePath", parse_json<std::string>::format(filePath, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool ExportWFAntenna::overwriteFile() const
    {
      return parse_json<bool>::parse(m_values["OverwriteFile"]);
    }

    void ExportWFAntenna::setOverwriteFile(bool overwriteFile)
    {
      m_values.AddMember("OverwriteFile", parse_json<bool>::format(overwriteFile, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
