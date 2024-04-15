
#include "PushTrackEcefNed.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of PushTrackEcefNed
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const PushTrackEcefNed::CmdName = "PushTrackEcefNed";
    const char* const PushTrackEcefNed::Documentation = "Push a track ecef and ned attitude node. Must be called after BeginTrackDefinition and before EndTrackDefinition.\n"
      "\n"
      "Name  Type   Description\n"
      "----- ------ --------------------------------------\n"
      "Time  int    Node Timestamp in miliseconds\n"
      "X     double X distance from earth-center in meters\n"
      "Y     double Y distance from earth-center in meters\n"
      "Z     double Z distance from earth-center in meters\n"
      "Yaw   double Yaw in radians\n"
      "Pitch double Pitch in radians\n"
      "Roll  double Roll in radians";
    const char* const PushTrackEcefNed::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(PushTrackEcefNed);
    REGISTER_COMMAND_TO_FACTORY_IMPL(PushTrackEcefNed);


    PushTrackEcefNed::PushTrackEcefNed()
      : CommandBase(CmdName, TargetId)
    {}

    PushTrackEcefNed::PushTrackEcefNed(int time, double x, double y, double z, double yaw, double pitch, double roll)
      : CommandBase(CmdName, TargetId)
    {

      setTime(time);
      setX(x);
      setY(y);
      setZ(z);
      setYaw(yaw);
      setPitch(pitch);
      setRoll(roll);
    }

    PushTrackEcefNedPtr PushTrackEcefNed::create(int time, double x, double y, double z, double yaw, double pitch, double roll)
    {
      return std::make_shared<PushTrackEcefNed>(time, x, y, z, yaw, pitch, roll);
    }

    PushTrackEcefNedPtr PushTrackEcefNed::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<PushTrackEcefNed>(ptr);
    }

    bool PushTrackEcefNed::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Time"])
          && parse_json<double>::is_valid(m_values["X"])
          && parse_json<double>::is_valid(m_values["Y"])
          && parse_json<double>::is_valid(m_values["Z"])
          && parse_json<double>::is_valid(m_values["Yaw"])
          && parse_json<double>::is_valid(m_values["Pitch"])
          && parse_json<double>::is_valid(m_values["Roll"])
        ;

    }

    std::string PushTrackEcefNed::documentation() const { return Documentation; }

    const std::vector<std::string>& PushTrackEcefNed::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Time", "X", "Y", "Z", "Yaw", "Pitch", "Roll"}; 
      return names; 
    }


    int PushTrackEcefNed::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int PushTrackEcefNed::time() const
    {
      return parse_json<int>::parse(m_values["Time"]);
    }

    void PushTrackEcefNed::setTime(int time)
    {
      m_values.AddMember("Time", parse_json<int>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushTrackEcefNed::x() const
    {
      return parse_json<double>::parse(m_values["X"]);
    }

    void PushTrackEcefNed::setX(double x)
    {
      m_values.AddMember("X", parse_json<double>::format(x, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushTrackEcefNed::y() const
    {
      return parse_json<double>::parse(m_values["Y"]);
    }

    void PushTrackEcefNed::setY(double y)
    {
      m_values.AddMember("Y", parse_json<double>::format(y, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushTrackEcefNed::z() const
    {
      return parse_json<double>::parse(m_values["Z"]);
    }

    void PushTrackEcefNed::setZ(double z)
    {
      m_values.AddMember("Z", parse_json<double>::format(z, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushTrackEcefNed::yaw() const
    {
      return parse_json<double>::parse(m_values["Yaw"]);
    }

    void PushTrackEcefNed::setYaw(double yaw)
    {
      m_values.AddMember("Yaw", parse_json<double>::format(yaw, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushTrackEcefNed::pitch() const
    {
      return parse_json<double>::parse(m_values["Pitch"]);
    }

    void PushTrackEcefNed::setPitch(double pitch)
    {
      m_values.AddMember("Pitch", parse_json<double>::format(pitch, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushTrackEcefNed::roll() const
    {
      return parse_json<double>::parse(m_values["Roll"]);
    }

    void PushTrackEcefNed::setRoll(double roll)
    {
      m_values.AddMember("Roll", parse_json<double>::format(roll, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
