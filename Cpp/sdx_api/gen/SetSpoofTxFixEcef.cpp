
#include "gen/SetSpoofTxFixEcef.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSpoofTxFixEcef
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSpoofTxFixEcef::CmdName = "SetSpoofTxFixEcef";
    const char* const SetSpoofTxFixEcef::Documentation = "Set spoofer transmitter static position and orientation";

    REGISTER_COMMAND_FACTORY(SetSpoofTxFixEcef);


    SetSpoofTxFixEcef::SetSpoofTxFixEcef()
      : CommandBase(CmdName)
    {}

    SetSpoofTxFixEcef::SetSpoofTxFixEcef(double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
      : CommandBase(CmdName)
    {

      setX(x);
      setY(y);
      setZ(z);
      setYaw(yaw);
      setPitch(pitch);
      setRoll(roll);
      setId(id);
    }

    SetSpoofTxFixEcefPtr SetSpoofTxFixEcef::create(double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
    {
      return std::make_shared<SetSpoofTxFixEcef>(x, y, z, yaw, pitch, roll, id);
    }

    SetSpoofTxFixEcefPtr SetSpoofTxFixEcef::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSpoofTxFixEcef>(ptr);
    }

    bool SetSpoofTxFixEcef::isValid() const
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

    std::string SetSpoofTxFixEcef::documentation() const { return Documentation; }


    int SetSpoofTxFixEcef::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    double SetSpoofTxFixEcef::x() const
    {
      return parse_json<double>::parse(m_values["X"]);
    }

    void SetSpoofTxFixEcef::setX(double x)
    {
      m_values.AddMember("X", parse_json<double>::format(x, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSpoofTxFixEcef::y() const
    {
      return parse_json<double>::parse(m_values["Y"]);
    }

    void SetSpoofTxFixEcef::setY(double y)
    {
      m_values.AddMember("Y", parse_json<double>::format(y, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSpoofTxFixEcef::z() const
    {
      return parse_json<double>::parse(m_values["Z"]);
    }

    void SetSpoofTxFixEcef::setZ(double z)
    {
      m_values.AddMember("Z", parse_json<double>::format(z, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSpoofTxFixEcef::yaw() const
    {
      return parse_json<double>::parse(m_values["Yaw"]);
    }

    void SetSpoofTxFixEcef::setYaw(double yaw)
    {
      m_values.AddMember("Yaw", parse_json<double>::format(yaw, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSpoofTxFixEcef::pitch() const
    {
      return parse_json<double>::parse(m_values["Pitch"]);
    }

    void SetSpoofTxFixEcef::setPitch(double pitch)
    {
      m_values.AddMember("Pitch", parse_json<double>::format(pitch, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSpoofTxFixEcef::roll() const
    {
      return parse_json<double>::parse(m_values["Roll"]);
    }

    void SetSpoofTxFixEcef::setRoll(double roll)
    {
      m_values.AddMember("Roll", parse_json<double>::format(roll, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetSpoofTxFixEcef::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetSpoofTxFixEcef::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
