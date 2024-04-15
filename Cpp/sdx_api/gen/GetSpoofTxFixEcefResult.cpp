
#include "GetSpoofTxFixEcefResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSpoofTxFixEcefResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSpoofTxFixEcefResult::CmdName = "GetSpoofTxFixEcefResult";
    const char* const GetSpoofTxFixEcefResult::Documentation = "Result of GetSpoofTxFixEcef.\n"
      "\n"
      "Name  Type   Description\n"
      "----- ------ ------------------------------\n"
      "X     double ECEF X (m)\n"
      "Y     double ECEF Y (m)\n"
      "Z     double ECEF Z (m)\n"
      "Yaw   double Yaw (rad)\n"
      "Pitch double Pitch (rad)\n"
      "Roll  double Roll (rad)\n"
      "Id    string Transmitter unique identifier.";
    const char* const GetSpoofTxFixEcefResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSpoofTxFixEcefResult);


    GetSpoofTxFixEcefResult::GetSpoofTxFixEcefResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetSpoofTxFixEcefResult::GetSpoofTxFixEcefResult(double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
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

    GetSpoofTxFixEcefResult::GetSpoofTxFixEcefResult(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
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


    GetSpoofTxFixEcefResultPtr GetSpoofTxFixEcefResult::create(double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
    {
      return std::make_shared<GetSpoofTxFixEcefResult>(x, y, z, yaw, pitch, roll, id);
    }

    GetSpoofTxFixEcefResultPtr GetSpoofTxFixEcefResult::create(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
    {
      return std::make_shared<GetSpoofTxFixEcefResult>(relatedCommand, x, y, z, yaw, pitch, roll, id);
    }

    GetSpoofTxFixEcefResultPtr GetSpoofTxFixEcefResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSpoofTxFixEcefResult>(ptr);
    }

    bool GetSpoofTxFixEcefResult::isValid() const
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

    std::string GetSpoofTxFixEcefResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSpoofTxFixEcefResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"X", "Y", "Z", "Yaw", "Pitch", "Roll", "Id"}; 
      return names; 
    }


    double GetSpoofTxFixEcefResult::x() const
    {
      return parse_json<double>::parse(m_values["X"]);
    }

    void GetSpoofTxFixEcefResult::setX(double x)
    {
      m_values.AddMember("X", parse_json<double>::format(x, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSpoofTxFixEcefResult::y() const
    {
      return parse_json<double>::parse(m_values["Y"]);
    }

    void GetSpoofTxFixEcefResult::setY(double y)
    {
      m_values.AddMember("Y", parse_json<double>::format(y, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSpoofTxFixEcefResult::z() const
    {
      return parse_json<double>::parse(m_values["Z"]);
    }

    void GetSpoofTxFixEcefResult::setZ(double z)
    {
      m_values.AddMember("Z", parse_json<double>::format(z, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSpoofTxFixEcefResult::yaw() const
    {
      return parse_json<double>::parse(m_values["Yaw"]);
    }

    void GetSpoofTxFixEcefResult::setYaw(double yaw)
    {
      m_values.AddMember("Yaw", parse_json<double>::format(yaw, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSpoofTxFixEcefResult::pitch() const
    {
      return parse_json<double>::parse(m_values["Pitch"]);
    }

    void GetSpoofTxFixEcefResult::setPitch(double pitch)
    {
      m_values.AddMember("Pitch", parse_json<double>::format(pitch, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSpoofTxFixEcefResult::roll() const
    {
      return parse_json<double>::parse(m_values["Roll"]);
    }

    void GetSpoofTxFixEcefResult::setRoll(double roll)
    {
      m_values.AddMember("Roll", parse_json<double>::format(roll, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSpoofTxFixEcefResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetSpoofTxFixEcefResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
