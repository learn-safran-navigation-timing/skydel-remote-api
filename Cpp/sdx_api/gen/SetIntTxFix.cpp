
#include "SetIntTxFix.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxFix
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxFix::CmdName = "SetIntTxFix";
    const char* const SetIntTxFix::Documentation = "Set interference transmitter static position and orientation\n"
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
    const char* const SetIntTxFix::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetIntTxFix);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetIntTxFix);


    SetIntTxFix::SetIntTxFix()
      : CommandBase(CmdName, TargetId)
    {}

    SetIntTxFix::SetIntTxFix(double lat, double lon, double alt, double yaw, double pitch, double roll, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setLat(lat);
      setLon(lon);
      setAlt(alt);
      setYaw(yaw);
      setPitch(pitch);
      setRoll(roll);
      setId(id);
    }

    SetIntTxFixPtr SetIntTxFix::create(double lat, double lon, double alt, double yaw, double pitch, double roll, const std::string& id)
    {
      return std::make_shared<SetIntTxFix>(lat, lon, alt, yaw, pitch, roll, id);
    }

    SetIntTxFixPtr SetIntTxFix::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIntTxFix>(ptr);
    }

    bool SetIntTxFix::isValid() const
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

    std::string SetIntTxFix::documentation() const { return Documentation; }

    const std::vector<std::string>& SetIntTxFix::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Lat", "Lon", "Alt", "Yaw", "Pitch", "Roll", "Id"}; 
      return names; 
    }


    int SetIntTxFix::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    double SetIntTxFix::lat() const
    {
      return parse_json<double>::parse(m_values["Lat"]);
    }

    void SetIntTxFix::setLat(double lat)
    {
      m_values.AddMember("Lat", parse_json<double>::format(lat, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxFix::lon() const
    {
      return parse_json<double>::parse(m_values["Lon"]);
    }

    void SetIntTxFix::setLon(double lon)
    {
      m_values.AddMember("Lon", parse_json<double>::format(lon, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxFix::alt() const
    {
      return parse_json<double>::parse(m_values["Alt"]);
    }

    void SetIntTxFix::setAlt(double alt)
    {
      m_values.AddMember("Alt", parse_json<double>::format(alt, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxFix::yaw() const
    {
      return parse_json<double>::parse(m_values["Yaw"]);
    }

    void SetIntTxFix::setYaw(double yaw)
    {
      m_values.AddMember("Yaw", parse_json<double>::format(yaw, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxFix::pitch() const
    {
      return parse_json<double>::parse(m_values["Pitch"]);
    }

    void SetIntTxFix::setPitch(double pitch)
    {
      m_values.AddMember("Pitch", parse_json<double>::format(pitch, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxFix::roll() const
    {
      return parse_json<double>::parse(m_values["Roll"]);
    }

    void SetIntTxFix::setRoll(double roll)
    {
      m_values.AddMember("Roll", parse_json<double>::format(roll, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxFix::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetIntTxFix::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
