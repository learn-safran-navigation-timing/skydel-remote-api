
#include "gen/SetVehicleTrajectoryOrbit.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetVehicleTrajectoryOrbit
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetVehicleTrajectoryOrbit::CmdName = "SetVehicleTrajectoryOrbit";
    const char* const SetVehicleTrajectoryOrbit::Documentation = "Set earth-orbiting spacecraft trajectory.";

    REGISTER_COMMAND_FACTORY(SetVehicleTrajectoryOrbit);


    SetVehicleTrajectoryOrbit::SetVehicleTrajectoryOrbit()
      : CommandBase(CmdName)
    {}

    SetVehicleTrajectoryOrbit::SetVehicleTrajectoryOrbit(const std::string& type, const Sdx::DateTime& reference, double semiMajorAxis, double inclination, double rightAscension, double eccentricity, double meanAnomaly, double argumentOfPerigee)
      : CommandBase(CmdName)
    {

      setType(type);
      setReference(reference);
      setSemiMajorAxis(semiMajorAxis);
      setInclination(inclination);
      setRightAscension(rightAscension);
      setEccentricity(eccentricity);
      setMeanAnomaly(meanAnomaly);
      setArgumentOfPerigee(argumentOfPerigee);
    }

    SetVehicleTrajectoryOrbitPtr SetVehicleTrajectoryOrbit::create(const std::string& type, const Sdx::DateTime& reference, double semiMajorAxis, double inclination, double rightAscension, double eccentricity, double meanAnomaly, double argumentOfPerigee)
    {
      return std::make_shared<SetVehicleTrajectoryOrbit>(type, reference, semiMajorAxis, inclination, rightAscension, eccentricity, meanAnomaly, argumentOfPerigee);
    }

    SetVehicleTrajectoryOrbitPtr SetVehicleTrajectoryOrbit::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetVehicleTrajectoryOrbit>(ptr);
    }

    bool SetVehicleTrajectoryOrbit::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Type"])
          && parse_json<Sdx::DateTime>::is_valid(m_values["Reference"])
          && parse_json<double>::is_valid(m_values["SemiMajorAxis"])
          && parse_json<double>::is_valid(m_values["Inclination"])
          && parse_json<double>::is_valid(m_values["RightAscension"])
          && parse_json<double>::is_valid(m_values["Eccentricity"])
          && parse_json<double>::is_valid(m_values["MeanAnomaly"])
          && parse_json<double>::is_valid(m_values["ArgumentOfPerigee"])
        ;

    }

    std::string SetVehicleTrajectoryOrbit::documentation() const { return Documentation; }


    int SetVehicleTrajectoryOrbit::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetVehicleTrajectoryOrbit::type() const
    {
      return parse_json<std::string>::parse(m_values["Type"]);
    }

    void SetVehicleTrajectoryOrbit::setType(const std::string& type)
    {
      m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::DateTime SetVehicleTrajectoryOrbit::reference() const
    {
      return parse_json<Sdx::DateTime>::parse(m_values["Reference"]);
    }

    void SetVehicleTrajectoryOrbit::setReference(const Sdx::DateTime& reference)
    {
      m_values.AddMember("Reference", parse_json<Sdx::DateTime>::format(reference, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetVehicleTrajectoryOrbit::semiMajorAxis() const
    {
      return parse_json<double>::parse(m_values["SemiMajorAxis"]);
    }

    void SetVehicleTrajectoryOrbit::setSemiMajorAxis(double semiMajorAxis)
    {
      m_values.AddMember("SemiMajorAxis", parse_json<double>::format(semiMajorAxis, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetVehicleTrajectoryOrbit::inclination() const
    {
      return parse_json<double>::parse(m_values["Inclination"]);
    }

    void SetVehicleTrajectoryOrbit::setInclination(double inclination)
    {
      m_values.AddMember("Inclination", parse_json<double>::format(inclination, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetVehicleTrajectoryOrbit::rightAscension() const
    {
      return parse_json<double>::parse(m_values["RightAscension"]);
    }

    void SetVehicleTrajectoryOrbit::setRightAscension(double rightAscension)
    {
      m_values.AddMember("RightAscension", parse_json<double>::format(rightAscension, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetVehicleTrajectoryOrbit::eccentricity() const
    {
      return parse_json<double>::parse(m_values["Eccentricity"]);
    }

    void SetVehicleTrajectoryOrbit::setEccentricity(double eccentricity)
    {
      m_values.AddMember("Eccentricity", parse_json<double>::format(eccentricity, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetVehicleTrajectoryOrbit::meanAnomaly() const
    {
      return parse_json<double>::parse(m_values["MeanAnomaly"]);
    }

    void SetVehicleTrajectoryOrbit::setMeanAnomaly(double meanAnomaly)
    {
      m_values.AddMember("MeanAnomaly", parse_json<double>::format(meanAnomaly, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetVehicleTrajectoryOrbit::argumentOfPerigee() const
    {
      return parse_json<double>::parse(m_values["ArgumentOfPerigee"]);
    }

    void SetVehicleTrajectoryOrbit::setArgumentOfPerigee(double argumentOfPerigee)
    {
      m_values.AddMember("ArgumentOfPerigee", parse_json<double>::format(argumentOfPerigee, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
