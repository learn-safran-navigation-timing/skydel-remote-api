
#include "GetSpoofTxAntennaOffsetResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSpoofTxAntennaOffsetResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSpoofTxAntennaOffsetResult::CmdName = "GetSpoofTxAntennaOffsetResult";
    const char* const GetSpoofTxAntennaOffsetResult::Documentation = "Result of GetSpoofTxAntennaOffset.\n"
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
    const char* const GetSpoofTxAntennaOffsetResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSpoofTxAntennaOffsetResult);


    GetSpoofTxAntennaOffsetResult::GetSpoofTxAntennaOffsetResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetSpoofTxAntennaOffsetResult::GetSpoofTxAntennaOffsetResult(double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setX(x);
      setY(y);
      setZ(z);
      setYaw(yaw);
      setPitch(pitch);
      setRoll(roll);
      setId(id);
    }

    GetSpoofTxAntennaOffsetResult::GetSpoofTxAntennaOffsetResult(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setX(x);
      setY(y);
      setZ(z);
      setYaw(yaw);
      setPitch(pitch);
      setRoll(roll);
      setId(id);
    }


    GetSpoofTxAntennaOffsetResultPtr GetSpoofTxAntennaOffsetResult::create(double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
    {
      return std::make_shared<GetSpoofTxAntennaOffsetResult>(x, y, z, yaw, pitch, roll, id);
    }

    GetSpoofTxAntennaOffsetResultPtr GetSpoofTxAntennaOffsetResult::create(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
    {
      return std::make_shared<GetSpoofTxAntennaOffsetResult>(relatedCommand, x, y, z, yaw, pitch, roll, id);
    }

    GetSpoofTxAntennaOffsetResultPtr GetSpoofTxAntennaOffsetResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSpoofTxAntennaOffsetResult>(ptr);
    }

    bool GetSpoofTxAntennaOffsetResult::isValid() const
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

    std::string GetSpoofTxAntennaOffsetResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSpoofTxAntennaOffsetResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"X", "Y", "Z", "Yaw", "Pitch", "Roll", "Id"}; 
      return names; 
    }


    double GetSpoofTxAntennaOffsetResult::x() const
    {
      return parse_json<double>::parse(m_values["X"]);
    }

    void GetSpoofTxAntennaOffsetResult::setX(double x)
    {
      m_values.AddMember("X", parse_json<double>::format(x, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSpoofTxAntennaOffsetResult::y() const
    {
      return parse_json<double>::parse(m_values["Y"]);
    }

    void GetSpoofTxAntennaOffsetResult::setY(double y)
    {
      m_values.AddMember("Y", parse_json<double>::format(y, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSpoofTxAntennaOffsetResult::z() const
    {
      return parse_json<double>::parse(m_values["Z"]);
    }

    void GetSpoofTxAntennaOffsetResult::setZ(double z)
    {
      m_values.AddMember("Z", parse_json<double>::format(z, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSpoofTxAntennaOffsetResult::yaw() const
    {
      return parse_json<double>::parse(m_values["Yaw"]);
    }

    void GetSpoofTxAntennaOffsetResult::setYaw(double yaw)
    {
      m_values.AddMember("Yaw", parse_json<double>::format(yaw, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSpoofTxAntennaOffsetResult::pitch() const
    {
      return parse_json<double>::parse(m_values["Pitch"]);
    }

    void GetSpoofTxAntennaOffsetResult::setPitch(double pitch)
    {
      m_values.AddMember("Pitch", parse_json<double>::format(pitch, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSpoofTxAntennaOffsetResult::roll() const
    {
      return parse_json<double>::parse(m_values["Roll"]);
    }

    void GetSpoofTxAntennaOffsetResult::setRoll(double roll)
    {
      m_values.AddMember("Roll", parse_json<double>::format(roll, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSpoofTxAntennaOffsetResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetSpoofTxAntennaOffsetResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
