
#include "GetEnabledSignalsForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetEnabledSignalsForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetEnabledSignalsForSVResult::CmdName = "GetEnabledSignalsForSVResult";
    const char* const GetEnabledSignalsForSVResult::Documentation = "Result of GetEnabledSignalsForSV.\n"
      "\n"
      "Name        Type         Description\n"
      "----------- ------------ ----------------------------------------------------------------------------------------------\n"
      "System      string       The system, can be \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\".\n"
      "SvId        int          The satellite SV ID.\n"
      "SignalArray array string The list of enabled signals.";
    const char* const GetEnabledSignalsForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetEnabledSignalsForSVResult);


    GetEnabledSignalsForSVResult::GetEnabledSignalsForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetEnabledSignalsForSVResult::GetEnabledSignalsForSVResult(const std::string& system, int svId, const std::vector<std::string>& signalArray)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setSignalArray(signalArray);
    }

    GetEnabledSignalsForSVResult::GetEnabledSignalsForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::vector<std::string>& signalArray)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
      setSignalArray(signalArray);
    }


    GetEnabledSignalsForSVResultPtr GetEnabledSignalsForSVResult::create(const std::string& system, int svId, const std::vector<std::string>& signalArray)
    {
      return std::make_shared<GetEnabledSignalsForSVResult>(system, svId, signalArray);
    }

    GetEnabledSignalsForSVResultPtr GetEnabledSignalsForSVResult::create(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::vector<std::string>& signalArray)
    {
      return std::make_shared<GetEnabledSignalsForSVResult>(relatedCommand, system, svId, signalArray);
    }

    GetEnabledSignalsForSVResultPtr GetEnabledSignalsForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetEnabledSignalsForSVResult>(ptr);
    }

    bool GetEnabledSignalsForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::vector<std::string>>::is_valid(m_values["SignalArray"])
        ;

    }

    std::string GetEnabledSignalsForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetEnabledSignalsForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "SignalArray"}; 
      return names; 
    }


    std::string GetEnabledSignalsForSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetEnabledSignalsForSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetEnabledSignalsForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetEnabledSignalsForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<std::string> GetEnabledSignalsForSVResult::signalArray() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["SignalArray"]);
    }

    void GetEnabledSignalsForSVResult::setSignalArray(const std::vector<std::string>& signalArray)
    {
      m_values.AddMember("SignalArray", parse_json<std::vector<std::string>>::format(signalArray, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
