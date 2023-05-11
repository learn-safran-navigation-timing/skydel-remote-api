
#include "gen/GetVehicleTrajectoryOrbitResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleTrajectoryOrbitResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleTrajectoryOrbitResult::CmdName = "GetVehicleTrajectoryOrbitResult";
    const char* const GetVehicleTrajectoryOrbitResult::Documentation = "Result of GetVehicleTrajectoryOrbit.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetVehicleTrajectoryOrbitResult);


    GetVehicleTrajectoryOrbitResult::GetVehicleTrajectoryOrbitResult()
      : CommandResult(CmdName)
    {}

    GetVehicleTrajectoryOrbitResult::GetVehicleTrajectoryOrbitResult(const std::string& type, const Sdx::DateTime& reference, double semiMajorAxis, double inclination, double rightAscension, double eccentricity, double meanAnomaly, double argumentOfPerigee)
      : CommandResult(CmdName)
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

    GetVehicleTrajectoryOrbitResult::GetVehicleTrajectoryOrbitResult(CommandBasePtr relatedCommand, const std::string& type, const Sdx::DateTime& reference, double semiMajorAxis, double inclination, double rightAscension, double eccentricity, double meanAnomaly, double argumentOfPerigee)
      : CommandResult(CmdName, relatedCommand)
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


    GetVehicleTrajectoryOrbitResultPtr GetVehicleTrajectoryOrbitResult::create(const std::string& type, const Sdx::DateTime& reference, double semiMajorAxis, double inclination, double rightAscension, double eccentricity, double meanAnomaly, double argumentOfPerigee)
    {
      return std::make_shared<GetVehicleTrajectoryOrbitResult>(type, reference, semiMajorAxis, inclination, rightAscension, eccentricity, meanAnomaly, argumentOfPerigee);
    }

    GetVehicleTrajectoryOrbitResultPtr GetVehicleTrajectoryOrbitResult::create(CommandBasePtr relatedCommand, const std::string& type, const Sdx::DateTime& reference, double semiMajorAxis, double inclination, double rightAscension, double eccentricity, double meanAnomaly, double argumentOfPerigee)
    {
      return std::make_shared<GetVehicleTrajectoryOrbitResult>(relatedCommand, type, reference, semiMajorAxis, inclination, rightAscension, eccentricity, meanAnomaly, argumentOfPerigee);
    }

    GetVehicleTrajectoryOrbitResultPtr GetVehicleTrajectoryOrbitResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleTrajectoryOrbitResult>(ptr);
    }

    bool GetVehicleTrajectoryOrbitResult::isValid() const
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

    std::string GetVehicleTrajectoryOrbitResult::documentation() const { return Documentation; }


    std::string GetVehicleTrajectoryOrbitResult::type() const
    {
      return parse_json<std::string>::parse(m_values["Type"]);
    }

    void GetVehicleTrajectoryOrbitResult::setType(const std::string& type)
    {
      m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::DateTime GetVehicleTrajectoryOrbitResult::reference() const
    {
      return parse_json<Sdx::DateTime>::parse(m_values["Reference"]);
    }

    void GetVehicleTrajectoryOrbitResult::setReference(const Sdx::DateTime& reference)
    {
      m_values.AddMember("Reference", parse_json<Sdx::DateTime>::format(reference, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleTrajectoryOrbitResult::semiMajorAxis() const
    {
      return parse_json<double>::parse(m_values["SemiMajorAxis"]);
    }

    void GetVehicleTrajectoryOrbitResult::setSemiMajorAxis(double semiMajorAxis)
    {
      m_values.AddMember("SemiMajorAxis", parse_json<double>::format(semiMajorAxis, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleTrajectoryOrbitResult::inclination() const
    {
      return parse_json<double>::parse(m_values["Inclination"]);
    }

    void GetVehicleTrajectoryOrbitResult::setInclination(double inclination)
    {
      m_values.AddMember("Inclination", parse_json<double>::format(inclination, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleTrajectoryOrbitResult::rightAscension() const
    {
      return parse_json<double>::parse(m_values["RightAscension"]);
    }

    void GetVehicleTrajectoryOrbitResult::setRightAscension(double rightAscension)
    {
      m_values.AddMember("RightAscension", parse_json<double>::format(rightAscension, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleTrajectoryOrbitResult::eccentricity() const
    {
      return parse_json<double>::parse(m_values["Eccentricity"]);
    }

    void GetVehicleTrajectoryOrbitResult::setEccentricity(double eccentricity)
    {
      m_values.AddMember("Eccentricity", parse_json<double>::format(eccentricity, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleTrajectoryOrbitResult::meanAnomaly() const
    {
      return parse_json<double>::parse(m_values["MeanAnomaly"]);
    }

    void GetVehicleTrajectoryOrbitResult::setMeanAnomaly(double meanAnomaly)
    {
      m_values.AddMember("MeanAnomaly", parse_json<double>::format(meanAnomaly, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleTrajectoryOrbitResult::argumentOfPerigee() const
    {
      return parse_json<double>::parse(m_values["ArgumentOfPerigee"]);
    }

    void GetVehicleTrajectoryOrbitResult::setArgumentOfPerigee(double argumentOfPerigee)
    {
      m_values.AddMember("ArgumentOfPerigee", parse_json<double>::format(argumentOfPerigee, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
