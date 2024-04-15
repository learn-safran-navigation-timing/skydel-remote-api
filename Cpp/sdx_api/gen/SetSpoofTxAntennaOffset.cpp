
#include "SetSpoofTxAntennaOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSpoofTxAntennaOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSpoofTxAntennaOffset::CmdName = "SetSpoofTxAntennaOffset";
    const char* const SetSpoofTxAntennaOffset::Documentation = "Set antenna offset and orientation relative to body frame.\n"
      "The origin of the body frame follows the transmitter trajectory.\n"
      "When the body yaw/pitch/roll are zeros, the body X-axis is pointing north\n"
      "                         Y-axis is pointing east\n"
      "                         Z-axis is pointing down\n"
      "The antenna Yaw is rotating around Z-axis. Pitch is rotating around Y-axis and\n"
      "the Roll is rotating arond the X-axis of the body frame.\n"
      "\n"
      "Name  Type   Description\n"
      "----- ------ --------------------------------------\n"
      "X     double Antenna X offset in the body frame\n"
      "Y     double Antenna Y offset in the body frame\n"
      "Z     double Antenna Z offset in the body frame\n"
      "Yaw   double Antenna Yaw offset in the body frame\n"
      "Pitch double Antenna Pitch offset in the body frame\n"
      "Roll  double Antenna Roll offset in the body frame\n"
      "Id    string Transmitter unique identifier.";
    const char* const SetSpoofTxAntennaOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSpoofTxAntennaOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSpoofTxAntennaOffset);


    SetSpoofTxAntennaOffset::SetSpoofTxAntennaOffset()
      : CommandBase(CmdName, TargetId)
    {}

    SetSpoofTxAntennaOffset::SetSpoofTxAntennaOffset(double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setX(x);
      setY(y);
      setZ(z);
      setYaw(yaw);
      setPitch(pitch);
      setRoll(roll);
      setId(id);
    }

    SetSpoofTxAntennaOffsetPtr SetSpoofTxAntennaOffset::create(double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
    {
      return std::make_shared<SetSpoofTxAntennaOffset>(x, y, z, yaw, pitch, roll, id);
    }

    SetSpoofTxAntennaOffsetPtr SetSpoofTxAntennaOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSpoofTxAntennaOffset>(ptr);
    }

    bool SetSpoofTxAntennaOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["X"])
          && parse_json<double>::is_valid(m_values["Y"])
          && parse_json<double>::is_valid(m_values["Z"])
          && parse_json<double>::is_valid(m_values["Yaw"])
          && parse_json<double>::is_valid(m_values["Pitch"])
          && parse_json<double>::is_valid(m_values["Roll"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetSpoofTxAntennaOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSpoofTxAntennaOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"X", "Y", "Z", "Yaw", "Pitch", "Roll", "Id"}; 
      return names; 
    }


    int SetSpoofTxAntennaOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    double SetSpoofTxAntennaOffset::x() const
    {
      return parse_json<double>::parse(m_values["X"]);
    }

    void SetSpoofTxAntennaOffset::setX(double x)
    {
      m_values.AddMember("X", parse_json<double>::format(x, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSpoofTxAntennaOffset::y() const
    {
      return parse_json<double>::parse(m_values["Y"]);
    }

    void SetSpoofTxAntennaOffset::setY(double y)
    {
      m_values.AddMember("Y", parse_json<double>::format(y, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSpoofTxAntennaOffset::z() const
    {
      return parse_json<double>::parse(m_values["Z"]);
    }

    void SetSpoofTxAntennaOffset::setZ(double z)
    {
      m_values.AddMember("Z", parse_json<double>::format(z, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSpoofTxAntennaOffset::yaw() const
    {
      return parse_json<double>::parse(m_values["Yaw"]);
    }

    void SetSpoofTxAntennaOffset::setYaw(double yaw)
    {
      m_values.AddMember("Yaw", parse_json<double>::format(yaw, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSpoofTxAntennaOffset::pitch() const
    {
      return parse_json<double>::parse(m_values["Pitch"]);
    }

    void SetSpoofTxAntennaOffset::setPitch(double pitch)
    {
      m_values.AddMember("Pitch", parse_json<double>::format(pitch, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSpoofTxAntennaOffset::roll() const
    {
      return parse_json<double>::parse(m_values["Roll"]);
    }

    void SetSpoofTxAntennaOffset::setRoll(double roll)
    {
      m_values.AddMember("Roll", parse_json<double>::format(roll, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetSpoofTxAntennaOffset::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetSpoofTxAntennaOffset::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
