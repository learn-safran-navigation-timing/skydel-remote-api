
#include "GetSpoofTxFixResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSpoofTxFixResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSpoofTxFixResult::CmdName = "GetSpoofTxFixResult";
    const char* const GetSpoofTxFixResult::Documentation = "Result of GetSpoofTxFix.\n"
      "\n"
      "Name  Type   Description\n"
      "----- ------ ------------------------------\n"
      "Lat   double Latitude (rad)\n"
      "Lon   double Longitude (rad)\n"
      "Alt   double Altitude (m)\n"
      "Yaw   double Yaw (rad)\n"
      "Pitch double Pitch (rad)\n"
      "Roll  double Roll (rad)\n"
      "Id    string Transmitter unique identifier.";
    const char* const GetSpoofTxFixResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSpoofTxFixResult);


    GetSpoofTxFixResult::GetSpoofTxFixResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetSpoofTxFixResult::GetSpoofTxFixResult(double lat, double lon, double alt, double yaw, double pitch, double roll, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setLat(lat);
      setLon(lon);
      setAlt(alt);
      setYaw(yaw);
      setPitch(pitch);
      setRoll(roll);
      setId(id);
    }

    GetSpoofTxFixResult::GetSpoofTxFixResult(CommandBasePtr relatedCommand, double lat, double lon, double alt, double yaw, double pitch, double roll, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setLat(lat);
      setLon(lon);
      setAlt(alt);
      setYaw(yaw);
      setPitch(pitch);
      setRoll(roll);
      setId(id);
    }


    GetSpoofTxFixResultPtr GetSpoofTxFixResult::create(double lat, double lon, double alt, double yaw, double pitch, double roll, const std::string& id)
    {
      return std::make_shared<GetSpoofTxFixResult>(lat, lon, alt, yaw, pitch, roll, id);
    }

    GetSpoofTxFixResultPtr GetSpoofTxFixResult::create(CommandBasePtr relatedCommand, double lat, double lon, double alt, double yaw, double pitch, double roll, const std::string& id)
    {
      return std::make_shared<GetSpoofTxFixResult>(relatedCommand, lat, lon, alt, yaw, pitch, roll, id);
    }

    GetSpoofTxFixResultPtr GetSpoofTxFixResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSpoofTxFixResult>(ptr);
    }

    bool GetSpoofTxFixResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["Lat"])
          && parse_json<double>::is_valid(m_values["Lon"])
          && parse_json<double>::is_valid(m_values["Alt"])
          && parse_json<double>::is_valid(m_values["Yaw"])
          && parse_json<double>::is_valid(m_values["Pitch"])
          && parse_json<double>::is_valid(m_values["Roll"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetSpoofTxFixResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSpoofTxFixResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Lat", "Lon", "Alt", "Yaw", "Pitch", "Roll", "Id"}; 
      return names; 
    }


    double GetSpoofTxFixResult::lat() const
    {
      return parse_json<double>::parse(m_values["Lat"]);
    }

    void GetSpoofTxFixResult::setLat(double lat)
    {
      m_values.AddMember("Lat", parse_json<double>::format(lat, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSpoofTxFixResult::lon() const
    {
      return parse_json<double>::parse(m_values["Lon"]);
    }

    void GetSpoofTxFixResult::setLon(double lon)
    {
      m_values.AddMember("Lon", parse_json<double>::format(lon, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSpoofTxFixResult::alt() const
    {
      return parse_json<double>::parse(m_values["Alt"]);
    }

    void GetSpoofTxFixResult::setAlt(double alt)
    {
      m_values.AddMember("Alt", parse_json<double>::format(alt, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSpoofTxFixResult::yaw() const
    {
      return parse_json<double>::parse(m_values["Yaw"]);
    }

    void GetSpoofTxFixResult::setYaw(double yaw)
    {
      m_values.AddMember("Yaw", parse_json<double>::format(yaw, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSpoofTxFixResult::pitch() const
    {
      return parse_json<double>::parse(m_values["Pitch"]);
    }

    void GetSpoofTxFixResult::setPitch(double pitch)
    {
      m_values.AddMember("Pitch", parse_json<double>::format(pitch, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSpoofTxFixResult::roll() const
    {
      return parse_json<double>::parse(m_values["Roll"]);
    }

    void GetSpoofTxFixResult::setRoll(double roll)
    {
      m_values.AddMember("Roll", parse_json<double>::format(roll, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSpoofTxFixResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetSpoofTxFixResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
