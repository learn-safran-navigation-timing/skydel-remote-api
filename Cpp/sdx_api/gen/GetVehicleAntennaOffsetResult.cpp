
#include "GetVehicleAntennaOffsetResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleAntennaOffsetResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleAntennaOffsetResult::CmdName = "GetVehicleAntennaOffsetResult";
    const char* const GetVehicleAntennaOffsetResult::Documentation = "Result of GetVehicleAntennaOffset.\n"
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
    const char* const GetVehicleAntennaOffsetResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetVehicleAntennaOffsetResult);


    GetVehicleAntennaOffsetResult::GetVehicleAntennaOffsetResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetVehicleAntennaOffsetResult::GetVehicleAntennaOffsetResult(double x, double y, double z, double yaw, double pitch, double roll, const Sdx::optional<std::string>& name)
      : CommandResult(CmdName, TargetId)
    {

      setX(x);
      setY(y);
      setZ(z);
      setYaw(yaw);
      setPitch(pitch);
      setRoll(roll);
      setName(name);
    }

    GetVehicleAntennaOffsetResult::GetVehicleAntennaOffsetResult(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll, const Sdx::optional<std::string>& name)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setX(x);
      setY(y);
      setZ(z);
      setYaw(yaw);
      setPitch(pitch);
      setRoll(roll);
      setName(name);
    }


    GetVehicleAntennaOffsetResultPtr GetVehicleAntennaOffsetResult::create(double x, double y, double z, double yaw, double pitch, double roll, const Sdx::optional<std::string>& name)
    {
      return std::make_shared<GetVehicleAntennaOffsetResult>(x, y, z, yaw, pitch, roll, name);
    }

    GetVehicleAntennaOffsetResultPtr GetVehicleAntennaOffsetResult::create(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll, const Sdx::optional<std::string>& name)
    {
      return std::make_shared<GetVehicleAntennaOffsetResult>(relatedCommand, x, y, z, yaw, pitch, roll, name);
    }

    GetVehicleAntennaOffsetResultPtr GetVehicleAntennaOffsetResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleAntennaOffsetResult>(ptr);
    }

    bool GetVehicleAntennaOffsetResult::isValid() const
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

    std::string GetVehicleAntennaOffsetResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetVehicleAntennaOffsetResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"X", "Y", "Z", "Yaw", "Pitch", "Roll", "Name"}; 
      return names; 
    }


    double GetVehicleAntennaOffsetResult::x() const
    {
      return parse_json<double>::parse(m_values["X"]);
    }

    void GetVehicleAntennaOffsetResult::setX(double x)
    {
      m_values.AddMember("X", parse_json<double>::format(x, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleAntennaOffsetResult::y() const
    {
      return parse_json<double>::parse(m_values["Y"]);
    }

    void GetVehicleAntennaOffsetResult::setY(double y)
    {
      m_values.AddMember("Y", parse_json<double>::format(y, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleAntennaOffsetResult::z() const
    {
      return parse_json<double>::parse(m_values["Z"]);
    }

    void GetVehicleAntennaOffsetResult::setZ(double z)
    {
      m_values.AddMember("Z", parse_json<double>::format(z, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleAntennaOffsetResult::yaw() const
    {
      return parse_json<double>::parse(m_values["Yaw"]);
    }

    void GetVehicleAntennaOffsetResult::setYaw(double yaw)
    {
      m_values.AddMember("Yaw", parse_json<double>::format(yaw, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleAntennaOffsetResult::pitch() const
    {
      return parse_json<double>::parse(m_values["Pitch"]);
    }

    void GetVehicleAntennaOffsetResult::setPitch(double pitch)
    {
      m_values.AddMember("Pitch", parse_json<double>::format(pitch, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleAntennaOffsetResult::roll() const
    {
      return parse_json<double>::parse(m_values["Roll"]);
    }

    void GetVehicleAntennaOffsetResult::setRoll(double roll)
    {
      m_values.AddMember("Roll", parse_json<double>::format(roll, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetVehicleAntennaOffsetResult::name() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["Name"]);
    }

    void GetVehicleAntennaOffsetResult::setName(const Sdx::optional<std::string>& name)
    {
      m_values.AddMember("Name", parse_json<Sdx::optional<std::string>>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
