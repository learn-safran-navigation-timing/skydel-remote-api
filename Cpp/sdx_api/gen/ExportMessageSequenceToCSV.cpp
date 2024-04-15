
#include "ExportMessageSequenceToCSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ExportMessageSequenceToCSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ExportMessageSequenceToCSV::CmdName = "ExportMessageSequenceToCSV";
    const char* const ExportMessageSequenceToCSV::Documentation = "Export the signal's message sequence into a csv file.\n"
      "\n"
      "Name        Type   Description\n"
      "----------- ------ -------------------------------------------------------------------------------------------------\n"
      "Signal      string Signal key (\"L2C\" for example).\n"
      "Path        string The full path to the csv file.\n"
      "Overwriting bool   Overwrites an existing file if set to true, returns an error if set to false and the file exists.";
    const char* const ExportMessageSequenceToCSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ExportMessageSequenceToCSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ExportMessageSequenceToCSV);


    ExportMessageSequenceToCSV::ExportMessageSequenceToCSV()
      : CommandBase(CmdName, TargetId)
    {}

    ExportMessageSequenceToCSV::ExportMessageSequenceToCSV(const std::string& signal, const std::string& path, bool overwriting)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& ExportMessageSequenceToCSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "Path", "Overwriting"}; 
      return names; 
    }


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
