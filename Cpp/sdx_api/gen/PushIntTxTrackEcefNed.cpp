
#include "PushIntTxTrackEcefNed.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of PushIntTxTrackEcefNed
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const PushIntTxTrackEcefNed::CmdName = "PushIntTxTrackEcefNed";
    const char* const PushIntTxTrackEcefNed::Documentation = "Push an interference track ecef and ned attitude node. Must be called after BeginIntTxTrackDefinition and before EndIntTxTrackDefinition.\n"
      "\n"
      "Name  Type   Description\n"
      "----- ------ --------------------------------------\n"
      "Time  int    Node Timestamp in miliseconds\n"
      "X     double X distance from earth-center in meters\n"
      "Y     double Y distance from earth-center in meters\n"
      "Z     double Z distance from earth-center in meters\n"
      "Yaw   double Yaw in radians\n"
      "Pitch double Pitch in radians\n"
      "Roll  double Roll in radians\n"
      "Id    string Transmitter unique identifier.";
    const char* const PushIntTxTrackEcefNed::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(PushIntTxTrackEcefNed);
    REGISTER_COMMAND_TO_FACTORY_IMPL(PushIntTxTrackEcefNed);


    PushIntTxTrackEcefNed::PushIntTxTrackEcefNed()
      : CommandBase(CmdName, TargetId)
    {}

    PushIntTxTrackEcefNed::PushIntTxTrackEcefNed(int time, double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
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

    PushIntTxTrackEcefNedPtr PushIntTxTrackEcefNed::create(int time, double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
    {
      return std::make_shared<PushIntTxTrackEcefNed>(time, x, y, z, yaw, pitch, roll, id);
    }

    PushIntTxTrackEcefNedPtr PushIntTxTrackEcefNed::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<PushIntTxTrackEcefNed>(ptr);
    }

    bool PushIntTxTrackEcefNed::isValid() const
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

    std::string PushIntTxTrackEcefNed::documentation() const { return Documentation; }

    const std::vector<std::string>& PushIntTxTrackEcefNed::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Time", "X", "Y", "Z", "Yaw", "Pitch", "Roll", "Id"}; 
      return names; 
    }


    int PushIntTxTrackEcefNed::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int PushIntTxTrackEcefNed::time() const
    {
      return parse_json<int>::parse(m_values["Time"]);
    }

    void PushIntTxTrackEcefNed::setTime(int time)
    {
      m_values.AddMember("Time", parse_json<int>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushIntTxTrackEcefNed::x() const
    {
      return parse_json<double>::parse(m_values["X"]);
    }

    void PushIntTxTrackEcefNed::setX(double x)
    {
      m_values.AddMember("X", parse_json<double>::format(x, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushIntTxTrackEcefNed::y() const
    {
      return parse_json<double>::parse(m_values["Y"]);
    }

    void PushIntTxTrackEcefNed::setY(double y)
    {
      m_values.AddMember("Y", parse_json<double>::format(y, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushIntTxTrackEcefNed::z() const
    {
      return parse_json<double>::parse(m_values["Z"]);
    }

    void PushIntTxTrackEcefNed::setZ(double z)
    {
      m_values.AddMember("Z", parse_json<double>::format(z, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushIntTxTrackEcefNed::yaw() const
    {
      return parse_json<double>::parse(m_values["Yaw"]);
    }

    void PushIntTxTrackEcefNed::setYaw(double yaw)
    {
      m_values.AddMember("Yaw", parse_json<double>::format(yaw, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushIntTxTrackEcefNed::pitch() const
    {
      return parse_json<double>::parse(m_values["Pitch"]);
    }

    void PushIntTxTrackEcefNed::setPitch(double pitch)
    {
      m_values.AddMember("Pitch", parse_json<double>::format(pitch, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushIntTxTrackEcefNed::roll() const
    {
      return parse_json<double>::parse(m_values["Roll"]);
    }

    void PushIntTxTrackEcefNed::setRoll(double roll)
    {
      m_values.AddMember("Roll", parse_json<double>::format(roll, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string PushIntTxTrackEcefNed::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void PushIntTxTrackEcefNed::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
