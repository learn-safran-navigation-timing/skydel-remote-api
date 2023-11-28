
#include "gen/GetWFElementResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetWFElementResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetWFElementResult::CmdName = "GetWFElementResult";
    const char* const GetWFElementResult::Documentation = "Result of GetWFElement.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetWFElementResult);


    GetWFElementResult::GetWFElementResult()
      : CommandResult(CmdName)
    {}

    GetWFElementResult::GetWFElementResult(int element, bool enabled, const std::string& antennaModelName)
      : CommandResult(CmdName)
    {

      setElement(element);
      setEnabled(enabled);
      setAntennaModelName(antennaModelName);
    }

    GetWFElementResult::GetWFElementResult(CommandBasePtr relatedCommand, int element, bool enabled, const std::string& antennaModelName)
      : CommandResult(CmdName, relatedCommand)
    {

      setElement(element);
      setEnabled(enabled);
      setAntennaModelName(antennaModelName);
    }


    GetWFElementResultPtr GetWFElementResult::create(int element, bool enabled, const std::string& antennaModelName)
    {
      return std::make_shared<GetWFElementResult>(element, enabled, antennaModelName);
    }

    GetWFElementResultPtr GetWFElementResult::create(CommandBasePtr relatedCommand, int element, bool enabled, const std::string& antennaModelName)
    {
      return std::make_shared<GetWFElementResult>(relatedCommand, element, enabled, antennaModelName);
    }

    GetWFElementResultPtr GetWFElementResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetWFElementResult>(ptr);
    }

    bool GetWFElementResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Element"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<std::string>::is_valid(m_values["AntennaModelName"])
        ;

    }

    std::string GetWFElementResult::documentation() const { return Documentation; }


    int GetWFElementResult::element() const
    {
      return parse_json<int>::parse(m_values["Element"]);
    }

    void GetWFElementResult::setElement(int element)
    {
      m_values.AddMember("Element", parse_json<int>::format(element, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetWFElementResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void GetWFElementResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetWFElementResult::antennaModelName() const
    {
      return parse_json<std::string>::parse(m_values["AntennaModelName"]);
    }

    void GetWFElementResult::setAntennaModelName(const std::string& antennaModelName)
    {
      m_values.AddMember("AntennaModelName", parse_json<std::string>::format(antennaModelName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
