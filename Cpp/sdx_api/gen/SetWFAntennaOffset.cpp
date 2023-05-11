
#include "gen/SetWFAntennaOffset.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetWFAntennaOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetWFAntennaOffset::CmdName = "SetWFAntennaOffset";
    const char* const SetWFAntennaOffset::Documentation = "Set WF antenna offset and orientation relative to body frame.\nThe origin of the body frame follows the vehicle trajectory.\nWhen the body yaw/pitch/roll are zeros, the body X-axis is pointing north\n                         Y-axis is pointing east\n                         Z-axis is pointing down\nThe antenna Yaw is rotating around Z-axis. Pitch is rotating around Y-axis and\nthe Roll is rotating arond the X-axis of the body frame.";

    REGISTER_COMMAND_FACTORY(SetWFAntennaOffset);


    SetWFAntennaOffset::SetWFAntennaOffset()
      : CommandBase(CmdName)
    {}

    SetWFAntennaOffset::SetWFAntennaOffset(double x, double y, double z, double yaw, double pitch, double roll)
      : CommandBase(CmdName)
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
