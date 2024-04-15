
#include "SetIssueOfDataBeiDou.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIssueOfDataBeiDou
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIssueOfDataBeiDou::CmdName = "SetIssueOfDataBeiDou";
    const char* const SetIssueOfDataBeiDou::Documentation = "Set BeiDou Issue of data, Ephemeris (IODE) and Issue of data, Clock (IODC)\n"
      "\n"
      "Name      Type Description\n"
      "--------- ---- ------------------------\n"
      "Clock     int  Issue of data, clock\n"
      "Ephemeris int  Issue of data, ephemeris";
    const char* const SetIssueOfDataBeiDou::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetIssueOfDataBeiDou);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetIssueOfDataBeiDou);


    SetIssueOfDataBeiDou::SetIssueOfDataBeiDou()
      : CommandBase(CmdName, TargetId)
    {}

    SetIssueOfDataBeiDou::SetIssueOfDataBeiDou(int clock, int ephemeris)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& SetIssueOfDataBeiDou::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Clock", "Ephemeris"}; 
      return names; 
    }


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
