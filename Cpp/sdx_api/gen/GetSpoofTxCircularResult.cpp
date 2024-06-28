
#include "GetSpoofTxCircularResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSpoofTxCircularResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSpoofTxCircularResult::CmdName = "GetSpoofTxCircularResult";
    const char* const GetSpoofTxCircularResult::Documentation = "Result of GetSpoofTxCircular.\n"
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
    const char* const GetSpoofTxCircularResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSpoofTxCircularResult);


    GetSpoofTxCircularResult::GetSpoofTxCircularResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetSpoofTxCircularResult::GetSpoofTxCircularResult(double lat, double lon, double alt, double radius, double speed, bool clockwise, const std::string& id, const std::optional<double>& originAngle)
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

    GetSpoofTxCircularResult::GetSpoofTxCircularResult(CommandBasePtr relatedCommand, double lat, double lon, double alt, double radius, double speed, bool clockwise, const std::string& id, const std::optional<double>& originAngle)
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


    GetSpoofTxCircularResultPtr GetSpoofTxCircularResult::create(double lat, double lon, double alt, double radius, double speed, bool clockwise, const std::string& id, const std::optional<double>& originAngle)
    {
      return std::make_shared<GetSpoofTxCircularResult>(lat, lon, alt, radius, speed, clockwise, id, originAngle);
    }

    GetSpoofTxCircularResultPtr GetSpoofTxCircularResult::create(CommandBasePtr relatedCommand, double lat, double lon, double alt, double radius, double speed, bool clockwise, const std::string& id, const std::optional<double>& originAngle)
    {
      return std::make_shared<GetSpoofTxCircularResult>(relatedCommand, lat, lon, alt, radius, speed, clockwise, id, originAngle);
    }

    GetSpoofTxCircularResultPtr GetSpoofTxCircularResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSpoofTxCircularResult>(ptr);
    }

    bool GetSpoofTxCircularResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["Lat"])
          && parse_json<double>::is_valid(m_values["Lon"])
          && parse_json<double>::is_valid(m_values["Alt"])
          && parse_json<double>::is_valid(m_values["Radius"])
          && parse_json<double>::is_valid(m_values["Speed"])
          && parse_json<bool>::is_valid(m_values["Clockwise"])
          && parse_json<std::string>::is_valid(m_values["Id"])
          && parse_json<std::optional<double>>::is_valid(m_values["OriginAngle"])
        ;

    }

    std::string GetSpoofTxCircularResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSpoofTxCircularResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Lat", "Lon", "Alt", "Radius", "Speed", "Clockwise", "Id", "OriginAngle"}; 
      return names; 
    }


    double GetSpoofTxCircularResult::lat() const
    {
      return parse_json<double>::parse(m_values["Lat"]);
    }

    void GetSpoofTxCircularResult::setLat(double lat)
    {
      m_values.AddMember("Lat", parse_json<double>::format(lat, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSpoofTxCircularResult::lon() const
    {
      return parse_json<double>::parse(m_values["Lon"]);
    }

    void GetSpoofTxCircularResult::setLon(double lon)
    {
      m_values.AddMember("Lon", parse_json<double>::format(lon, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSpoofTxCircularResult::alt() const
    {
      return parse_json<double>::parse(m_values["Alt"]);
    }

    void GetSpoofTxCircularResult::setAlt(double alt)
    {
      m_values.AddMember("Alt", parse_json<double>::format(alt, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSpoofTxCircularResult::radius() const
    {
      return parse_json<double>::parse(m_values["Radius"]);
    }

    void GetSpoofTxCircularResult::setRadius(double radius)
    {
      m_values.AddMember("Radius", parse_json<double>::format(radius, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSpoofTxCircularResult::speed() const
    {
      return parse_json<double>::parse(m_values["Speed"]);
    }

    void GetSpoofTxCircularResult::setSpeed(double speed)
    {
      m_values.AddMember("Speed", parse_json<double>::format(speed, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetSpoofTxCircularResult::clockwise() const
    {
      return parse_json<bool>::parse(m_values["Clockwise"]);
    }

    void GetSpoofTxCircularResult::setClockwise(bool clockwise)
    {
      m_values.AddMember("Clockwise", parse_json<bool>::format(clockwise, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSpoofTxCircularResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetSpoofTxCircularResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<double> GetSpoofTxCircularResult::originAngle() const
    {
      return parse_json<std::optional<double>>::parse(m_values["OriginAngle"]);
    }

    void GetSpoofTxCircularResult::setOriginAngle(const std::optional<double>& originAngle)
    {
      m_values.AddMember("OriginAngle", parse_json<std::optional<double>>::format(originAngle, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
