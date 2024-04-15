
#include "GetIssueOfDataResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIssueOfDataResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIssueOfDataResult::CmdName = "GetIssueOfDataResult";
    const char* const GetIssueOfDataResult::Documentation = "Result of GetIssueOfData.\n"
      "\n"
      "Name          Type          Description\n"
      "------------- ------------- ---------------------------------------------------\n"
      "Clock         int           Issue of data, clock\n"
      "Ephemeris     int           Issue of data, ephemeris\n"
      "OverrideRinex optional bool If the IOD overrides the RINEX IOD, default is True";
    const char* const GetIssueOfDataResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIssueOfDataResult);


    GetIssueOfDataResult::GetIssueOfDataResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetIssueOfDataResult::GetIssueOfDataResult(int clock, int ephemeris, const Sdx::optional<bool>& overrideRinex)
      : CommandResult(CmdName, TargetId)
    {

      setClock(clock);
      setEphemeris(ephemeris);
      setOverrideRinex(overrideRinex);
    }

    GetIssueOfDataResult::GetIssueOfDataResult(CommandBasePtr relatedCommand, int clock, int ephemeris, const Sdx::optional<bool>& overrideRinex)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& GetIssueOfDataResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Clock", "Ephemeris", "OverrideRinex"}; 
      return names; 
    }


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
