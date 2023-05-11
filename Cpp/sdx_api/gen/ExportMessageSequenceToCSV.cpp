
#include "gen/ExportMessageSequenceToCSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ExportMessageSequenceToCSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ExportMessageSequenceToCSV::CmdName = "ExportMessageSequenceToCSV";
    const char* const ExportMessageSequenceToCSV::Documentation = "Export the signal's message sequence into a csv file.";

    REGISTER_COMMAND_FACTORY(ExportMessageSequenceToCSV);


    ExportMessageSequenceToCSV::ExportMessageSequenceToCSV()
      : CommandBase(CmdName)
    {}

    ExportMessageSequenceToCSV::ExportMessageSequenceToCSV(const std::string& signal, const std::string& path, bool overwriting)
      : CommandBase(CmdName)
    {

      setSignal(signal);
      setPath(path);
      setOverwriting(overwriting);
    }

    ExportMessageSequenceToCSVPtr ExportMessageSequenceToCSV::create(const std::string& signal, const std::string& path, bool overwriting)
    {
      return std::make_shared<ExportMessageSequenceToCSV>(signal, path, overwriting);
    }

    ExportMessageSequenceToCSVPtr ExportMessageSequenceToCSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ExportMessageSequenceToCSV>(ptr);
    }

    bool ExportMessageSequenceToCSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<std::string>::is_valid(m_values["Path"])
          && parse_json<bool>::is_valid(m_values["Overwriting"])
        ;

    }

    std::string ExportMessageSequenceToCSV::documentation() const { return Documentation; }


    int ExportMessageSequenceToCSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string ExportMessageSequenceToCSV::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void ExportMessageSequenceToCSV::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ExportMessageSequenceToCSV::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void ExportMessageSequenceToCSV::setPath(const std::string& path)
    {
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool ExportMessageSequenceToCSV::overwriting() const
    {
      return parse_json<bool>::parse(m_values["Overwriting"]);
    }

    void ExportMessageSequenceToCSV::setOverwriting(bool overwriting)
    {
      m_values.AddMember("Overwriting", parse_json<bool>::format(overwriting, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
