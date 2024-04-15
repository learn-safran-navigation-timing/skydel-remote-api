
#include "SetWFAntennaOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetWFAntennaOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetWFAntennaOffset::CmdName = "SetWFAntennaOffset";
    const char* const SetWFAntennaOffset::Documentation = "Set WF antenna offset and orientation relative to body frame.\n"
      "The origin of the body frame follows the vehicle trajectory.\n"
      "When the body yaw/pitch/roll are zeros, the body X-axis is pointing north\n"
      "                         Y-axis is pointing east\n"
      "                         Z-axis is pointing down\n"
      "The antenna Yaw is rotating around Z-axis. Pitch is rotating around Y-axis and\n"
      "the Roll is rotating arond the X-axis of the body frame.\n"
      "\n"
      "Name  Type   Description\n"
      "----- ------ -----------------------------------------------\n"
      "X     double WF Antenna X offset in the body frame (meter)\n"
      "Y     double WF Antenna Y offset in the body frame (meter)\n"
      "Z     double WF Antenna Z offset in the body frame (meter)\n"
      "Yaw   double WF Antenna Yaw offset in the body frame (rad)\n"
      "Pitch double WF Antenna Pitch offset in the body frame (rad)\n"
      "Roll  double WF Antenna Roll offset in the body frame (rad)";
    const char* const SetWFAntennaOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetWFAntennaOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetWFAntennaOffset);


    SetWFAntennaOffset::SetWFAntennaOffset()
      : CommandBase(CmdName, TargetId)
    {}

    SetWFAntennaOffset::SetWFAntennaOffset(double x, double y, double z, double yaw, double pitch, double roll)
      : CommandBase(CmdName, TargetId)
    {

      setX(x);
      setY(y);
      setZ(z);
      setYaw(yaw);
      setPitch(pitch);
      setRoll(roll);
    }

    SetWFAntennaOffsetPtr SetWFAntennaOffset::create(double x, double y, double z, double yaw, double pitch, double roll)
    {
      return std::make_shared<SetWFAntennaOffset>(x, y, z, yaw, pitch, roll);
    }

    SetWFAntennaOffsetPtr SetWFAntennaOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetWFAntennaOffset>(ptr);
    }

    bool SetWFAntennaOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["X"])
          && parse_json<double>::is_valid(m_values["Y"])
          && parse_json<double>::is_valid(m_values["Z"])
          && parse_json<double>::is_valid(m_values["Yaw"])
          && parse_json<double>::is_valid(m_values["Pitch"])
          && parse_json<double>::is_valid(m_values["Roll"])
        ;

    }

    std::string SetWFAntennaOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& SetWFAntennaOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"X", "Y", "Z", "Yaw", "Pitch", "Roll"}; 
      return names; 
    }


    int SetWFAntennaOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    double SetWFAntennaOffset::x() const
    {
      return parse_json<double>::parse(m_values["X"]);
    }

    void SetWFAntennaOffset::setX(double x)
    {
      m_values.AddMember("X", parse_json<double>::format(x, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetWFAntennaOffset::y() const
    {
      return parse_json<double>::parse(m_values["Y"]);
    }

    void SetWFAntennaOffset::setY(double y)
    {
      m_values.AddMember("Y", parse_json<double>::format(y, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetWFAntennaOffset::z() const
    {
      return parse_json<double>::parse(m_values["Z"]);
    }

    void SetWFAntennaOffset::setZ(double z)
    {
      m_values.AddMember("Z", parse_json<double>::format(z, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetWFAntennaOffset::yaw() const
    {
      return parse_json<double>::parse(m_values["Yaw"]);
    }

    void SetWFAntennaOffset::setYaw(double yaw)
    {
      m_values.AddMember("Yaw", parse_json<double>::format(yaw, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetWFAntennaOffset::pitch() const
    {
      return parse_json<double>::parse(m_values["Pitch"]);
    }

    void SetWFAntennaOffset::setPitch(double pitch)
    {
      m_values.AddMember("Pitch", parse_json<double>::format(pitch, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetWFAntennaOffset::roll() const
    {
      return parse_json<double>::parse(m_values["Roll"]);
    }

    void SetWFAntennaOffset::setRoll(double roll)
    {
      m_values.AddMember("Roll", parse_json<double>::format(roll, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
