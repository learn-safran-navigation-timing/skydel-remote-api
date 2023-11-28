
#include "gen/GetN310LocalOscillatorSource.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetN310LocalOscillatorSource
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetN310LocalOscillatorSource::CmdName = "GetN310LocalOscillatorSource";
    const char* const GetN310LocalOscillatorSource::Documentation = "Get the local oscillator source of the N310. Can be Internal or External. By default, the source is Internal.";

    REGISTER_COMMAND_FACTORY(GetN310LocalOscillatorSource);


    GetN310LocalOscillatorSource::GetN310LocalOscillatorSource()
      : CommandBase(CmdName)
    {}

    GetN310LocalOscillatorSource::GetN310LocalOscillatorSource(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    GetN310LocalOscillatorSourcePtr GetN310LocalOscillatorSource::create(const std::string& id)
    {
      return std::make_shared<GetN310LocalOscillatorSource>(id);
    }

    GetN310LocalOscillatorSourcePtr GetN310LocalOscillatorSource::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetN310LocalOscillatorSource>(ptr);
    }

    bool GetN310LocalOscillatorSource::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetN310LocalOscillatorSource::documentation() const { return Documentation; }


    int GetN310LocalOscillatorSource::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetN310LocalOscillatorSource::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetN310LocalOscillatorSource::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
