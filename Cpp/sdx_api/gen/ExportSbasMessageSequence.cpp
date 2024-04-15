
#include "ExportSbasMessageSequence.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ExportSbasMessageSequence
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ExportSbasMessageSequence::CmdName = "ExportSbasMessageSequence";
    const char* const ExportSbasMessageSequence::Documentation = "Export the SBAS message sequence into a csv file.\n"
      "\n"
      "Name        Type   Description\n"
      "----------- ------ -----------------------------------------------------------------------------------------------\n"
      "Path        string The full path to the csv file.\n"
      "Overwriting bool   Overwrite an existing file if set to true, return an error if set to false and the file exists.";
    const char* const ExportSbasMessageSequence::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ExportSbasMessageSequence);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ExportSbasMessageSequence);


    ExportSbasMessageSequence::ExportSbasMessageSequence()
      : CommandBase(CmdName, TargetId)
    {}

    ExportSbasMessageSequence::ExportSbasMessageSequence(const std::string& path, bool overwriting)
      : CommandBase(CmdName, TargetId)
    {

      setPath(path);
      setOverwriting(overwriting);
    }

    ExportSbasMessageSequencePtr ExportSbasMessageSequence::create(const std::string& path, bool overwriting)
    {
      return std::make_shared<ExportSbasMessageSequence>(path, overwriting);
    }

    ExportSbasMessageSequencePtr ExportSbasMessageSequence::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ExportSbasMessageSequence>(ptr);
    }

    bool ExportSbasMessageSequence::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Path"])
          && parse_json<bool>::is_valid(m_values["Overwriting"])
        ;

    }

    std::string ExportSbasMessageSequence::documentation() const { return Documentation; }

    const std::vector<std::string>& ExportSbasMessageSequence::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Path", "Overwriting"}; 
      return names; 
    }


    int ExportSbasMessageSequence::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string ExportSbasMessageSequence::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void ExportSbasMessageSequence::setPath(const std::string& path)
    {
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool ExportSbasMessageSequence::overwriting() const
    {
      return parse_json<bool>::parse(m_values["Overwriting"]);
    }

    void ExportSbasMessageSequence::setOverwriting(bool overwriting)
    {
      m_values.AddMember("Overwriting", parse_json<bool>::format(overwriting, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
