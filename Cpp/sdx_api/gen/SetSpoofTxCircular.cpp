
#include "SetSpoofTxCircular.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSpoofTxCircular
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSpoofTxCircular::CmdName = "SetSpoofTxCircular";
    const char* const SetSpoofTxCircular::Documentation = "Set spoofer transmitter circular trajectory\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- --------------------------------\n"
      "Lat         double          Center latitude (rad)\n"
      "Lon         double          Center longitude (rad)\n"
      "Alt         double          Altitude (m)\n"
      "Radius      double          Radius (m)\n"
      "Speed       double          Speed (m/s)\n"
      "Clockwise   bool            If true, vehicle turns clockwise\n"
      "Id          string          Transmitter unique identifier.\n"
      "OriginAngle optional double Vehicle angle at elapsed time 0.";
    const char* const SetSpoofTxCircular::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSpoofTxCircular);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSpoofTxCircular);


    SetSpoofTxCircular::SetSpoofTxCircular()
      : CommandBase(CmdName, TargetId)
    {}

    SetSpoofTxCircular::SetSpoofTxCircular(double lat, double lon, double alt, double radius, double speed, bool clockwise, const std::string& id, const Sdx::optional<double>& originAngle)
      : CommandBase(CmdName, TargetId)
    {

      setLat(lat);
      setLon(lon);
      setAlt(alt);
      setRadius(radius);
      setSpeed(speed);
      setClockwise(clockwise);
      setId(id);
      setOriginAngle(originAngle);
    }

    SetSpoofTxCircularPtr SetSpoofTxCircular::create(double lat, double lon, double alt, double radius, double speed, bool clockwise, const std::string& id, const Sdx::optional<double>& originAngle)
    {
      return std::make_shared<SetSpoofTxCircular>(lat, lon, alt, radius, speed, clockwise, id, originAngle);
    }

    SetSpoofTxCircularPtr SetSpoofTxCircular::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSpoofTxCircular>(ptr);
    }

    bool SetSpoofTxCircular::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["Lat"])
          && parse_json<double>::is_valid(m_values["Lon"])
          && parse_json<double>::is_valid(m_values["Alt"])
          && parse_json<double>::is_valid(m_values["Radius"])
          && parse_json<double>::is_valid(m_values["Speed"])
          && parse_json<bool>::is_valid(m_values["Clockwise"])
          && parse_json<std::string>::is_valid(m_values["Id"])
          && parse_json<Sdx::optional<double>>::is_valid(m_values["OriginAngle"])
        ;

    }

    std::string SetSpoofTxCircular::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSpoofTxCircular::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Lat", "Lon", "Alt", "Radius", "Speed", "Clockwise", "Id", "OriginAngle"}; 
      return names; 
    }


    int SetSpoofTxCircular::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    double SetSpoofTxCircular::lat() const
    {
      return parse_json<double>::parse(m_values["Lat"]);
    }

    void SetSpoofTxCircular::setLat(double lat)
    {
      m_values.AddMember("Lat", parse_json<double>::format(lat, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSpoofTxCircular::lon() const
    {
      return parse_json<double>::parse(m_values["Lon"]);
    }

    void SetSpoofTxCircular::setLon(double lon)
    {
      m_values.AddMember("Lon", parse_json<double>::format(lon, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSpoofTxCircular::alt() const
    {
      return parse_json<double>::parse(m_values["Alt"]);
    }

    void SetSpoofTxCircular::setAlt(double alt)
    {
      m_values.AddMember("Alt", parse_json<double>::format(alt, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSpoofTxCircular::radius() const
    {
      return parse_json<double>::parse(m_values["Radius"]);
    }

    void SetSpoofTxCircular::setRadius(double radius)
    {
      m_values.AddMember("Radius", parse_json<double>::format(radius, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSpoofTxCircular::speed() const
    {
      return parse_json<double>::parse(m_values["Speed"]);
    }

    void SetSpoofTxCircular::setSpeed(double speed)
    {
      m_values.AddMember("Speed", parse_json<double>::format(speed, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetSpoofTxCircular::clockwise() const
    {
      return parse_json<bool>::parse(m_values["Clockwise"]);
    }

    void SetSpoofTxCircular::setClockwise(bool clockwise)
    {
      m_values.AddMember("Clockwise", parse_json<bool>::format(clockwise, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetSpoofTxCircular::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetSpoofTxCircular::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<double> SetSpoofTxCircular::originAngle() const
    {
      return parse_json<Sdx::optional<double>>::parse(m_values["OriginAngle"]);
    }

    void SetSpoofTxCircular::setOriginAngle(const Sdx::optional<double>& originAngle)
    {
      m_values.AddMember("OriginAngle", parse_json<Sdx::optional<double>>::format(originAngle, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
