
#include "SetIssueOfDataQzss.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIssueOfDataQzss
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIssueOfDataQzss::CmdName = "SetIssueOfDataQzss";
    const char* const SetIssueOfDataQzss::Documentation = "Set QZSS Issue of data, Ephemeris (IODE) and Issue of data, Clock (IODC)\n"
      "\n"
      "Name          Type          Description\n"
      "------------- ------------- ---------------------------------------------------\n"
      "Clock         int           Issue of data, clock\n"
      "Ephemeris     int           Issue of data, ephemeris\n"
      "OverrideRinex optional bool If the IOD overrides the RINEX IOD, default is True";
    const char* const SetIssueOfDataQzss::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetIssueOfDataQzss);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetIssueOfDataQzss);


    SetIssueOfDataQzss::SetIssueOfDataQzss()
      : CommandBase(CmdName, TargetId)
    {}

    SetIssueOfDataQzss::SetIssueOfDataQzss(int clock, int ephemeris, const Sdx::optional<bool>& overrideRinex)
      : CommandBase(CmdName, TargetId)
    {

      setClock(clock);
      setEphemeris(ephemeris);
      setOverrideRinex(overrideRinex);
    }

    SetIssueOfDataQzssPtr SetIssueOfDataQzss::create(int clock, int ephemeris, const Sdx::optional<bool>& overrideRinex)
    {
      return std::make_shared<SetIssueOfDataQzss>(clock, ephemeris, overrideRinex);
    }

    SetIssueOfDataQzssPtr SetIssueOfDataQzss::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIssueOfDataQzss>(ptr);
    }

    bool SetIssueOfDataQzss::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Clock"])
          && parse_json<int>::is_valid(m_values["Ephemeris"])
          && parse_json<Sdx::optional<bool>>::is_valid(m_values["OverrideRinex"])
        ;

    }

    std::string SetIssueOfDataQzss::documentation() const { return Documentation; }

    const std::vector<std::string>& SetIssueOfDataQzss::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Clock", "Ephemeris", "OverrideRinex"}; 
      return names; 
    }


    int SetIssueOfDataQzss::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetIssueOfDataQzss::clock() const
    {
      return parse_json<int>::parse(m_values["Clock"]);
    }

    void SetIssueOfDataQzss::setClock(int clock)
    {
      m_values.AddMember("Clock", parse_json<int>::format(clock, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetIssueOfDataQzss::ephemeris() const
    {
      return parse_json<int>::parse(m_values["Ephemeris"]);
    }

    void SetIssueOfDataQzss::setEphemeris(int ephemeris)
    {
      m_values.AddMember("Ephemeris", parse_json<int>::format(ephemeris, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<bool> SetIssueOfDataQzss::overrideRinex() const
    {
      return parse_json<Sdx::optional<bool>>::parse(m_values["OverrideRinex"]);
    }

    void SetIssueOfDataQzss::setOverrideRinex(const Sdx::optional<bool>& overrideRinex)
    {
      m_values.AddMember("OverrideRinex", parse_json<Sdx::optional<bool>>::format(overrideRinex, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
