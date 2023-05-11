
#include "gen/SetSpoofTxFix.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSpoofTxFix
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSpoofTxFix::CmdName = "SetSpoofTxFix";
    const char* const SetSpoofTxFix::Documentation = "Set spoofer transmitter static position and orientation";

    REGISTER_COMMAND_FACTORY(SetSpoofTxFix);


    SetSpoofTxFix::SetSpoofTxFix()
      : CommandBase(CmdName)
    {}

    SetSpoofTxFix::SetSpoofTxFix(double lat, double lon, double alt, double yaw, double pitch, double roll, const std::string& id)
      : CommandBase(CmdName)
    {

      setLat(lat);
      setLon(lon);
      setAlt(alt);
      setYaw(yaw);
      setPitch(pitch);
      setRoll(roll);
      setId(id);
    }

    SetSpoofTxFixPtr SetSpoofTxFix::create(double lat, double lon, double alt, double yaw, double pitch, double roll, const std::string& id)
    {
      return std::make_shared<SetSpoofTxFix>(lat, lon, alt, yaw, pitch, roll, id);
    }

    SetSpoofTxFixPtr SetSpoofTxFix::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSpoofTxFix>(ptr);
    }

    bool SetSpoofTxFix::isValid() const
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

    std::string SetSpoofTxFix::documentation() const { return Documentation; }


    int SetSpoofTxFix::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    double SetSpoofTxFix::lat() const
    {
      return parse_json<double>::parse(m_values["Lat"]);
    }

    void SetSpoofTxFix::setLat(double lat)
    {
      m_values.AddMember("Lat", parse_json<double>::format(lat, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSpoofTxFix::lon() const
    {
      return parse_json<double>::parse(m_values["Lon"]);
    }

    void SetSpoofTxFix::setLon(double lon)
    {
      m_values.AddMember("Lon", parse_json<double>::format(lon, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSpoofTxFix::alt() const
    {
      return parse_json<double>::parse(m_values["Alt"]);
    }

    void SetSpoofTxFix::setAlt(double alt)
    {
      m_values.AddMember("Alt", parse_json<double>::format(alt, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSpoofTxFix::yaw() const
    {
      return parse_json<double>::parse(m_values["Yaw"]);
    }

    void SetSpoofTxFix::setYaw(double yaw)
    {
      m_values.AddMember("Yaw", parse_json<double>::format(yaw, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSpoofTxFix::pitch() const
    {
      return parse_json<double>::parse(m_values["Pitch"]);
    }

    void SetSpoofTxFix::setPitch(double pitch)
    {
      m_values.AddMember("Pitch", parse_json<double>::format(pitch, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSpoofTxFix::roll() const
    {
      return parse_json<double>::parse(m_values["Roll"]);
    }

    void SetSpoofTxFix::setRoll(double roll)
    {
      m_values.AddMember("Roll", parse_json<double>::format(roll, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetSpoofTxFix::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetSpoofTxFix::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
