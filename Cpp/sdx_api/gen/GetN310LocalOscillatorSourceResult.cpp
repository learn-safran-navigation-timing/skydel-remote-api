
#include "GetN310LocalOscillatorSourceResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetN310LocalOscillatorSourceResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetN310LocalOscillatorSourceResult::CmdName = "GetN310LocalOscillatorSourceResult";
    const char* const GetN310LocalOscillatorSourceResult::Documentation = "Result of GetN310LocalOscillatorSource.\n"
      "\n"
      "Name       Type   Description\n"
      "---------- ------ -------------------------------------------------------------------------------------------\n"
      "IsExternal bool   Indicates if the Local Oscillator is external (true) or internal (false). False by default.\n"
      "Id         string N310 modulation target Id.";
    const char* const GetN310LocalOscillatorSourceResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetN310LocalOscillatorSourceResult);


    GetN310LocalOscillatorSourceResult::GetN310LocalOscillatorSourceResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetN310LocalOscillatorSourceResult::GetN310LocalOscillatorSourceResult(bool isExternal, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setIsExternal(isExternal);
      setId(id);
    }

    GetN310LocalOscillatorSourceResult::GetN310LocalOscillatorSourceResult(CommandBasePtr relatedCommand, bool isExternal, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& GetN310LocalOscillatorSourceResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"IsExternal", "Id"}; 
      return names; 
    }


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
