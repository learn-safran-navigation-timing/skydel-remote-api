
#include "gen/SetVehicleTrajectoryFixEcef.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetVehicleTrajectoryFixEcef
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetVehicleTrajectoryFixEcef::CmdName = "SetVehicleTrajectoryFixEcef";
    const char* const SetVehicleTrajectoryFixEcef::Documentation = "Set vehicle static position and orientation";

    REGISTER_COMMAND_FACTORY(SetVehicleTrajectoryFixEcef);


    SetVehicleTrajectoryFixEcef::SetVehicleTrajectoryFixEcef()
      : CommandBase(CmdName)
    {}

    SetVehicleTrajectoryFixEcef::SetVehicleTrajectoryFixEcef(const std::string& type, double x, double y, double z, double yaw, double pitch, double roll)
      : CommandBase(CmdName)
    {

      setType(type);
      setX(x);
      setY(y);
      setZ(z);
      setYaw(yaw);
      setPitch(pitch);
      setRoll(roll);
    }

    SetVehicleTrajectoryFixEcefPtr SetVehicleTrajectoryFixEcef::create(const std::string& type, double x, double y, double z, double yaw, double pitch, double roll)
    {
      return std::make_shared<SetVehicleTrajectoryFixEcef>(type, x, y, z, yaw, pitch, roll);
    }

    SetVehicleTrajectoryFixEcefPtr SetVehicleTrajectoryFixEcef::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetVehicleTrajectoryFixEcef>(ptr);
    }

    bool SetVehicleTrajectoryFixEcef::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Type"])
          && parse_json<double>::is_valid(m_values["X"])
          && parse_json<double>::is_valid(m_values["Y"])
          && parse_json<double>::is_valid(m_values["Z"])
          && parse_json<double>::is_valid(m_values["Yaw"])
          && parse_json<double>::is_valid(m_values["Pitch"])
          && parse_json<double>::is_valid(m_values["Roll"])
        ;

    }

    std::string SetVehicleTrajectoryFixEcef::documentation() const { return Documentation; }


    int SetVehicleTrajectoryFixEcef::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetVehicleTrajectoryFixEcef::type() const
    {
      return parse_json<std::string>::parse(m_values["Type"]);
    }

    void SetVehicleTrajectoryFixEcef::setType(const std::string& type)
    {
      m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetVehicleTrajectoryFixEcef::x() const
    {
      return parse_json<double>::parse(m_values["X"]);
    }

    void SetVehicleTrajectoryFixEcef::setX(double x)
    {
      m_values.AddMember("X", parse_json<double>::format(x, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetVehicleTrajectoryFixEcef::y() const
    {
      return parse_json<double>::parse(m_values["Y"]);
    }

    void SetVehicleTrajectoryFixEcef::setY(double y)
    {
      m_values.AddMember("Y", parse_json<double>::format(y, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetVehicleTrajectoryFixEcef::z() const
    {
      return parse_json<double>::parse(m_values["Z"]);
    }

    void SetVehicleTrajectoryFixEcef::setZ(double z)
    {
      m_values.AddMember("Z", parse_json<double>::format(z, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetVehicleTrajectoryFixEcef::yaw() const
    {
      return parse_json<double>::parse(m_values["Yaw"]);
    }

    void SetVehicleTrajectoryFixEcef::setYaw(double yaw)
    {
      m_values.AddMember("Yaw", parse_json<double>::format(yaw, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetVehicleTrajectoryFixEcef::pitch() const
    {
      return parse_json<double>::parse(m_values["Pitch"]);
    }

    void SetVehicleTrajectoryFixEcef::setPitch(double pitch)
    {
      m_values.AddMember("Pitch", parse_json<double>::format(pitch, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetVehicleTrajectoryFixEcef::roll() const
    {
      return parse_json<double>::parse(m_values["Roll"]);
    }

    void SetVehicleTrajectoryFixEcef::setRoll(double roll)
    {
      m_values.AddMember("Roll", parse_json<double>::format(roll, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
