
#include "GetIntTxCircularResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxCircularResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxCircularResult::CmdName = "GetIntTxCircularResult";
    const char* const GetIntTxCircularResult::Documentation = "Result of GetIntTxCircular.\n"
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
    const char* const GetIntTxCircularResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIntTxCircularResult);


    GetIntTxCircularResult::GetIntTxCircularResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetIntTxCircularResult::GetIntTxCircularResult(double lat, double lon, double alt, double radius, double speed, bool clockwise, const std::string& id, const Sdx::optional<double>& originAngle)
      : CommandResult(CmdName, TargetId)
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

    GetIntTxCircularResult::GetIntTxCircularResult(CommandBasePtr relatedCommand, double lat, double lon, double alt, double radius, double speed, bool clockwise, const std::string& id, const Sdx::optional<double>& originAngle)
      : CommandResult(CmdName, TargetId, relatedCommand)
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


    GetIntTxCircularResultPtr GetIntTxCircularResult::create(double lat, double lon, double alt, double radius, double speed, bool clockwise, const std::string& id, const Sdx::optional<double>& originAngle)
    {
      return std::make_shared<GetIntTxCircularResult>(lat, lon, alt, radius, speed, clockwise, id, originAngle);
    }

    GetIntTxCircularResultPtr GetIntTxCircularResult::create(CommandBasePtr relatedCommand, double lat, double lon, double alt, double radius, double speed, bool clockwise, const std::string& id, const Sdx::optional<double>& originAngle)
    {
      return std::make_shared<GetIntTxCircularResult>(relatedCommand, lat, lon, alt, radius, speed, clockwise, id, originAngle);
    }

    GetIntTxCircularResultPtr GetIntTxCircularResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxCircularResult>(ptr);
    }

    bool GetIntTxCircularResult::isValid() const
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

    std::string GetIntTxCircularResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIntTxCircularResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Lat", "Lon", "Alt", "Radius", "Speed", "Clockwise", "Id", "OriginAngle"}; 
      return names; 
    }


    double GetIntTxCircularResult::lat() const
    {
      return parse_json<double>::parse(m_values["Lat"]);
    }

    void GetIntTxCircularResult::setLat(double lat)
    {
      m_values.AddMember("Lat", parse_json<double>::format(lat, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxCircularResult::lon() const
    {
      return parse_json<double>::parse(m_values["Lon"]);
    }

    void GetIntTxCircularResult::setLon(double lon)
    {
      m_values.AddMember("Lon", parse_json<double>::format(lon, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxCircularResult::alt() const
    {
      return parse_json<double>::parse(m_values["Alt"]);
    }

    void GetIntTxCircularResult::setAlt(double alt)
    {
      m_values.AddMember("Alt", parse_json<double>::format(alt, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxCircularResult::radius() const
    {
      return parse_json<double>::parse(m_values["Radius"]);
    }

    void GetIntTxCircularResult::setRadius(double radius)
    {
      m_values.AddMember("Radius", parse_json<double>::format(radius, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxCircularResult::speed() const
    {
      return parse_json<double>::parse(m_values["Speed"]);
    }

    void GetIntTxCircularResult::setSpeed(double speed)
    {
      m_values.AddMember("Speed", parse_json<double>::format(speed, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetIntTxCircularResult::clockwise() const
    {
      return parse_json<bool>::parse(m_values["Clockwise"]);
    }

    void GetIntTxCircularResult::setClockwise(bool clockwise)
    {
      m_values.AddMember("Clockwise", parse_json<bool>::format(clockwise, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxCircularResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetIntTxCircularResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<double> GetIntTxCircularResult::originAngle() const
    {
      return parse_json<Sdx::optional<double>>::parse(m_values["OriginAngle"]);
    }

    void GetIntTxCircularResult::setOriginAngle(const Sdx::optional<double>& originAngle)
    {
      m_values.AddMember("OriginAngle", parse_json<Sdx::optional<double>>::format(originAngle, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
