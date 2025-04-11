
#include "GetModulationTargetIQPlaybackResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetModulationTargetIQPlaybackResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetModulationTargetIQPlaybackResult::CmdName = "GetModulationTargetIQPlaybackResult";
    const char* const GetModulationTargetIQPlaybackResult::Documentation = "Result of GetModulationTargetIQPlayback.\n"
      "\n"
      "Name   Type         Description\n"
      "------ ------------ -------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Output int          Output index (zero based)\n"
      "Files  array string The paths to the IQ Playback files. Note: only one file is currently supported, the additional files will be ignored.\n"
      "Gain   int          The gain associated to this output (dB). This value has to be between the radio's minimum and maximum value. A negative value means to use the radio default value.\n"
      "Id     string       Target identifier";
    const char* const GetModulationTargetIQPlaybackResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetModulationTargetIQPlaybackResult);


    GetModulationTargetIQPlaybackResult::GetModulationTargetIQPlaybackResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetModulationTargetIQPlaybackResult::GetModulationTargetIQPlaybackResult(int output, const std::vector<std::string>& files, int gain, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setOutput(output);
      setFiles(files);
      setGain(gain);
      setId(id);
    }

    GetModulationTargetIQPlaybackResult::GetModulationTargetIQPlaybackResult(CommandBasePtr relatedCommand, int output, const std::vector<std::string>& files, int gain, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setOutput(output);
      setFiles(files);
      setGain(gain);
      setId(id);
    }


    GetModulationTargetIQPlaybackResultPtr GetModulationTargetIQPlaybackResult::create(int output, const std::vector<std::string>& files, int gain, const std::string& id)
    {
      return std::make_shared<GetModulationTargetIQPlaybackResult>(output, files, gain, id);
    }

    GetModulationTargetIQPlaybackResultPtr GetModulationTargetIQPlaybackResult::create(CommandBasePtr relatedCommand, int output, const std::vector<std::string>& files, int gain, const std::string& id)
    {
      return std::make_shared<GetModulationTargetIQPlaybackResult>(relatedCommand, output, files, gain, id);
    }

    GetModulationTargetIQPlaybackResultPtr GetModulationTargetIQPlaybackResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetModulationTargetIQPlaybackResult>(ptr);
    }

    bool GetModulationTargetIQPlaybackResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Output"])
          && parse_json<std::vector<std::string>>::is_valid(m_values["Files"])
          && parse_json<int>::is_valid(m_values["Gain"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetModulationTargetIQPlaybackResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetModulationTargetIQPlaybackResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Output", "Files", "Gain", "Id"}; 
      return names; 
    }


    int GetModulationTargetIQPlaybackResult::output() const
    {
      return parse_json<int>::parse(m_values["Output"]);
    }

    void GetModulationTargetIQPlaybackResult::setOutput(int output)
    {
      m_values.AddMember("Output", parse_json<int>::format(output, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<std::string> GetModulationTargetIQPlaybackResult::files() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Files"]);
    }

    void GetModulationTargetIQPlaybackResult::setFiles(const std::vector<std::string>& files)
    {
      m_values.AddMember("Files", parse_json<std::vector<std::string>>::format(files, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetModulationTargetIQPlaybackResult::gain() const
    {
      return parse_json<int>::parse(m_values["Gain"]);
    }

    void GetModulationTargetIQPlaybackResult::setGain(int gain)
    {
      m_values.AddMember("Gain", parse_json<int>::format(gain, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetModulationTargetIQPlaybackResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetModulationTargetIQPlaybackResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
