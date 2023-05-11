
#include "gen/SetIssueOfData.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIssueOfData
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIssueOfData::CmdName = "SetIssueOfData";
    const char* const SetIssueOfData::Documentation = "Set GPS Issue of data, Ephemeris (IODE) and Issue of data, Clock (IODC)";

    REGISTER_COMMAND_FACTORY(SetIssueOfData);


    SetIssueOfData::SetIssueOfData()
      : CommandBase(CmdName)
    {}

    SetIssueOfData::SetIssueOfData(int clock, int ephemeris, const Sdx::optional<bool>& overrideRinex)
      : CommandBase(CmdName)
    {

      setClock(clock);
      setEphemeris(ephemeris);
      setOverrideRinex(overrideRinex);
    }

    SetIssueOfDataPtr SetIssueOfData::create(int clock, int ephemeris, const Sdx::optional<bool>& overrideRinex)
    {
      return std::make_shared<SetIssueOfData>(clock, ephemeris, overrideRinex);
    }

    SetIssueOfDataPtr SetIssueOfData::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIssueOfData>(ptr);
    }

    bool SetIssueOfData::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Clock"])
          && parse_json<int>::is_valid(m_values["Ephemeris"])
          && parse_json<Sdx::optional<bool>>::is_valid(m_values["OverrideRinex"])
        ;

    }

    std::string SetIssueOfData::documentation() const { return Documentation; }


    int SetIssueOfData::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetIssueOfData::clock() const
    {
      return parse_json<int>::parse(m_values["Clock"]);
    }

    void SetIssueOfData::setClock(int clock)
    {
      m_values.AddMember("Clock", parse_json<int>::format(clock, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetIssueOfData::ephemeris() const
    {
      return parse_json<int>::parse(m_values["Ephemeris"]);
    }

    void SetIssueOfData::setEphemeris(int ephemeris)
    {
      m_values.AddMember("Ephemeris", parse_json<int>::format(ephemeris, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<bool> SetIssueOfData::overrideRinex() const
    {
      return parse_json<Sdx::optional<bool>>::parse(m_values["OverrideRinex"]);
    }

    void SetIssueOfData::setOverrideRinex(const Sdx::optional<bool>& overrideRinex)
    {
      m_values.AddMember("OverrideRinex", parse_json<Sdx::optional<bool>>::format(overrideRinex, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
