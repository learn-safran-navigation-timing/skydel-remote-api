
#include "gen/ExportHilGraphDataToCSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ExportHilGraphDataToCSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ExportHilGraphDataToCSV::CmdName = "ExportHilGraphDataToCSV";
    const char* const ExportHilGraphDataToCSV::Documentation = "Export the hil graph data into a csv file.";

    REGISTER_COMMAND_FACTORY(ExportHilGraphDataToCSV);


    ExportHilGraphDataToCSV::ExportHilGraphDataToCSV()
      : CommandBase(CmdName)
    {}

    ExportHilGraphDataToCSV::ExportHilGraphDataToCSV(const std::string& path, bool overwriting)
      : CommandBase(CmdName)
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
