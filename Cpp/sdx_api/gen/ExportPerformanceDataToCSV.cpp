
#include "gen/ExportPerformanceDataToCSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ExportPerformanceDataToCSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ExportPerformanceDataToCSV::CmdName = "ExportPerformanceDataToCSV";
    const char* const ExportPerformanceDataToCSV::Documentation = "Export the performance graph data into a csv file.";

    REGISTER_COMMAND_FACTORY(ExportPerformanceDataToCSV);


    ExportPerformanceDataToCSV::ExportPerformanceDataToCSV()
      : CommandBase(CmdName)
    {}

    ExportPerformanceDataToCSV::ExportPerformanceDataToCSV(const std::string& path, bool overwriting)
      : CommandBase(CmdName)
    {

      setPath(path);
      setOverwriting(overwriting);
    }

    ExportPerformanceDataToCSVPtr ExportPerformanceDataToCSV::create(const std::string& path, bool overwriting)
    {
      return std::make_shared<ExportPerformanceDataToCSV>(path, overwriting);
    }

    ExportPerformanceDataToCSVPtr ExportPerformanceDataToCSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ExportPerformanceDataToCSV>(ptr);
    }

    bool ExportPerformanceDataToCSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Path"])
          && parse_json<bool>::is_valid(m_values["Overwriting"])
        ;

    }

    std::string ExportPerformanceDataToCSV::documentation() const { return Documentation; }


    int ExportPerformanceDataToCSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string ExportPerformanceDataToCSV::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void ExportPerformanceDataToCSV::setPath(const std::string& path)
    {
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool ExportPerformanceDataToCSV::overwriting() const
    {
      return parse_json<bool>::parse(m_values["Overwriting"]);
    }

    void ExportPerformanceDataToCSV::setOverwriting(bool overwriting)
    {
      m_values.AddMember("Overwriting", parse_json<bool>::format(overwriting, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
