
#include "SetVehicleAntennaOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetVehicleAntennaOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetVehicleAntennaOffset::CmdName = "SetVehicleAntennaOffset";
    const char* const SetVehicleAntennaOffset::Documentation = "Set antenna offset and orientation relative to body frame.\n"
      "The origin of the body frame follows the vehicle trajectory.\n"
      "When the body yaw/pitch/roll are zeros, the body X-axis is pointing north\n"
      "                         Y-axis is pointing east\n"
      "                         Z-axis is pointing down\n"
      "The antenna Yaw is rotating around Z-axis. Pitch is rotating around Y-axis and\n"
      "the Roll is rotating arond the X-axis of the body frame.\n"
      "\n"
      "Name  Type            Description\n"
      "----- --------------- --------------------------------------------\n"
      "X     double          Antenna X offset in the body frame (meter)\n"
      "Y     double          Antenna Y offset in the body frame (meter)\n"
      "Z     double          Antenna Z offset in the body frame (meter)\n"
      "Yaw   double          Antenna Yaw offset in the body frame (rad)\n"
      "Pitch double          Antenna Pitch offset in the body frame (rad)\n"
      "Roll  double          Antenna Roll offset in the body frame (rad)\n"
      "Name  optional string Unique vehicle antenna name";
    const char* const SetVehicleAntennaOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetVehicleAntennaOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetVehicleAntennaOffset);


    SetVehicleAntennaOffset::SetVehicleAntennaOffset()
      : CommandBase(CmdName, TargetId)
    {}

    SetVehicleAntennaOffset::SetVehicleAntennaOffset(double x, double y, double z, double yaw, double pitch, double roll, const Sdx::optional<std::string>& name)
      : CommandBase(CmdName, TargetId)
    {

      setX(x);
      setY(y);
      setZ(z);
      setYaw(yaw);
      setPitch(pitch);
      setRoll(roll);
      setName(name);
    }

    SetVehicleAntennaOffsetPtr SetVehicleAntennaOffset::create(double x, double y, double z, double yaw, double pitch, double roll, const Sdx::optional<std::string>& name)
    {
      return std::make_shared<SetVehicleAntennaOffset>(x, y, z, yaw, pitch, roll, name);
    }

    SetVehicleAntennaOffsetPtr SetVehicleAntennaOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetVehicleAntennaOffset>(ptr);
    }

    bool SetVehicleAntennaOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["X"])
          && parse_json<double>::is_valid(m_values["Y"])
          && parse_json<double>::is_valid(m_values["Z"])
          && parse_json<double>::is_valid(m_values["Yaw"])
          && parse_json<double>::is_valid(m_values["Pitch"])
          && parse_json<double>::is_valid(m_values["Roll"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["Name"])
        ;

    }

    std::string SetVehicleAntennaOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& SetVehicleAntennaOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"X", "Y", "Z", "Yaw", "Pitch", "Roll", "Name"}; 
      return names; 
    }


    int SetVehicleAntennaOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    double SetVehicleAntennaOffset::x() const
    {
      return parse_json<double>::parse(m_values["X"]);
    }

    void SetVehicleAntennaOffset::setX(double x)
    {
      m_values.AddMember("X", parse_json<double>::format(x, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetVehicleAntennaOffset::y() const
    {
      return parse_json<double>::parse(m_values["Y"]);
    }

    void SetVehicleAntennaOffset::setY(double y)
    {
      m_values.AddMember("Y", parse_json<double>::format(y, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetVehicleAntennaOffset::z() const
    {
      return parse_json<double>::parse(m_values["Z"]);
    }

    void SetVehicleAntennaOffset::setZ(double z)
    {
      m_values.AddMember("Z", parse_json<double>::format(z, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetVehicleAntennaOffset::yaw() const
    {
      return parse_json<double>::parse(m_values["Yaw"]);
    }

    void SetVehicleAntennaOffset::setYaw(double yaw)
    {
      m_values.AddMember("Yaw", parse_json<double>::format(yaw, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetVehicleAntennaOffset::pitch() const
    {
      return parse_json<double>::parse(m_values["Pitch"]);
    }

    void SetVehicleAntennaOffset::setPitch(double pitch)
    {
      m_values.AddMember("Pitch", parse_json<double>::format(pitch, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetVehicleAntennaOffset::roll() const
    {
      return parse_json<double>::parse(m_values["Roll"]);
    }

    void SetVehicleAntennaOffset::setRoll(double roll)
    {
      m_values.AddMember("Roll", parse_json<double>::format(roll, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetVehicleAntennaOffset::name() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["Name"]);
    }

    void SetVehicleAntennaOffset::setName(const Sdx::optional<std::string>& name)
    {
      m_values.AddMember("Name", parse_json<Sdx::optional<std::string>>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
