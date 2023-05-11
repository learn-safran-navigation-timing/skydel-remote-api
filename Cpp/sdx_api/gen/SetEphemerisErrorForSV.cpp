
#include "gen/SetEphemerisErrorForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetEphemerisErrorForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetEphemerisErrorForSV::CmdName = "SetEphemerisErrorForSV";
    const char* const SetEphemerisErrorForSV::Documentation = "Set the satellite ephemeris error.";

    REGISTER_COMMAND_FACTORY(SetEphemerisErrorForSV);


    SetEphemerisErrorForSV::SetEphemerisErrorForSV()
      : CommandBase(CmdName)
    {}

    SetEphemerisErrorForSV::SetEphemerisErrorForSV(const std::string& system, int svId, const Sdx::RIC& orbit, double deltaAf0, double deltaAf1)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setOrbit(orbit);
      setDeltaAf0(deltaAf0);
      setDeltaAf1(deltaAf1);
    }

    SetEphemerisErrorForSVPtr SetEphemerisErrorForSV::create(const std::string& system, int svId, const Sdx::RIC& orbit, double deltaAf0, double deltaAf1)
    {
      return std::make_shared<SetEphemerisErrorForSV>(system, svId, orbit, deltaAf0, deltaAf1);
    }

    SetEphemerisErrorForSVPtr SetEphemerisErrorForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetEphemerisErrorForSV>(ptr);
    }

    bool SetEphemerisErrorForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::RIC>::is_valid(m_values["Orbit"])
          && parse_json<double>::is_valid(m_values["DeltaAf0"])
          && parse_json<double>::is_valid(m_values["DeltaAf1"])
        ;

    }

    std::string SetEphemerisErrorForSV::documentation() const { return Documentation; }


    int SetEphemerisErrorForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetEphemerisErrorForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetEphemerisErrorForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetEphemerisErrorForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetEphemerisErrorForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::RIC SetEphemerisErrorForSV::orbit() const
    {
      return parse_json<Sdx::RIC>::parse(m_values["Orbit"]);
    }

    void SetEphemerisErrorForSV::setOrbit(const Sdx::RIC& orbit)
    {
      m_values.AddMember("Orbit", parse_json<Sdx::RIC>::format(orbit, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetEphemerisErrorForSV::deltaAf0() const
    {
      return parse_json<double>::parse(m_values["DeltaAf0"]);
    }

    void SetEphemerisErrorForSV::setDeltaAf0(double deltaAf0)
    {
      m_values.AddMember("DeltaAf0", parse_json<double>::format(deltaAf0, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetEphemerisErrorForSV::deltaAf1() const
    {
      return parse_json<double>::parse(m_values["DeltaAf1"]);
    }

    void SetEphemerisErrorForSV::setDeltaAf1(double deltaAf1)
    {
      m_values.AddMember("DeltaAf1", parse_json<double>::format(deltaAf1, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
