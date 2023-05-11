
#include "gen/GetIssueOfDataQzssResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIssueOfDataQzssResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIssueOfDataQzssResult::CmdName = "GetIssueOfDataQzssResult";
    const char* const GetIssueOfDataQzssResult::Documentation = "Result of GetIssueOfDataQzss.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetIssueOfDataQzssResult);


    GetIssueOfDataQzssResult::GetIssueOfDataQzssResult()
      : CommandResult(CmdName)
    {}

    GetIssueOfDataQzssResult::GetIssueOfDataQzssResult(int clock, int ephemeris, const Sdx::optional<bool>& overrideRinex)
      : CommandResult(CmdName)
    {

      setClock(clock);
      setEphemeris(ephemeris);
      setOverrideRinex(overrideRinex);
    }

    GetIssueOfDataQzssResult::GetIssueOfDataQzssResult(CommandBasePtr relatedCommand, int clock, int ephemeris, const Sdx::optional<bool>& overrideRinex)
      : CommandResult(CmdName, relatedCommand)
    {

      setClock(clock);
      setEphemeris(ephemeris);
      setOverrideRinex(overrideRinex);
    }


    GetIssueOfDataQzssResultPtr GetIssueOfDataQzssResult::create(int clock, int ephemeris, const Sdx::optional<bool>& overrideRinex)
    {
      return std::make_shared<GetIssueOfDataQzssResult>(clock, ephemeris, overrideRinex);
    }

    GetIssueOfDataQzssResultPtr GetIssueOfDataQzssResult::create(CommandBasePtr relatedCommand, int clock, int ephemeris, const Sdx::optional<bool>& overrideRinex)
    {
      return std::make_shared<GetIssueOfDataQzssResult>(relatedCommand, clock, ephemeris, overrideRinex);
    }

    GetIssueOfDataQzssResultPtr GetIssueOfDataQzssResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIssueOfDataQzssResult>(ptr);
    }

    bool GetIssueOfDataQzssResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Clock"])
          && parse_json<int>::is_valid(m_values["Ephemeris"])
          && parse_json<Sdx::optional<bool>>::is_valid(m_values["OverrideRinex"])
        ;

    }

    std::string GetIssueOfDataQzssResult::documentation() const { return Documentation; }


    int GetIssueOfDataQzssResult::clock() const
    {
      return parse_json<int>::parse(m_values["Clock"]);
    }

    void GetIssueOfDataQzssResult::setClock(int clock)
    {
      m_values.AddMember("Clock", parse_json<int>::format(clock, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetIssueOfDataQzssResult::ephemeris() const
    {
      return parse_json<int>::parse(m_values["Ephemeris"]);
    }

    void GetIssueOfDataQzssResult::setEphemeris(int ephemeris)
    {
      m_values.AddMember("Ephemeris", parse_json<int>::format(ephemeris, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<bool> GetIssueOfDataQzssResult::overrideRinex() const
    {
      return parse_json<Sdx::optional<bool>>::parse(m_values["OverrideRinex"]);
    }

    void GetIssueOfDataQzssResult::setOverrideRinex(const Sdx::optional<bool>& overrideRinex)
    {
      m_values.AddMember("OverrideRinex", parse_json<Sdx::optional<bool>>::format(overrideRinex, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
