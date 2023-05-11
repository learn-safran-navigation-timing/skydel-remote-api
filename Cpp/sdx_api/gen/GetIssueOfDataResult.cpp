
#include "gen/GetIssueOfDataResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIssueOfDataResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIssueOfDataResult::CmdName = "GetIssueOfDataResult";
    const char* const GetIssueOfDataResult::Documentation = "Result of GetIssueOfData.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetIssueOfDataResult);


    GetIssueOfDataResult::GetIssueOfDataResult()
      : CommandResult(CmdName)
    {}

    GetIssueOfDataResult::GetIssueOfDataResult(int clock, int ephemeris, const Sdx::optional<bool>& overrideRinex)
      : CommandResult(CmdName)
    {

      setClock(clock);
      setEphemeris(ephemeris);
      setOverrideRinex(overrideRinex);
    }

    GetIssueOfDataResult::GetIssueOfDataResult(CommandBasePtr relatedCommand, int clock, int ephemeris, const Sdx::optional<bool>& overrideRinex)
      : CommandResult(CmdName, relatedCommand)
    {

      setClock(clock);
      setEphemeris(ephemeris);
      setOverrideRinex(overrideRinex);
    }


    GetIssueOfDataResultPtr GetIssueOfDataResult::create(int clock, int ephemeris, const Sdx::optional<bool>& overrideRinex)
    {
      return std::make_shared<GetIssueOfDataResult>(clock, ephemeris, overrideRinex);
    }

    GetIssueOfDataResultPtr GetIssueOfDataResult::create(CommandBasePtr relatedCommand, int clock, int ephemeris, const Sdx::optional<bool>& overrideRinex)
    {
      return std::make_shared<GetIssueOfDataResult>(relatedCommand, clock, ephemeris, overrideRinex);
    }

    GetIssueOfDataResultPtr GetIssueOfDataResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIssueOfDataResult>(ptr);
    }

    bool GetIssueOfDataResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Clock"])
          && parse_json<int>::is_valid(m_values["Ephemeris"])
          && parse_json<Sdx::optional<bool>>::is_valid(m_values["OverrideRinex"])
        ;

    }

    std::string GetIssueOfDataResult::documentation() const { return Documentation; }


    int GetIssueOfDataResult::clock() const
    {
      return parse_json<int>::parse(m_values["Clock"]);
    }

    void GetIssueOfDataResult::setClock(int clock)
    {
      m_values.AddMember("Clock", parse_json<int>::format(clock, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetIssueOfDataResult::ephemeris() const
    {
      return parse_json<int>::parse(m_values["Ephemeris"]);
    }

    void GetIssueOfDataResult::setEphemeris(int ephemeris)
    {
      m_values.AddMember("Ephemeris", parse_json<int>::format(ephemeris, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<bool> GetIssueOfDataResult::overrideRinex() const
    {
      return parse_json<Sdx::optional<bool>>::parse(m_values["OverrideRinex"]);
    }

    void GetIssueOfDataResult::setOverrideRinex(const Sdx::optional<bool>& overrideRinex)
    {
      m_values.AddMember("OverrideRinex", parse_json<Sdx::optional<bool>>::format(overrideRinex, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
