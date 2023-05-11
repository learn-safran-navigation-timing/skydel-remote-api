
#include "gen/GetManualPowerOffsetForSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetManualPowerOffsetForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetManualPowerOffsetForSVResult::CmdName = "GetManualPowerOffsetForSVResult";
    const char* const GetManualPowerOffsetForSVResult::Documentation = "Result of GetManualPowerOffsetForSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetManualPowerOffsetForSVResult);


    GetManualPowerOffsetForSVResult::GetManualPowerOffsetForSVResult()
      : CommandResult(CmdName)
    {}

    GetManualPowerOffsetForSVResult::GetManualPowerOffsetForSVResult(const std::string& system, int svId, const std::map<std::string, double>& signalPowerOffsetDict)
      : CommandResult(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setSignalPowerOffsetDict(signalPowerOffsetDict);
    }

    GetManualPowerOffsetForSVResult::GetManualPowerOffsetForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::map<std::string, double>& signalPowerOffsetDict)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
      setSignalPowerOffsetDict(signalPowerOffsetDict);
    }


    GetManualPowerOffsetForSVResultPtr GetManualPowerOffsetForSVResult::create(const std::string& system, int svId, const std::map<std::string, double>& signalPowerOffsetDict)
    {
      return std::make_shared<GetManualPowerOffsetForSVResult>(system, svId, signalPowerOffsetDict);
    }

    GetManualPowerOffsetForSVResultPtr GetManualPowerOffsetForSVResult::create(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::map<std::string, double>& signalPowerOffsetDict)
    {
      return std::make_shared<GetManualPowerOffsetForSVResult>(relatedCommand, system, svId, signalPowerOffsetDict);
    }

    GetManualPowerOffsetForSVResultPtr GetManualPowerOffsetForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetManualPowerOffsetForSVResult>(ptr);
    }

    bool GetManualPowerOffsetForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::map<std::string, double>>::is_valid(m_values["SignalPowerOffsetDict"])
        ;

    }

    std::string GetManualPowerOffsetForSVResult::documentation() const { return Documentation; }


    std::string GetManualPowerOffsetForSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetManualPowerOffsetForSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetManualPowerOffsetForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetManualPowerOffsetForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::map<std::string, double> GetManualPowerOffsetForSVResult::signalPowerOffsetDict() const
    {
      return parse_json<std::map<std::string, double>>::parse(m_values["SignalPowerOffsetDict"]);
    }

    void GetManualPowerOffsetForSVResult::setSignalPowerOffsetDict(const std::map<std::string, double>& signalPowerOffsetDict)
    {
      m_values.AddMember("SignalPowerOffsetDict", parse_json<std::map<std::string, double>>::format(signalPowerOffsetDict, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
