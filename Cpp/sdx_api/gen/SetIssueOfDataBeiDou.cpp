
#include "gen/SetIssueOfDataBeiDou.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIssueOfDataBeiDou
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIssueOfDataBeiDou::CmdName = "SetIssueOfDataBeiDou";
    const char* const SetIssueOfDataBeiDou::Documentation = "Set BeiDou Issue of data, Ephemeris (IODE) and Issue of data, Clock (IODC)";

    REGISTER_COMMAND_FACTORY(SetIssueOfDataBeiDou);


    SetIssueOfDataBeiDou::SetIssueOfDataBeiDou()
      : CommandBase(CmdName)
    {}

    SetIssueOfDataBeiDou::SetIssueOfDataBeiDou(int clock, int ephemeris)
      : CommandBase(CmdName)
    {

      setClock(clock);
      setEphemeris(ephemeris);
    }

    SetIssueOfDataBeiDouPtr SetIssueOfDataBeiDou::create(int clock, int ephemeris)
    {
      return std::make_shared<SetIssueOfDataBeiDou>(clock, ephemeris);
    }

    SetIssueOfDataBeiDouPtr SetIssueOfDataBeiDou::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIssueOfDataBeiDou>(ptr);
    }

    bool SetIssueOfDataBeiDou::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Clock"])
          && parse_json<int>::is_valid(m_values["Ephemeris"])
        ;

    }

    std::string SetIssueOfDataBeiDou::documentation() const { return Documentation; }


    int SetIssueOfDataBeiDou::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetIssueOfDataBeiDou::clock() const
    {
      return parse_json<int>::parse(m_values["Clock"]);
    }

    void SetIssueOfDataBeiDou::setClock(int clock)
    {
      m_values.AddMember("Clock", parse_json<int>::format(clock, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetIssueOfDataBeiDou::ephemeris() const
    {
      return parse_json<int>::parse(m_values["Ephemeris"]);
    }

    void SetIssueOfDataBeiDou::setEphemeris(int ephemeris)
    {
      m_values.AddMember("Ephemeris", parse_json<int>::format(ephemeris, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
