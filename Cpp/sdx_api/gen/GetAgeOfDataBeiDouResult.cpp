
#include "GetAgeOfDataBeiDouResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAgeOfDataBeiDouResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAgeOfDataBeiDouResult::CmdName = "GetAgeOfDataBeiDouResult";
    const char* const GetAgeOfDataBeiDouResult::Documentation = "Result of GetAgeOfDataBeiDou.\n"
      "\n"
      "Name          Type          Description\n"
      "------------- ------------- ---------------------------------------------------\n"
      "Clock         int           Age of data, clock\n"
      "Ephemeris     int           Age of data, ephemeris\n"
      "OverrideRinex optional bool If the AOD overrides the RINEX AOD, default is True";
    const char* const GetAgeOfDataBeiDouResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAgeOfDataBeiDouResult);


    GetAgeOfDataBeiDouResult::GetAgeOfDataBeiDouResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetAgeOfDataBeiDouResult::GetAgeOfDataBeiDouResult(int clock, int ephemeris, const std::optional<bool>& overrideRinex)
      : CommandResult(CmdName, TargetId)
    {

      setClock(clock);
      setEphemeris(ephemeris);
      setOverrideRinex(overrideRinex);
    }

    GetAgeOfDataBeiDouResult::GetAgeOfDataBeiDouResult(CommandBasePtr relatedCommand, int clock, int ephemeris, const std::optional<bool>& overrideRinex)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setClock(clock);
      setEphemeris(ephemeris);
      setOverrideRinex(overrideRinex);
    }


    GetAgeOfDataBeiDouResultPtr GetAgeOfDataBeiDouResult::create(int clock, int ephemeris, const std::optional<bool>& overrideRinex)
    {
      return std::make_shared<GetAgeOfDataBeiDouResult>(clock, ephemeris, overrideRinex);
    }

    GetAgeOfDataBeiDouResultPtr GetAgeOfDataBeiDouResult::create(CommandBasePtr relatedCommand, int clock, int ephemeris, const std::optional<bool>& overrideRinex)
    {
      return std::make_shared<GetAgeOfDataBeiDouResult>(relatedCommand, clock, ephemeris, overrideRinex);
    }

    GetAgeOfDataBeiDouResultPtr GetAgeOfDataBeiDouResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAgeOfDataBeiDouResult>(ptr);
    }

    bool GetAgeOfDataBeiDouResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Clock"])
          && parse_json<int>::is_valid(m_values["Ephemeris"])
          && parse_json<std::optional<bool>>::is_valid(m_values["OverrideRinex"])
        ;

    }

    std::string GetAgeOfDataBeiDouResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetAgeOfDataBeiDouResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Clock", "Ephemeris", "OverrideRinex"}; 
      return names; 
    }


    int GetAgeOfDataBeiDouResult::clock() const
    {
      return parse_json<int>::parse(m_values["Clock"]);
    }

    void GetAgeOfDataBeiDouResult::setClock(int clock)
    {
      m_values.AddMember("Clock", parse_json<int>::format(clock, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetAgeOfDataBeiDouResult::ephemeris() const
    {
      return parse_json<int>::parse(m_values["Ephemeris"]);
    }

    void GetAgeOfDataBeiDouResult::setEphemeris(int ephemeris)
    {
      m_values.AddMember("Ephemeris", parse_json<int>::format(ephemeris, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<bool> GetAgeOfDataBeiDouResult::overrideRinex() const
    {
      return parse_json<std::optional<bool>>::parse(m_values["OverrideRinex"]);
    }

    void GetAgeOfDataBeiDouResult::setOverrideRinex(const std::optional<bool>& overrideRinex)
    {
      m_values.AddMember("OverrideRinex", parse_json<std::optional<bool>>::format(overrideRinex, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
