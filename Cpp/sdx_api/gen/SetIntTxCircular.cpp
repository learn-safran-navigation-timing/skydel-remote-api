
#include "gen/SetIntTxCircular.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxCircular
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxCircular::CmdName = "SetIntTxCircular";
    const char* const SetIntTxCircular::Documentation = "Set interference transmitter circular trajectory";

    REGISTER_COMMAND_FACTORY(SetIntTxCircular);


    SetIntTxCircular::SetIntTxCircular()
      : CommandBase(CmdName)
    {}

    SetIntTxCircular::SetIntTxCircular(double lat, double lon, double alt, double radius, double speed, bool clockwise, const std::string& id, const Sdx::optional<double>& originAngle)
      : CommandBase(CmdName)
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

    SetIntTxCircularPtr SetIntTxCircular::create(double lat, double lon, double alt, double radius, double speed, bool clockwise, const std::string& id, const Sdx::optional<double>& originAngle)
    {
      return std::make_shared<SetIntTxCircular>(lat, lon, alt, radius, speed, clockwise, id, originAngle);
    }

    SetIntTxCircularPtr SetIntTxCircular::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIntTxCircular>(ptr);
    }

    bool SetIntTxCircular::isValid() const
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

    std::string SetIntTxCircular::documentation() const { return Documentation; }


    int SetIntTxCircular::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    double SetIntTxCircular::lat() const
    {
      return parse_json<double>::parse(m_values["Lat"]);
    }

    void SetIntTxCircular::setLat(double lat)
    {
      m_values.AddMember("Lat", parse_json<double>::format(lat, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxCircular::lon() const
    {
      return parse_json<double>::parse(m_values["Lon"]);
    }

    void SetIntTxCircular::setLon(double lon)
    {
      m_values.AddMember("Lon", parse_json<double>::format(lon, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxCircular::alt() const
    {
      return parse_json<double>::parse(m_values["Alt"]);
    }

    void SetIntTxCircular::setAlt(double alt)
    {
      m_values.AddMember("Alt", parse_json<double>::format(alt, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxCircular::radius() const
    {
      return parse_json<double>::parse(m_values["Radius"]);
    }

    void SetIntTxCircular::setRadius(double radius)
    {
      m_values.AddMember("Radius", parse_json<double>::format(radius, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxCircular::speed() const
    {
      return parse_json<double>::parse(m_values["Speed"]);
    }

    void SetIntTxCircular::setSpeed(double speed)
    {
      m_values.AddMember("Speed", parse_json<double>::format(speed, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetIntTxCircular::clockwise() const
    {
      return parse_json<bool>::parse(m_values["Clockwise"]);
    }

    void SetIntTxCircular::setClockwise(bool clockwise)
    {
      m_values.AddMember("Clockwise", parse_json<bool>::format(clockwise, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxCircular::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetIntTxCircular::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<double> SetIntTxCircular::originAngle() const
    {
      return parse_json<Sdx::optional<double>>::parse(m_values["OriginAngle"]);
    }

    void SetIntTxCircular::setOriginAngle(const Sdx::optional<double>& originAngle)
    {
      m_values.AddMember("OriginAngle", parse_json<Sdx::optional<double>>::format(originAngle, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
