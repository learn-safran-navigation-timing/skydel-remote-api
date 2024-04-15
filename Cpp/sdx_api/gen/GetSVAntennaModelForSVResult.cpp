
#include "GetSVAntennaModelForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVAntennaModelForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVAntennaModelForSVResult::CmdName = "GetSVAntennaModelForSVResult";
    const char* const GetSVAntennaModelForSVResult::Documentation = "Result of GetSVAntennaModelForSV.\n"
      "\n"
      "Name             Type   Description\n"
      "---------------- ------ ---------------------------------------------------------------------------\n"
      "System           string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\".\n"
      "SvId             int    The satellite's SV ID.\n"
      "AntennaModelName string SV antenna model name.";
    const char* const GetSVAntennaModelForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSVAntennaModelForSVResult);


    GetSVAntennaModelForSVResult::GetSVAntennaModelForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetSVAntennaModelForSVResult::GetSVAntennaModelForSVResult(const std::string& system, int svId, const std::string& antennaModelName)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setAntennaModelName(antennaModelName);
    }

    GetSVAntennaModelForSVResult::GetSVAntennaModelForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& antennaModelName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
      setAntennaModelName(antennaModelName);
    }


    GetSVAntennaModelForSVResultPtr GetSVAntennaModelForSVResult::create(const std::string& system, int svId, const std::string& antennaModelName)
    {
      return std::make_shared<GetSVAntennaModelForSVResult>(system, svId, antennaModelName);
    }

    GetSVAntennaModelForSVResultPtr GetSVAntennaModelForSVResult::create(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& antennaModelName)
    {
      return std::make_shared<GetSVAntennaModelForSVResult>(relatedCommand, system, svId, antennaModelName);
    }

    GetSVAntennaModelForSVResultPtr GetSVAntennaModelForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSVAntennaModelForSVResult>(ptr);
    }

    bool GetSVAntennaModelForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["AntennaModelName"])
        ;

    }

    std::string GetSVAntennaModelForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSVAntennaModelForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "AntennaModelName"}; 
      return names; 
    }


    std::string GetSVAntennaModelForSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetSVAntennaModelForSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSVAntennaModelForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetSVAntennaModelForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSVAntennaModelForSVResult::antennaModelName() const
    {
      return parse_json<std::string>::parse(m_values["AntennaModelName"]);
    }

    void GetSVAntennaModelForSVResult::setAntennaModelName(const std::string& antennaModelName)
    {
      m_values.AddMember("AntennaModelName", parse_json<std::string>::format(antennaModelName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
