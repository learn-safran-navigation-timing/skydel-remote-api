
#include "SetIssueOfDataGalileo.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIssueOfDataGalileo
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIssueOfDataGalileo::CmdName = "SetIssueOfDataGalileo";
    const char* const SetIssueOfDataGalileo::Documentation = "Set Galileo Issue of data, Navigation (IODNAV) and Issue of data, Almanac (IODA)\n"
      "\n"
      "Name          Type          Description\n"
      "------------- ------------- ---------------------------------------------------------\n"
      "Navigation    int           Issue of data, navigation\n"
      "Almanac       int           Issue of data, almanac\n"
      "OverrideRinex optional bool If the IODNAV overrides the RINEX IODNAV, default is True";
    const char* const SetIssueOfDataGalileo::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetIssueOfDataGalileo);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetIssueOfDataGalileo);


    SetIssueOfDataGalileo::SetIssueOfDataGalileo()
      : CommandBase(CmdName, TargetId)
    {}

    SetIssueOfDataGalileo::SetIssueOfDataGalileo(int navigation, int almanac, const std::optional<bool>& overrideRinex)
      : CommandBase(CmdName, TargetId)
    {

      setNavigation(navigation);
      setAlmanac(almanac);
      setOverrideRinex(overrideRinex);
    }

    SetIssueOfDataGalileoPtr SetIssueOfDataGalileo::create(int navigation, int almanac, const std::optional<bool>& overrideRinex)
    {
      return std::make_shared<SetIssueOfDataGalileo>(navigation, almanac, overrideRinex);
    }

    SetIssueOfDataGalileoPtr SetIssueOfDataGalileo::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIssueOfDataGalileo>(ptr);
    }

    bool SetIssueOfDataGalileo::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Navigation"])
          && parse_json<int>::is_valid(m_values["Almanac"])
          && parse_json<std::optional<bool>>::is_valid(m_values["OverrideRinex"])
        ;

    }

    std::string SetIssueOfDataGalileo::documentation() const { return Documentation; }

    const std::vector<std::string>& SetIssueOfDataGalileo::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Navigation", "Almanac", "OverrideRinex"}; 
      return names; 
    }


    int SetIssueOfDataGalileo::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetIssueOfDataGalileo::navigation() const
    {
      return parse_json<int>::parse(m_values["Navigation"]);
    }

    void SetIssueOfDataGalileo::setNavigation(int navigation)
    {
      m_values.AddMember("Navigation", parse_json<int>::format(navigation, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetIssueOfDataGalileo::almanac() const
    {
      return parse_json<int>::parse(m_values["Almanac"]);
    }

    void SetIssueOfDataGalileo::setAlmanac(int almanac)
    {
      m_values.AddMember("Almanac", parse_json<int>::format(almanac, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<bool> SetIssueOfDataGalileo::overrideRinex() const
    {
      return parse_json<std::optional<bool>>::parse(m_values["OverrideRinex"]);
    }

    void SetIssueOfDataGalileo::setOverrideRinex(const std::optional<bool>& overrideRinex)
    {
      m_values.AddMember("OverrideRinex", parse_json<std::optional<bool>>::format(overrideRinex, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
