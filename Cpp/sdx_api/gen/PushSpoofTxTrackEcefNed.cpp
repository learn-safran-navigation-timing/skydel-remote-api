
#include "PushSpoofTxTrackEcefNed.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of PushSpoofTxTrackEcefNed
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const PushSpoofTxTrackEcefNed::CmdName = "PushSpoofTxTrackEcefNed";
    const char* const PushSpoofTxTrackEcefNed::Documentation = "Push a spoofer transmitter track ECEF and NED attitude node. Must be called after BeginSpoofTxTrackDefinition and before EndSpoofTxTrackDefinition.\n"
      "\n"
      "Name  Type   Description\n"
      "----- ------ ---------------------------------------\n"
      "Time  int    Node Timestamp in miliseconds.\n"
      "X     double X distance from earth-center in meters.\n"
      "Y     double Y distance from earth-center in meters.\n"
      "Z     double Z distance from earth-center in meters.\n"
      "Yaw   double Yaw in radians.\n"
      "Pitch double Pitch in radians.\n"
      "Roll  double Roll in radians.\n"
      "Id    string Transmitter unique identifier.";
    const char* const PushSpoofTxTrackEcefNed::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(PushSpoofTxTrackEcefNed);
    REGISTER_COMMAND_TO_FACTORY_IMPL(PushSpoofTxTrackEcefNed);


    PushSpoofTxTrackEcefNed::PushSpoofTxTrackEcefNed()
      : CommandBase(CmdName, TargetId)
    {}

    PushSpoofTxTrackEcefNed::PushSpoofTxTrackEcefNed(int time, double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setTime(time);
      setX(x);
      setY(y);
      setZ(z);
      setYaw(yaw);
      setPitch(pitch);
      setRoll(roll);
      setId(id);
    }

    PushSpoofTxTrackEcefNedPtr PushSpoofTxTrackEcefNed::create(int time, double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
    {
      return std::make_shared<PushSpoofTxTrackEcefNed>(time, x, y, z, yaw, pitch, roll, id);
    }

    PushSpoofTxTrackEcefNedPtr PushSpoofTxTrackEcefNed::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<PushSpoofTxTrackEcefNed>(ptr);
    }

    bool PushSpoofTxTrackEcefNed::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Time"])
          && parse_json<double>::is_valid(m_values["X"])
          && parse_json<double>::is_valid(m_values["Y"])
          && parse_json<double>::is_valid(m_values["Z"])
          && parse_json<double>::is_valid(m_values["Yaw"])
          && parse_json<double>::is_valid(m_values["Pitch"])
          && parse_json<double>::is_valid(m_values["Roll"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string PushSpoofTxTrackEcefNed::documentation() const { return Documentation; }

    const std::vector<std::string>& PushSpoofTxTrackEcefNed::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Time", "X", "Y", "Z", "Yaw", "Pitch", "Roll", "Id"}; 
      return names; 
    }


    int PushSpoofTxTrackEcefNed::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int PushSpoofTxTrackEcefNed::time() const
    {
      return parse_json<int>::parse(m_values["Time"]);
    }

    void PushSpoofTxTrackEcefNed::setTime(int time)
    {
      m_values.AddMember("Time", parse_json<int>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushSpoofTxTrackEcefNed::x() const
    {
      return parse_json<double>::parse(m_values["X"]);
    }

    void PushSpoofTxTrackEcefNed::setX(double x)
    {
      m_values.AddMember("X", parse_json<double>::format(x, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushSpoofTxTrackEcefNed::y() const
    {
      return parse_json<double>::parse(m_values["Y"]);
    }

    void PushSpoofTxTrackEcefNed::setY(double y)
    {
      m_values.AddMember("Y", parse_json<double>::format(y, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushSpoofTxTrackEcefNed::z() const
    {
      return parse_json<double>::parse(m_values["Z"]);
    }

    void PushSpoofTxTrackEcefNed::setZ(double z)
    {
      m_values.AddMember("Z", parse_json<double>::format(z, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushSpoofTxTrackEcefNed::yaw() const
    {
      return parse_json<double>::parse(m_values["Yaw"]);
    }

    void PushSpoofTxTrackEcefNed::setYaw(double yaw)
    {
      m_values.AddMember("Yaw", parse_json<double>::format(yaw, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushSpoofTxTrackEcefNed::pitch() const
    {
      return parse_json<double>::parse(m_values["Pitch"]);
    }

    void PushSpoofTxTrackEcefNed::setPitch(double pitch)
    {
      m_values.AddMember("Pitch", parse_json<double>::format(pitch, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushSpoofTxTrackEcefNed::roll() const
    {
      return parse_json<double>::parse(m_values["Roll"]);
    }

    void PushSpoofTxTrackEcefNed::setRoll(double roll)
    {
      m_values.AddMember("Roll", parse_json<double>::format(roll, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string PushSpoofTxTrackEcefNed::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void PushSpoofTxTrackEcefNed::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
