
#include "gen/SetVehicleTrajectoryCircular.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetVehicleTrajectoryCircular
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetVehicleTrajectoryCircular::CmdName = "SetVehicleTrajectoryCircular";
    const char* const SetVehicleTrajectoryCircular::Documentation = "Set vehicle circular trajectory";

    REGISTER_COMMAND_FACTORY(SetVehicleTrajectoryCircular);


    SetVehicleTrajectoryCircular::SetVehicleTrajectoryCircular()
      : CommandBase(CmdName)
    {}

    SetVehicleTrajectoryCircular::SetVehicleTrajectoryCircular(const std::string& type, double lat, double lon, double alt, double radius, double speed, bool clockwise, const Sdx::optional<double>& originAngle)
      : CommandBase(CmdName)
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

    SetVehicleTrajectoryCircularPtr SetVehicleTrajectoryCircular::create(const std::string& type, double lat, double lon, double alt, double radius, double speed, bool clockwise, const Sdx::optional<double>& originAngle)
    {
      return std::make_shared<SetVehicleTrajectoryCircular>(type, lat, lon, alt, radius, speed, clockwise, originAngle);
    }

    SetVehicleTrajectoryCircularPtr SetVehicleTrajectoryCircular::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetVehicleTrajectoryCircular>(ptr);
    }

    bool SetVehicleTrajectoryCircular::isValid() const
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

    std::string SetVehicleTrajectoryCircular::documentation() const { return Documentation; }


    int SetVehicleTrajectoryCircular::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetVehicleTrajectoryCircular::type() const
    {
      return parse_json<std::string>::parse(m_values["Type"]);
    }

    void SetVehicleTrajectoryCircular::setType(const std::string& type)
    {
      m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetVehicleTrajectoryCircular::lat() const
    {
      return parse_json<double>::parse(m_values["Lat"]);
    }

    void SetVehicleTrajectoryCircular::setLat(double lat)
    {
      m_values.AddMember("Lat", parse_json<double>::format(lat, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetVehicleTrajectoryCircular::lon() const
    {
      return parse_json<double>::parse(m_values["Lon"]);
    }

    void SetVehicleTrajectoryCircular::setLon(double lon)
    {
      m_values.AddMember("Lon", parse_json<double>::format(lon, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetVehicleTrajectoryCircular::alt() const
    {
      return parse_json<double>::parse(m_values["Alt"]);
    }

    void SetVehicleTrajectoryCircular::setAlt(double alt)
    {
      m_values.AddMember("Alt", parse_json<double>::format(alt, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetVehicleTrajectoryCircular::radius() const
    {
      return parse_json<double>::parse(m_values["Radius"]);
    }

    void SetVehicleTrajectoryCircular::setRadius(double radius)
    {
      m_values.AddMember("Radius", parse_json<double>::format(radius, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetVehicleTrajectoryCircular::speed() const
    {
      return parse_json<double>::parse(m_values["Speed"]);
    }

    void SetVehicleTrajectoryCircular::setSpeed(double speed)
    {
      m_values.AddMember("Speed", parse_json<double>::format(speed, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetVehicleTrajectoryCircular::clockwise() const
    {
      return parse_json<bool>::parse(m_values["Clockwise"]);
    }

    void SetVehicleTrajectoryCircular::setClockwise(bool clockwise)
    {
      m_values.AddMember("Clockwise", parse_json<bool>::format(clockwise, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<double> SetVehicleTrajectoryCircular::originAngle() const
    {
      return parse_json<Sdx::optional<double>>::parse(m_values["OriginAngle"]);
    }

    void SetVehicleTrajectoryCircular::setOriginAngle(const Sdx::optional<double>& originAngle)
    {
      m_values.AddMember("OriginAngle", parse_json<Sdx::optional<double>>::format(originAngle, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
