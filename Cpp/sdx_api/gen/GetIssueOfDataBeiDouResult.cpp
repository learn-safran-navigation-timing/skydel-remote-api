
#include "GetIssueOfDataBeiDouResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIssueOfDataBeiDouResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIssueOfDataBeiDouResult::CmdName = "GetIssueOfDataBeiDouResult";
    const char* const GetIssueOfDataBeiDouResult::Documentation = "Result of GetIssueOfDataBeiDou.\n"
      "\n"
      "Name      Type Description\n"
      "--------- ---- ------------------------\n"
      "Clock     int  Issue of data, clock\n"
      "Ephemeris int  Issue of data, ephemeris";
    const char* const GetIssueOfDataBeiDouResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIssueOfDataBeiDouResult);


    GetIssueOfDataBeiDouResult::GetIssueOfDataBeiDouResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetIssueOfDataBeiDouResult::GetIssueOfDataBeiDouResult(int clock, int ephemeris)
      : CommandResult(CmdName, TargetId)
    {

      setClock(clock);
      setEphemeris(ephemeris);
    }

    GetIssueOfDataBeiDouResult::GetIssueOfDataBeiDouResult(CommandBasePtr relatedCommand, int clock, int ephemeris)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& GetIssueOfDataBeiDouResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Clock", "Ephemeris"}; 
      return names; 
    }


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
