
#include "gen/GetIssueOfDataGalileoResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIssueOfDataGalileoResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIssueOfDataGalileoResult::CmdName = "GetIssueOfDataGalileoResult";
    const char* const GetIssueOfDataGalileoResult::Documentation = "Result of GetIssueOfDataGalileo.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetIssueOfDataGalileoResult);


    GetIssueOfDataGalileoResult::GetIssueOfDataGalileoResult()
      : CommandResult(CmdName)
    {}

    GetIssueOfDataGalileoResult::GetIssueOfDataGalileoResult(int navigation, int almanac, const Sdx::optional<bool>& overrideRinex)
      : CommandResult(CmdName)
    {

      setNavigation(navigation);
      setAlmanac(almanac);
      setOverrideRinex(overrideRinex);
    }

    GetIssueOfDataGalileoResult::GetIssueOfDataGalileoResult(CommandBasePtr relatedCommand, int navigation, int almanac, const Sdx::optional<bool>& overrideRinex)
      : CommandResult(CmdName, relatedCommand)
    {

      setNavigation(navigation);
      setAlmanac(almanac);
      setOverrideRinex(overrideRinex);
    }


    GetIssueOfDataGalileoResultPtr GetIssueOfDataGalileoResult::create(int navigation, int almanac, const Sdx::optional<bool>& overrideRinex)
    {
      return std::make_shared<GetIssueOfDataGalileoResult>(navigation, almanac, overrideRinex);
    }

    GetIssueOfDataGalileoResultPtr GetIssueOfDataGalileoResult::create(CommandBasePtr relatedCommand, int navigation, int almanac, const Sdx::optional<bool>& overrideRinex)
    {
      return std::make_shared<GetIssueOfDataGalileoResult>(relatedCommand, navigation, almanac, overrideRinex);
    }

    GetIssueOfDataGalileoResultPtr GetIssueOfDataGalileoResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIssueOfDataGalileoResult>(ptr);
    }

    bool GetIssueOfDataGalileoResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Navigation"])
          && parse_json<int>::is_valid(m_values["Almanac"])
          && parse_json<Sdx::optional<bool>>::is_valid(m_values["OverrideRinex"])
        ;

    }

    std::string GetIssueOfDataGalileoResult::documentation() const { return Documentation; }


    int GetIssueOfDataGalileoResult::navigation() const
    {
      return parse_json<int>::parse(m_values["Navigation"]);
    }

    void GetIssueOfDataGalileoResult::setNavigation(int navigation)
    {
      m_values.AddMember("Navigation", parse_json<int>::format(navigation, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetIssueOfDataGalileoResult::almanac() const
    {
      return parse_json<int>::parse(m_values["Almanac"]);
    }

    void GetIssueOfDataGalileoResult::setAlmanac(int almanac)
    {
      m_values.AddMember("Almanac", parse_json<int>::format(almanac, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<bool> GetIssueOfDataGalileoResult::overrideRinex() const
    {
      return parse_json<Sdx::optional<bool>>::parse(m_values["OverrideRinex"]);
    }

    void GetIssueOfDataGalileoResult::setOverrideRinex(const Sdx::optional<bool>& overrideRinex)
    {
      m_values.AddMember("OverrideRinex", parse_json<Sdx::optional<bool>>::format(overrideRinex, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
