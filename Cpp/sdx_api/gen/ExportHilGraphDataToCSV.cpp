
#include "ExportHilGraphDataToCSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ExportHilGraphDataToCSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ExportHilGraphDataToCSV::CmdName = "ExportHilGraphDataToCSV";
    const char* const ExportHilGraphDataToCSV::Documentation = "Export the hil graph data into a csv file.\n"
      "\n"
      "Name        Type   Description\n"
      "----------- ------ -----------------------------------------------------------------------------------------------\n"
      "Path        string The full path to the csv file.\n"
      "Overwriting bool   Overwrite an existing file if set to true, return an error if set to false and the file exists.";
    const char* const ExportHilGraphDataToCSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ExportHilGraphDataToCSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ExportHilGraphDataToCSV);


    ExportHilGraphDataToCSV::ExportHilGraphDataToCSV()
      : CommandBase(CmdName, TargetId)
    {}

    ExportHilGraphDataToCSV::ExportHilGraphDataToCSV(const std::string& path, bool overwriting)
      : CommandBase(CmdName, TargetId)
    {

      setPath(path);
      setOverwriting(overwriting);
    }

    ExportHilGraphDataToCSVPtr ExportHilGraphDataToCSV::create(const std::string& path, bool overwriting)
    {
      return std::make_shared<ExportHilGraphDataToCSV>(path, overwriting);
    }

    ExportHilGraphDataToCSVPtr ExportHilGraphDataToCSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ExportHilGraphDataToCSV>(ptr);
    }

    bool ExportHilGraphDataToCSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Path"])
          && parse_json<bool>::is_valid(m_values["Overwriting"])
        ;

    }

    std::string ExportHilGraphDataToCSV::documentation() const { return Documentation; }

    const std::vector<std::string>& ExportHilGraphDataToCSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Path", "Overwriting"}; 
      return names; 
    }


    int ExportHilGraphDataToCSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string ExportHilGraphDataToCSV::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void ExportHilGraphDataToCSV::setPath(const std::string& path)
    {
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool ExportHilGraphDataToCSV::overwriting() const
    {
      return parse_json<bool>::parse(m_values["Overwriting"]);
    }

    void ExportHilGraphDataToCSV::setOverwriting(bool overwriting)
    {
      m_values.AddMember("Overwriting", parse_json<bool>::format(overwriting, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
