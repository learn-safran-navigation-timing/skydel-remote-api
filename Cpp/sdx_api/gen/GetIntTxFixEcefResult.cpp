
#include "GetIntTxFixEcefResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxFixEcefResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxFixEcefResult::CmdName = "GetIntTxFixEcefResult";
    const char* const GetIntTxFixEcefResult::Documentation = "Result of GetIntTxFixEcef.\n"
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
    const char* const GetIntTxFixEcefResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIntTxFixEcefResult);


    GetIntTxFixEcefResult::GetIntTxFixEcefResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetIntTxFixEcefResult::GetIntTxFixEcefResult(double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
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

    GetIntTxFixEcefResult::GetIntTxFixEcefResult(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
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


    GetIntTxFixEcefResultPtr GetIntTxFixEcefResult::create(double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
    {
      return std::make_shared<GetIntTxFixEcefResult>(x, y, z, yaw, pitch, roll, id);
    }

    GetIntTxFixEcefResultPtr GetIntTxFixEcefResult::create(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
    {
      return std::make_shared<GetIntTxFixEcefResult>(relatedCommand, x, y, z, yaw, pitch, roll, id);
    }

    GetIntTxFixEcefResultPtr GetIntTxFixEcefResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxFixEcefResult>(ptr);
    }

    bool GetIntTxFixEcefResult::isValid() const
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

    std::string GetIntTxFixEcefResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIntTxFixEcefResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"X", "Y", "Z", "Yaw", "Pitch", "Roll", "Id"}; 
      return names; 
    }


    double GetIntTxFixEcefResult::x() const
    {
      return parse_json<double>::parse(m_values["X"]);
    }

    void GetIntTxFixEcefResult::setX(double x)
    {
      m_values.AddMember("X", parse_json<double>::format(x, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxFixEcefResult::y() const
    {
      return parse_json<double>::parse(m_values["Y"]);
    }

    void GetIntTxFixEcefResult::setY(double y)
    {
      m_values.AddMember("Y", parse_json<double>::format(y, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxFixEcefResult::z() const
    {
      return parse_json<double>::parse(m_values["Z"]);
    }

    void GetIntTxFixEcefResult::setZ(double z)
    {
      m_values.AddMember("Z", parse_json<double>::format(z, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxFixEcefResult::yaw() const
    {
      return parse_json<double>::parse(m_values["Yaw"]);
    }

    void GetIntTxFixEcefResult::setYaw(double yaw)
    {
      m_values.AddMember("Yaw", parse_json<double>::format(yaw, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxFixEcefResult::pitch() const
    {
      return parse_json<double>::parse(m_values["Pitch"]);
    }

    void GetIntTxFixEcefResult::setPitch(double pitch)
    {
      m_values.AddMember("Pitch", parse_json<double>::format(pitch, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxFixEcefResult::roll() const
    {
      return parse_json<double>::parse(m_values["Roll"]);
    }

    void GetIntTxFixEcefResult::setRoll(double roll)
    {
      m_values.AddMember("Roll", parse_json<double>::format(roll, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxFixEcefResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetIntTxFixEcefResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
