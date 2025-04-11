
#include "GetModulationTargetIQPlayback.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetModulationTargetIQPlayback
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetModulationTargetIQPlayback::CmdName = "GetModulationTargetIQPlayback";
    const char* const GetModulationTargetIQPlayback::Documentation = "Get the IQ file to playback on the specified target and output. Skydel tries to keep the sampling rate as low as possible. File may be upsampled if it doesn't match with the supported sampling rates.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ -------------------------\n"
      "Output int    Output index (zero based)\n"
      "Id     string Target identifier";
    const char* const GetModulationTargetIQPlayback::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetModulationTargetIQPlayback);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetModulationTargetIQPlayback);


    GetModulationTargetIQPlayback::GetModulationTargetIQPlayback()
      : CommandBase(CmdName, TargetId)
    {}

    GetModulationTargetIQPlayback::GetModulationTargetIQPlayback(int output, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setOutput(output);
      setId(id);
    }

    GetModulationTargetIQPlaybackPtr GetModulationTargetIQPlayback::create(int output, const std::string& id)
    {
      return std::make_shared<GetModulationTargetIQPlayback>(output, id);
    }

    GetModulationTargetIQPlaybackPtr GetModulationTargetIQPlayback::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetModulationTargetIQPlayback>(ptr);
    }

    bool GetModulationTargetIQPlayback::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Output"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetModulationTargetIQPlayback::documentation() const { return Documentation; }

    const std::vector<std::string>& GetModulationTargetIQPlayback::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Output", "Id"}; 
      return names; 
    }


    int GetModulationTargetIQPlayback::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetModulationTargetIQPlayback::output() const
    {
      return parse_json<int>::parse(m_values["Output"]);
    }

    void GetModulationTargetIQPlayback::setOutput(int output)
    {
      m_values.AddMember("Output", parse_json<int>::format(output, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetModulationTargetIQPlayback::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetModulationTargetIQPlayback::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
