
#include "SetIntTxAntennaOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxAntennaOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxAntennaOffset::CmdName = "SetIntTxAntennaOffset";
    const char* const SetIntTxAntennaOffset::Documentation = "Set antenna offset and orientation relative to body frame.\n"
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
    const char* const SetIntTxAntennaOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetIntTxAntennaOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetIntTxAntennaOffset);


    SetIntTxAntennaOffset::SetIntTxAntennaOffset()
      : CommandBase(CmdName, TargetId)
    {}

    SetIntTxAntennaOffset::SetIntTxAntennaOffset(double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
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

    SetIntTxAntennaOffsetPtr SetIntTxAntennaOffset::create(double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
    {
      return std::make_shared<SetIntTxAntennaOffset>(x, y, z, yaw, pitch, roll, id);
    }

    SetIntTxAntennaOffsetPtr SetIntTxAntennaOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIntTxAntennaOffset>(ptr);
    }

    bool SetIntTxAntennaOffset::isValid() const
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

    std::string SetIntTxAntennaOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& SetIntTxAntennaOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"X", "Y", "Z", "Yaw", "Pitch", "Roll", "Id"}; 
      return names; 
    }


    int SetIntTxAntennaOffset::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    double SetIntTxAntennaOffset::x() const
    {
      return parse_json<double>::parse(m_values["X"]);
    }

    void SetIntTxAntennaOffset::setX(double x)
    {
      m_values.AddMember("X", parse_json<double>::format(x, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxAntennaOffset::y() const
    {
      return parse_json<double>::parse(m_values["Y"]);
    }

    void SetIntTxAntennaOffset::setY(double y)
    {
      m_values.AddMember("Y", parse_json<double>::format(y, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxAntennaOffset::z() const
    {
      return parse_json<double>::parse(m_values["Z"]);
    }

    void SetIntTxAntennaOffset::setZ(double z)
    {
      m_values.AddMember("Z", parse_json<double>::format(z, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxAntennaOffset::yaw() const
    {
      return parse_json<double>::parse(m_values["Yaw"]);
    }

    void SetIntTxAntennaOffset::setYaw(double yaw)
    {
      m_values.AddMember("Yaw", parse_json<double>::format(yaw, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxAntennaOffset::pitch() const
    {
      return parse_json<double>::parse(m_values["Pitch"]);
    }

    void SetIntTxAntennaOffset::setPitch(double pitch)
    {
      m_values.AddMember("Pitch", parse_json<double>::format(pitch, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxAntennaOffset::roll() const
    {
      return parse_json<double>::parse(m_values["Roll"]);
    }

    void SetIntTxAntennaOffset::setRoll(double roll)
    {
      m_values.AddMember("Roll", parse_json<double>::format(roll, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxAntennaOffset::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetIntTxAntennaOffset::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
