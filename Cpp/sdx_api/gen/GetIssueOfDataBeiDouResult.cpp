
#include "gen/GetIssueOfDataBeiDouResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIssueOfDataBeiDouResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIssueOfDataBeiDouResult::CmdName = "GetIssueOfDataBeiDouResult";
    const char* const GetIssueOfDataBeiDouResult::Documentation = "Result of GetIssueOfDataBeiDou.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetIssueOfDataBeiDouResult);


    GetIssueOfDataBeiDouResult::GetIssueOfDataBeiDouResult()
      : CommandResult(CmdName)
    {}

    GetIssueOfDataBeiDouResult::GetIssueOfDataBeiDouResult(int clock, int ephemeris)
      : CommandResult(CmdName)
    {

      setClock(clock);
      setEphemeris(ephemeris);
    }

    GetIssueOfDataBeiDouResult::GetIssueOfDataBeiDouResult(CommandBasePtr relatedCommand, int clock, int ephemeris)
      : CommandResult(CmdName, relatedCommand)
    {

      setClock(clock);
      setEphemeris(ephemeris);
    }


    GetIssueOfDataBeiDouResultPtr GetIssueOfDataBeiDouResult::create(int clock, int ephemeris)
    {
      return std::make_shared<GetIssueOfDataBeiDouResult>(clock, ephemeris);
    }

    GetIssueOfDataBeiDouResultPtr GetIssueOfDataBeiDouResult::create(CommandBasePtr relatedCommand, int clock, int ephemeris)
    {
      return std::make_shared<GetIssueOfDataBeiDouResult>(relatedCommand, clock, ephemeris);
    }

    GetIssueOfDataBeiDouResultPtr GetIssueOfDataBeiDouResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIssueOfDataBeiDouResult>(ptr);
    }

    bool GetIssueOfDataBeiDouResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Clock"])
          && parse_json<int>::is_valid(m_values["Ephemeris"])
        ;

    }

    std::string GetIssueOfDataBeiDouResult::documentation() const { return Documentation; }


    int GetIssueOfDataBeiDouResult::clock() const
    {
      return parse_json<int>::parse(m_values["Clock"]);
    }

    void GetIssueOfDataBeiDouResult::setClock(int clock)
    {
      m_values.AddMember("Clock", parse_json<int>::format(clock, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetIssueOfDataBeiDouResult::ephemeris() const
    {
      return parse_json<int>::parse(m_values["Ephemeris"]);
    }

    void GetIssueOfDataBeiDouResult::setEphemeris(int ephemeris)
    {
      m_values.AddMember("Ephemeris", parse_json<int>::format(ephemeris, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
