
#include "gen/SetIssueOfDataNavIC.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIssueOfDataNavIC
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIssueOfDataNavIC::CmdName = "SetIssueOfDataNavIC";
    const char* const SetIssueOfDataNavIC::Documentation = "Set NavIC Issue of data, Ephemeris and Clock (IODEC)";

    REGISTER_COMMAND_FACTORY(SetIssueOfDataNavIC);


    SetIssueOfDataNavIC::SetIssueOfDataNavIC()
      : CommandBase(CmdName)
    {}

    SetIssueOfDataNavIC::SetIssueOfDataNavIC(int ephemerisAndClock, const Sdx::optional<bool>& overrideRinex)
      : CommandBase(CmdName)
    {

      setEphemerisAndClock(ephemerisAndClock);
      setOverrideRinex(overrideRinex);
    }

    SetIssueOfDataNavICPtr SetIssueOfDataNavIC::create(int ephemerisAndClock, const Sdx::optional<bool>& overrideRinex)
    {
      return std::make_shared<SetIssueOfDataNavIC>(ephemerisAndClock, overrideRinex);
    }

    SetIssueOfDataNavICPtr SetIssueOfDataNavIC::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIssueOfDataNavIC>(ptr);
    }

    bool SetIssueOfDataNavIC::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["EphemerisAndClock"])
          && parse_json<Sdx::optional<bool>>::is_valid(m_values["OverrideRinex"])
        ;

    }

    std::string SetIssueOfDataNavIC::documentation() const { return Documentation; }


    int SetIssueOfDataNavIC::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetIssueOfDataNavIC::ephemerisAndClock() const
    {
      return parse_json<int>::parse(m_values["EphemerisAndClock"]);
    }

    void SetIssueOfDataNavIC::setEphemerisAndClock(int ephemerisAndClock)
    {
      m_values.AddMember("EphemerisAndClock", parse_json<int>::format(ephemerisAndClock, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<bool> SetIssueOfDataNavIC::overrideRinex() const
    {
      return parse_json<Sdx::optional<bool>>::parse(m_values["OverrideRinex"]);
    }

    void SetIssueOfDataNavIC::setOverrideRinex(const Sdx::optional<bool>& overrideRinex)
    {
      m_values.AddMember("OverrideRinex", parse_json<Sdx::optional<bool>>::format(overrideRinex, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
