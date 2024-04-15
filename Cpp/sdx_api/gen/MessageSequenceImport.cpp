
#include "MessageSequenceImport.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of MessageSequenceImport
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const MessageSequenceImport::CmdName = "MessageSequenceImport";
    const char* const MessageSequenceImport::Documentation = "Import a sequence file.\n"
      "A sequence file is a CSV with one message type per line.\n"
      "\n"
      "Name     Type   Description\n"
      "-------- ------ ------------------------------------------------\n"
      "Signal   string Signal Name (\"L2C\" for example)\n"
      "Filename string Path to the CSV file on the simulator's machine.";
    const char* const MessageSequenceImport::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(MessageSequenceImport);
    REGISTER_COMMAND_TO_FACTORY_IMPL(MessageSequenceImport);


    MessageSequenceImport::MessageSequenceImport()
      : CommandBase(CmdName, TargetId)
    {}

    MessageSequenceImport::MessageSequenceImport(const std::string& signal, const std::string& filename)
      : CommandBase(CmdName, TargetId)
    {

      setSignal(signal);
      setFilename(filename);
    }

    MessageSequenceImportPtr MessageSequenceImport::create(const std::string& signal, const std::string& filename)
    {
      return std::make_shared<MessageSequenceImport>(signal, filename);
    }

    MessageSequenceImportPtr MessageSequenceImport::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<MessageSequenceImport>(ptr);
    }

    bool MessageSequenceImport::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<std::string>::is_valid(m_values["Filename"])
        ;

    }

    std::string MessageSequenceImport::documentation() const { return Documentation; }

    const std::vector<std::string>& MessageSequenceImport::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "Filename"}; 
      return names; 
    }


    int MessageSequenceImport::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string MessageSequenceImport::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void MessageSequenceImport::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string MessageSequenceImport::filename() const
    {
      return parse_json<std::string>::parse(m_values["Filename"]);
    }

    void MessageSequenceImport::setFilename(const std::string& filename)
    {
      m_values.AddMember("Filename", parse_json<std::string>::format(filename, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
