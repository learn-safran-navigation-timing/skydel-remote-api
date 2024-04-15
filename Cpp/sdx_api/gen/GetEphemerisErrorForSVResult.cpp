
#include "GetEphemerisErrorForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetEphemerisErrorForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetEphemerisErrorForSVResult::CmdName = "GetEphemerisErrorForSVResult";
    const char* const GetEphemerisErrorForSVResult::Documentation = "Result of GetEphemerisErrorForSV.\n"
      "\n"
      "Name     Type   Description\n"
      "-------- ------ -----------------------------------------------------------------------------------\n"
      "System   string \"GPS\", \"Galileo\", \"GLONASS\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "SvId     int    Satellite SV ID.\n"
      "Orbit    RIC    The orbit error, in relative orbit frame. In-track error not available for GLONASS.\n"
      "DeltaAf0 double The clock bias error, in second. DeltaTaun for GLONASS.\n"
      "DeltaAf1 double The clock drift error, in second/second. Not available for GLONASS.";
    const char* const GetEphemerisErrorForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetEphemerisErrorForSVResult);


    GetEphemerisErrorForSVResult::GetEphemerisErrorForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetEphemerisErrorForSVResult::GetEphemerisErrorForSVResult(const std::string& system, int svId, const Sdx::RIC& orbit, double deltaAf0, double deltaAf1)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setOrbit(orbit);
      setDeltaAf0(deltaAf0);
      setDeltaAf1(deltaAf1);
    }

    GetEphemerisErrorForSVResult::GetEphemerisErrorForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const Sdx::RIC& orbit, double deltaAf0, double deltaAf1)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
      setOrbit(orbit);
      setDeltaAf0(deltaAf0);
      setDeltaAf1(deltaAf1);
    }


    GetEphemerisErrorForSVResultPtr GetEphemerisErrorForSVResult::create(const std::string& system, int svId, const Sdx::RIC& orbit, double deltaAf0, double deltaAf1)
    {
      return std::make_shared<GetEphemerisErrorForSVResult>(system, svId, orbit, deltaAf0, deltaAf1);
    }

    GetEphemerisErrorForSVResultPtr GetEphemerisErrorForSVResult::create(CommandBasePtr relatedCommand, const std::string& system, int svId, const Sdx::RIC& orbit, double deltaAf0, double deltaAf1)
    {
      return std::make_shared<GetEphemerisErrorForSVResult>(relatedCommand, system, svId, orbit, deltaAf0, deltaAf1);
    }

    GetEphemerisErrorForSVResultPtr GetEphemerisErrorForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetEphemerisErrorForSVResult>(ptr);
    }

    bool GetEphemerisErrorForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::RIC>::is_valid(m_values["Orbit"])
          && parse_json<double>::is_valid(m_values["DeltaAf0"])
          && parse_json<double>::is_valid(m_values["DeltaAf1"])
        ;

    }

    std::string GetEphemerisErrorForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetEphemerisErrorForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "Orbit", "DeltaAf0", "DeltaAf1"}; 
      return names; 
    }


    std::string GetEphemerisErrorForSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetEphemerisErrorForSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetEphemerisErrorForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetEphemerisErrorForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::RIC GetEphemerisErrorForSVResult::orbit() const
    {
      return parse_json<Sdx::RIC>::parse(m_values["Orbit"]);
    }

    void GetEphemerisErrorForSVResult::setOrbit(const Sdx::RIC& orbit)
    {
      m_values.AddMember("Orbit", parse_json<Sdx::RIC>::format(orbit, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetEphemerisErrorForSVResult::deltaAf0() const
    {
      return parse_json<double>::parse(m_values["DeltaAf0"]);
    }

    void GetEphemerisErrorForSVResult::setDeltaAf0(double deltaAf0)
    {
      m_values.AddMember("DeltaAf0", parse_json<double>::format(deltaAf0, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetEphemerisErrorForSVResult::deltaAf1() const
    {
      return parse_json<double>::parse(m_values["DeltaAf1"]);
    }

    void GetEphemerisErrorForSVResult::setDeltaAf1(double deltaAf1)
    {
      m_values.AddMember("DeltaAf1", parse_json<double>::format(deltaAf1, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
