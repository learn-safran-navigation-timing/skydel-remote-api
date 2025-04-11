
#include "ChangeModulationTargetIQPlayback.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ChangeModulationTargetIQPlayback
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ChangeModulationTargetIQPlayback::CmdName = "ChangeModulationTargetIQPlayback";
    const char* const ChangeModulationTargetIQPlayback::Documentation = "Set the IQ file to playback on the specified target and output. Skydel tries to keep the sampling rate as low as possible. File may be upsampled if it doesn't match with the supported sampling rates.\n"
      "\n"
      "Name   Type         Description\n"
      "------ ------------ -------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Output int          Output index (zero based)\n"
      "Files  array string The paths to the IQ Playback files. Note: only one file is currently supported, the additional files will be ignored.\n"
      "Gain   int          The gain associated to this output (dB). This value has to be between the radio's minimum and maximum value. A negative value means to use the radio default value.\n"
      "Id     string       Target identifier";
    const char* const ChangeModulationTargetIQPlayback::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ChangeModulationTargetIQPlayback);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ChangeModulationTargetIQPlayback);


    ChangeModulationTargetIQPlayback::ChangeModulationTargetIQPlayback()
      : CommandBase(CmdName, TargetId)
    {}

    ChangeModulationTargetIQPlayback::ChangeModulationTargetIQPlayback(int output, const std::vector<std::string>& files, int gain, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setOutput(output);
      setFiles(files);
      setGain(gain);
      setId(id);
    }

    ChangeModulationTargetIQPlaybackPtr ChangeModulationTargetIQPlayback::create(int output, const std::vector<std::string>& files, int gain, const std::string& id)
    {
      return std::make_shared<ChangeModulationTargetIQPlayback>(output, files, gain, id);
    }

    ChangeModulationTargetIQPlaybackPtr ChangeModulationTargetIQPlayback::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ChangeModulationTargetIQPlayback>(ptr);
    }

    bool ChangeModulationTargetIQPlayback::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Output"])
          && parse_json<std::vector<std::string>>::is_valid(m_values["Files"])
          && parse_json<int>::is_valid(m_values["Gain"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string ChangeModulationTargetIQPlayback::documentation() const { return Documentation; }

    const std::vector<std::string>& ChangeModulationTargetIQPlayback::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Output", "Files", "Gain", "Id"}; 
      return names; 
    }


    int ChangeModulationTargetIQPlayback::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int ChangeModulationTargetIQPlayback::output() const
    {
      return parse_json<int>::parse(m_values["Output"]);
    }

    void ChangeModulationTargetIQPlayback::setOutput(int output)
    {
      m_values.AddMember("Output", parse_json<int>::format(output, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<std::string> ChangeModulationTargetIQPlayback::files() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Files"]);
    }

    void ChangeModulationTargetIQPlayback::setFiles(const std::vector<std::string>& files)
    {
      m_values.AddMember("Files", parse_json<std::vector<std::string>>::format(files, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int ChangeModulationTargetIQPlayback::gain() const
    {
      return parse_json<int>::parse(m_values["Gain"]);
    }

    void ChangeModulationTargetIQPlayback::setGain(int gain)
    {
      m_values.AddMember("Gain", parse_json<int>::format(gain, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ChangeModulationTargetIQPlayback::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void ChangeModulationTargetIQPlayback::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
