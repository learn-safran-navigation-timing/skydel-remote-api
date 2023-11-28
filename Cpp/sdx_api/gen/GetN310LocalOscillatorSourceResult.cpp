
#include "gen/GetN310LocalOscillatorSourceResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetN310LocalOscillatorSourceResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetN310LocalOscillatorSourceResult::CmdName = "GetN310LocalOscillatorSourceResult";
    const char* const GetN310LocalOscillatorSourceResult::Documentation = "Result of GetN310LocalOscillatorSource.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetN310LocalOscillatorSourceResult);


    GetN310LocalOscillatorSourceResult::GetN310LocalOscillatorSourceResult()
      : CommandResult(CmdName)
    {}

    GetN310LocalOscillatorSourceResult::GetN310LocalOscillatorSourceResult(bool isExternal, const std::string& id)
      : CommandResult(CmdName)
    {

      setIsExternal(isExternal);
      setId(id);
    }

    GetN310LocalOscillatorSourceResult::GetN310LocalOscillatorSourceResult(CommandBasePtr relatedCommand, bool isExternal, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setIsExternal(isExternal);
      setId(id);
    }


    GetN310LocalOscillatorSourceResultPtr GetN310LocalOscillatorSourceResult::create(bool isExternal, const std::string& id)
    {
      return std::make_shared<GetN310LocalOscillatorSourceResult>(isExternal, id);
    }

    GetN310LocalOscillatorSourceResultPtr GetN310LocalOscillatorSourceResult::create(CommandBasePtr relatedCommand, bool isExternal, const std::string& id)
    {
      return std::make_shared<GetN310LocalOscillatorSourceResult>(relatedCommand, isExternal, id);
    }

    GetN310LocalOscillatorSourceResultPtr GetN310LocalOscillatorSourceResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetN310LocalOscillatorSourceResult>(ptr);
    }

    bool GetN310LocalOscillatorSourceResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["IsExternal"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetN310LocalOscillatorSourceResult::documentation() const { return Documentation; }


    bool GetN310LocalOscillatorSourceResult::isExternal() const
    {
      return parse_json<bool>::parse(m_values["IsExternal"]);
    }

    void GetN310LocalOscillatorSourceResult::setIsExternal(bool isExternal)
    {
      m_values.AddMember("IsExternal", parse_json<bool>::format(isExternal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetN310LocalOscillatorSourceResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetN310LocalOscillatorSourceResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
