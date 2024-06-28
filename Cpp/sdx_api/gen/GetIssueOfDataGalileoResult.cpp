
#include "GetIssueOfDataGalileoResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIssueOfDataGalileoResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIssueOfDataGalileoResult::CmdName = "GetIssueOfDataGalileoResult";
    const char* const GetIssueOfDataGalileoResult::Documentation = "Result of GetIssueOfDataGalileo.\n"
      "\n"
      "Name          Type          Description\n"
      "------------- ------------- ---------------------------------------------------------\n"
      "Navigation    int           Issue of data, navigation\n"
      "Almanac       int           Issue of data, almanac\n"
      "OverrideRinex optional bool If the IODNAV overrides the RINEX IODNAV, default is True";
    const char* const GetIssueOfDataGalileoResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIssueOfDataGalileoResult);


    GetIssueOfDataGalileoResult::GetIssueOfDataGalileoResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetIssueOfDataGalileoResult::GetIssueOfDataGalileoResult(int navigation, int almanac, const std::optional<bool>& overrideRinex)
      : CommandResult(CmdName, TargetId)
    {

      setNavigation(navigation);
      setAlmanac(almanac);
      setOverrideRinex(overrideRinex);
    }

    GetIssueOfDataGalileoResult::GetIssueOfDataGalileoResult(CommandBasePtr relatedCommand, int navigation, int almanac, const std::optional<bool>& overrideRinex)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setNavigation(navigation);
      setAlmanac(almanac);
      setOverrideRinex(overrideRinex);
    }


    GetIssueOfDataGalileoResultPtr GetIssueOfDataGalileoResult::create(int navigation, int almanac, const std::optional<bool>& overrideRinex)
    {
      return std::make_shared<GetIssueOfDataGalileoResult>(navigation, almanac, overrideRinex);
    }

    GetIssueOfDataGalileoResultPtr GetIssueOfDataGalileoResult::create(CommandBasePtr relatedCommand, int navigation, int almanac, const std::optional<bool>& overrideRinex)
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
          && parse_json<std::optional<bool>>::is_valid(m_values["OverrideRinex"])
        ;

    }

    std::string GetIssueOfDataGalileoResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIssueOfDataGalileoResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Navigation", "Almanac", "OverrideRinex"}; 
      return names; 
    }


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



    std::optional<bool> GetIssueOfDataGalileoResult::overrideRinex() const
    {
      return parse_json<std::optional<bool>>::parse(m_values["OverrideRinex"]);
    }

    void GetIssueOfDataGalileoResult::setOverrideRinex(const std::optional<bool>& overrideRinex)
    {
      m_values.AddMember("OverrideRinex", parse_json<std::optional<bool>>::format(overrideRinex, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
