
#include "GetVehiclePositionEcefResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehiclePositionEcefResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehiclePositionEcefResult::CmdName = "GetVehiclePositionEcefResult";
    const char* const GetVehiclePositionEcefResult::Documentation = "Result of GetVehiclePositionEcef.\n"
      "\n"
      "Name        Type   Description\n"
      "----------- ------ --------------------------------------------------------------------------------------\n"
      "ElapsedTime int    Simulation elapsed time in milliseconds at which the vehicle's position was retrieved.\n"
      "X           double X-component of vehicle's ECEF position (m).\n"
      "Y           double Y-component of vehicle's ECEF position (m).\n"
      "Z           double Z-component of vehicle's ECEF position (m).";
    const char* const GetVehiclePositionEcefResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetVehiclePositionEcefResult);


    GetVehiclePositionEcefResult::GetVehiclePositionEcefResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetVehiclePositionEcefResult::GetVehiclePositionEcefResult(int elapsedTime, double x, double y, double z)
      : CommandResult(CmdName, TargetId)
    {

      setElapsedTime(elapsedTime);
      setX(x);
      setY(y);
      setZ(z);
    }

    GetVehiclePositionEcefResult::GetVehiclePositionEcefResult(CommandBasePtr relatedCommand, int elapsedTime, double x, double y, double z)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setElapsedTime(elapsedTime);
      setX(x);
      setY(y);
      setZ(z);
    }


    GetVehiclePositionEcefResultPtr GetVehiclePositionEcefResult::create(int elapsedTime, double x, double y, double z)
    {
      return std::make_shared<GetVehiclePositionEcefResult>(elapsedTime, x, y, z);
    }

    GetVehiclePositionEcefResultPtr GetVehiclePositionEcefResult::create(CommandBasePtr relatedCommand, int elapsedTime, double x, double y, double z)
    {
      return std::make_shared<GetVehiclePositionEcefResult>(relatedCommand, elapsedTime, x, y, z);
    }

    GetVehiclePositionEcefResultPtr GetVehiclePositionEcefResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehiclePositionEcefResult>(ptr);
    }

    bool GetVehiclePositionEcefResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["ElapsedTime"])
          && parse_json<double>::is_valid(m_values["X"])
          && parse_json<double>::is_valid(m_values["Y"])
          && parse_json<double>::is_valid(m_values["Z"])
        ;

    }

    std::string GetVehiclePositionEcefResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetVehiclePositionEcefResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ElapsedTime", "X", "Y", "Z"}; 
      return names; 
    }


    int GetVehiclePositionEcefResult::elapsedTime() const
    {
      return parse_json<int>::parse(m_values["ElapsedTime"]);
    }

    void GetVehiclePositionEcefResult::setElapsedTime(int elapsedTime)
    {
      setValue("ElapsedTime", parse_json<int>::format(elapsedTime, m_values.GetAllocator()));
    }



    double GetVehiclePositionEcefResult::x() const
    {
      return parse_json<double>::parse(m_values["X"]);
    }

    void GetVehiclePositionEcefResult::setX(double x)
    {
      setValue("X", parse_json<double>::format(x, m_values.GetAllocator()));
    }



    double GetVehiclePositionEcefResult::y() const
    {
      return parse_json<double>::parse(m_values["Y"]);
    }

    void GetVehiclePositionEcefResult::setY(double y)
    {
      setValue("Y", parse_json<double>::format(y, m_values.GetAllocator()));
    }



    double GetVehiclePositionEcefResult::z() const
    {
      return parse_json<double>::parse(m_values["Z"]);
    }

    void GetVehiclePositionEcefResult::setZ(double z)
    {
      setValue("Z", parse_json<double>::format(z, m_values.GetAllocator()));
    }


  }
}
