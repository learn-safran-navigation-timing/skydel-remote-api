
#include "gen/GetVehicleTrajectoryCircularResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleTrajectoryCircularResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleTrajectoryCircularResult::CmdName = "GetVehicleTrajectoryCircularResult";
    const char* const GetVehicleTrajectoryCircularResult::Documentation = "Result of GetVehicleTrajectoryCircular.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetVehicleTrajectoryCircularResult);


    GetVehicleTrajectoryCircularResult::GetVehicleTrajectoryCircularResult()
      : CommandResult(CmdName)
    {}

    GetVehicleTrajectoryCircularResult::GetVehicleTrajectoryCircularResult(const std::string& type, double lat, double lon, double alt, double radius, double speed, bool clockwise, const Sdx::optional<double>& originAngle)
      : CommandResult(CmdName)
    {

      setType(type);
      setLat(lat);
      setLon(lon);
      setAlt(alt);
      setRadius(radius);
      setSpeed(speed);
      setClockwise(clockwise);
      setOriginAngle(originAngle);
    }

    GetVehicleTrajectoryCircularResult::GetVehicleTrajectoryCircularResult(CommandBasePtr relatedCommand, const std::string& type, double lat, double lon, double alt, double radius, double speed, bool clockwise, const Sdx::optional<double>& originAngle)
      : CommandResult(CmdName, relatedCommand)
    {

      setType(type);
      setLat(lat);
      setLon(lon);
      setAlt(alt);
      setRadius(radius);
      setSpeed(speed);
      setClockwise(clockwise);
      setOriginAngle(originAngle);
    }


    GetVehicleTrajectoryCircularResultPtr GetVehicleTrajectoryCircularResult::create(const std::string& type, double lat, double lon, double alt, double radius, double speed, bool clockwise, const Sdx::optional<double>& originAngle)
    {
      return std::make_shared<GetVehicleTrajectoryCircularResult>(type, lat, lon, alt, radius, speed, clockwise, originAngle);
    }

    GetVehicleTrajectoryCircularResultPtr GetVehicleTrajectoryCircularResult::create(CommandBasePtr relatedCommand, const std::string& type, double lat, double lon, double alt, double radius, double speed, bool clockwise, const Sdx::optional<double>& originAngle)
    {
      return std::make_shared<GetVehicleTrajectoryCircularResult>(relatedCommand, type, lat, lon, alt, radius, speed, clockwise, originAngle);
    }

    GetVehicleTrajectoryCircularResultPtr GetVehicleTrajectoryCircularResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleTrajectoryCircularResult>(ptr);
    }

    bool GetVehicleTrajectoryCircularResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Type"])
          && parse_json<double>::is_valid(m_values["Lat"])
          && parse_json<double>::is_valid(m_values["Lon"])
          && parse_json<double>::is_valid(m_values["Alt"])
          && parse_json<double>::is_valid(m_values["Radius"])
          && parse_json<double>::is_valid(m_values["Speed"])
          && parse_json<bool>::is_valid(m_values["Clockwise"])
          && parse_json<Sdx::optional<double>>::is_valid(m_values["OriginAngle"])
        ;

    }

    std::string GetVehicleTrajectoryCircularResult::documentation() const { return Documentation; }


    std::string GetVehicleTrajectoryCircularResult::type() const
    {
      return parse_json<std::string>::parse(m_values["Type"]);
    }

    void GetVehicleTrajectoryCircularResult::setType(const std::string& type)
    {
      m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleTrajectoryCircularResult::lat() const
    {
      return parse_json<double>::parse(m_values["Lat"]);
    }

    void GetVehicleTrajectoryCircularResult::setLat(double lat)
    {
      m_values.AddMember("Lat", parse_json<double>::format(lat, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleTrajectoryCircularResult::lon() const
    {
      return parse_json<double>::parse(m_values["Lon"]);
    }

    void GetVehicleTrajectoryCircularResult::setLon(double lon)
    {
      m_values.AddMember("Lon", parse_json<double>::format(lon, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleTrajectoryCircularResult::alt() const
    {
      return parse_json<double>::parse(m_values["Alt"]);
    }

    void GetVehicleTrajectoryCircularResult::setAlt(double alt)
    {
      m_values.AddMember("Alt", parse_json<double>::format(alt, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleTrajectoryCircularResult::radius() const
    {
      return parse_json<double>::parse(m_values["Radius"]);
    }

    void GetVehicleTrajectoryCircularResult::setRadius(double radius)
    {
      m_values.AddMember("Radius", parse_json<double>::format(radius, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleTrajectoryCircularResult::speed() const
    {
      return parse_json<double>::parse(m_values["Speed"]);
    }

    void GetVehicleTrajectoryCircularResult::setSpeed(double speed)
    {
      m_values.AddMember("Speed", parse_json<double>::format(speed, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetVehicleTrajectoryCircularResult::clockwise() const
    {
      return parse_json<bool>::parse(m_values["Clockwise"]);
    }

    void GetVehicleTrajectoryCircularResult::setClockwise(bool clockwise)
    {
      m_values.AddMember("Clockwise", parse_json<bool>::format(clockwise, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<double> GetVehicleTrajectoryCircularResult::originAngle() const
    {
      return parse_json<Sdx::optional<double>>::parse(m_values["OriginAngle"]);
    }

    void GetVehicleTrajectoryCircularResult::setOriginAngle(const Sdx::optional<double>& originAngle)
    {
      m_values.AddMember("OriginAngle", parse_json<Sdx::optional<double>>::format(originAngle, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
