
#include "gen/GetIssueOfDataNavICResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIssueOfDataNavICResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIssueOfDataNavICResult::CmdName = "GetIssueOfDataNavICResult";
    const char* const GetIssueOfDataNavICResult::Documentation = "Result of GetIssueOfDataNavIC.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetIssueOfDataNavICResult);


    GetIssueOfDataNavICResult::GetIssueOfDataNavICResult()
      : CommandResult(CmdName)
    {}

    GetIssueOfDataNavICResult::GetIssueOfDataNavICResult(int ephemerisAndClock, const Sdx::optional<bool>& overrideRinex)
      : CommandResult(CmdName)
    {

      setEphemerisAndClock(ephemerisAndClock);
      setOverrideRinex(overrideRinex);
    }

    GetIssueOfDataNavICResult::GetIssueOfDataNavICResult(CommandBasePtr relatedCommand, int ephemerisAndClock, const Sdx::optional<bool>& overrideRinex)
      : CommandResult(CmdName, relatedCommand)
    {

      setEphemerisAndClock(ephemerisAndClock);
      setOverrideRinex(overrideRinex);
    }


    GetIssueOfDataNavICResultPtr GetIssueOfDataNavICResult::create(int ephemerisAndClock, const Sdx::optional<bool>& overrideRinex)
    {
      return std::make_shared<GetIssueOfDataNavICResult>(ephemerisAndClock, overrideRinex);
    }

    GetIssueOfDataNavICResultPtr GetIssueOfDataNavICResult::create(CommandBasePtr relatedCommand, int ephemerisAndClock, const Sdx::optional<bool>& overrideRinex)
    {
      return std::make_shared<GetIssueOfDataNavICResult>(relatedCommand, ephemerisAndClock, overrideRinex);
    }

    GetIssueOfDataNavICResultPtr GetIssueOfDataNavICResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIssueOfDataNavICResult>(ptr);
    }

    bool GetIssueOfDataNavICResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["EphemerisAndClock"])
          && parse_json<Sdx::optional<bool>>::is_valid(m_values["OverrideRinex"])
        ;

    }

    std::string GetIssueOfDataNavICResult::documentation() const { return Documentation; }


    int GetIssueOfDataNavICResult::ephemerisAndClock() const
    {
      return parse_json<int>::parse(m_values["EphemerisAndClock"]);
    }

    void GetIssueOfDataNavICResult::setEphemerisAndClock(int ephemerisAndClock)
    {
      m_values.AddMember("EphemerisAndClock", parse_json<int>::format(ephemerisAndClock, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<bool> GetIssueOfDataNavICResult::overrideRinex() const
    {
      return parse_json<Sdx::optional<bool>>::parse(m_values["OverrideRinex"]);
    }

    void GetIssueOfDataNavICResult::setOverrideRinex(const Sdx::optional<bool>& overrideRinex)
    {
      m_values.AddMember("OverrideRinex", parse_json<Sdx::optional<bool>>::format(overrideRinex, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
