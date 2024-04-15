
#include "GetVehicleTrajectoryFixResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleTrajectoryFixResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleTrajectoryFixResult::CmdName = "GetVehicleTrajectoryFixResult";
    const char* const GetVehicleTrajectoryFixResult::Documentation = "Result of GetVehicleTrajectoryFix.\n"
      "\n"
      "Name  Type   Description\n"
      "----- ------ -----------------------\n"
      "Type  string Trajectory type (\"Fix\")\n"
      "Lat   double Latitude (rad)\n"
      "Lon   double Longitude (rad)\n"
      "Alt   double Altitude (m)\n"
      "Yaw   double Yaw (rad)\n"
      "Pitch double Pitch (rad)\n"
      "Roll  double Roll (rad)";
    const char* const GetVehicleTrajectoryFixResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetVehicleTrajectoryFixResult);


    GetVehicleTrajectoryFixResult::GetVehicleTrajectoryFixResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetVehicleTrajectoryFixResult::GetVehicleTrajectoryFixResult(const std::string& type, double lat, double lon, double alt, double yaw, double pitch, double roll)
      : CommandResult(CmdName, TargetId)
    {

      setType(type);
      setLat(lat);
      setLon(lon);
      setAlt(alt);
      setYaw(yaw);
      setPitch(pitch);
      setRoll(roll);
    }

    GetVehicleTrajectoryFixResult::GetVehicleTrajectoryFixResult(CommandBasePtr relatedCommand, const std::string& type, double lat, double lon, double alt, double yaw, double pitch, double roll)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setType(type);
      setLat(lat);
      setLon(lon);
      setAlt(alt);
      setYaw(yaw);
      setPitch(pitch);
      setRoll(roll);
    }


    GetVehicleTrajectoryFixResultPtr GetVehicleTrajectoryFixResult::create(const std::string& type, double lat, double lon, double alt, double yaw, double pitch, double roll)
    {
      return std::make_shared<GetVehicleTrajectoryFixResult>(type, lat, lon, alt, yaw, pitch, roll);
    }

    GetVehicleTrajectoryFixResultPtr GetVehicleTrajectoryFixResult::create(CommandBasePtr relatedCommand, const std::string& type, double lat, double lon, double alt, double yaw, double pitch, double roll)
    {
      return std::make_shared<GetVehicleTrajectoryFixResult>(relatedCommand, type, lat, lon, alt, yaw, pitch, roll);
    }

    GetVehicleTrajectoryFixResultPtr GetVehicleTrajectoryFixResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleTrajectoryFixResult>(ptr);
    }

    bool GetVehicleTrajectoryFixResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Type"])
          && parse_json<double>::is_valid(m_values["Lat"])
          && parse_json<double>::is_valid(m_values["Lon"])
          && parse_json<double>::is_valid(m_values["Alt"])
          && parse_json<double>::is_valid(m_values["Yaw"])
          && parse_json<double>::is_valid(m_values["Pitch"])
          && parse_json<double>::is_valid(m_values["Roll"])
        ;

    }

    std::string GetVehicleTrajectoryFixResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetVehicleTrajectoryFixResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Type", "Lat", "Lon", "Alt", "Yaw", "Pitch", "Roll"}; 
      return names; 
    }


    std::string GetVehicleTrajectoryFixResult::type() const
    {
      return parse_json<std::string>::parse(m_values["Type"]);
    }

    void GetVehicleTrajectoryFixResult::setType(const std::string& type)
    {
      m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleTrajectoryFixResult::lat() const
    {
      return parse_json<double>::parse(m_values["Lat"]);
    }

    void GetVehicleTrajectoryFixResult::setLat(double lat)
    {
      m_values.AddMember("Lat", parse_json<double>::format(lat, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleTrajectoryFixResult::lon() const
    {
      return parse_json<double>::parse(m_values["Lon"]);
    }

    void GetVehicleTrajectoryFixResult::setLon(double lon)
    {
      m_values.AddMember("Lon", parse_json<double>::format(lon, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleTrajectoryFixResult::alt() const
    {
      return parse_json<double>::parse(m_values["Alt"]);
    }

    void GetVehicleTrajectoryFixResult::setAlt(double alt)
    {
      m_values.AddMember("Alt", parse_json<double>::format(alt, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleTrajectoryFixResult::yaw() const
    {
      return parse_json<double>::parse(m_values["Yaw"]);
    }

    void GetVehicleTrajectoryFixResult::setYaw(double yaw)
    {
      m_values.AddMember("Yaw", parse_json<double>::format(yaw, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleTrajectoryFixResult::pitch() const
    {
      return parse_json<double>::parse(m_values["Pitch"]);
    }

    void GetVehicleTrajectoryFixResult::setPitch(double pitch)
    {
      m_values.AddMember("Pitch", parse_json<double>::format(pitch, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleTrajectoryFixResult::roll() const
    {
      return parse_json<double>::parse(m_values["Roll"]);
    }

    void GetVehicleTrajectoryFixResult::setRoll(double roll)
    {
      m_values.AddMember("Roll", parse_json<double>::format(roll, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
