
#include "GetElevationAzimuthForEachSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetElevationAzimuthForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetElevationAzimuthForEachSVResult::CmdName = "GetElevationAzimuthForEachSVResult";
    const char* const GetElevationAzimuthForEachSVResult::Documentation = "Result of GetElevationAzimuthForEachSV.\n"
      "\n"
      "Name              Type                            Description\n"
      "----------------- ------------------------------- ---------------------------------------------------------------------------\n"
      "System            string                          \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\".\n"
      "ElevationAzimuths array optional ElevationAzimuth Elevation and Azimuth position angles of the satellites.";
    const char* const GetElevationAzimuthForEachSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetElevationAzimuthForEachSVResult);


    GetElevationAzimuthForEachSVResult::GetElevationAzimuthForEachSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetElevationAzimuthForEachSVResult::GetElevationAzimuthForEachSVResult(const std::string& system, const std::vector<Sdx::optional<Sdx::ElevationAzimuth>>& elevationAzimuths)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setElevationAzimuths(elevationAzimuths);
    }

    GetElevationAzimuthForEachSVResult::GetElevationAzimuthForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<Sdx::optional<Sdx::ElevationAzimuth>>& elevationAzimuths)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setElevationAzimuths(elevationAzimuths);
    }


    GetElevationAzimuthForEachSVResultPtr GetElevationAzimuthForEachSVResult::create(const std::string& system, const std::vector<Sdx::optional<Sdx::ElevationAzimuth>>& elevationAzimuths)
    {
      return std::make_shared<GetElevationAzimuthForEachSVResult>(system, elevationAzimuths);
    }

    GetElevationAzimuthForEachSVResultPtr GetElevationAzimuthForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<Sdx::optional<Sdx::ElevationAzimuth>>& elevationAzimuths)
    {
      return std::make_shared<GetElevationAzimuthForEachSVResult>(relatedCommand, system, elevationAzimuths);
    }

    GetElevationAzimuthForEachSVResultPtr GetElevationAzimuthForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetElevationAzimuthForEachSVResult>(ptr);
    }

    bool GetElevationAzimuthForEachSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::vector<Sdx::optional<Sdx::ElevationAzimuth>>>::is_valid(m_values["ElevationAzimuths"])
        ;

    }

    std::string GetElevationAzimuthForEachSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetElevationAzimuthForEachSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "ElevationAzimuths"}; 
      return names; 
    }


    std::string GetElevationAzimuthForEachSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetElevationAzimuthForEachSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<Sdx::optional<Sdx::ElevationAzimuth>> GetElevationAzimuthForEachSVResult::elevationAzimuths() const
    {
      return parse_json<std::vector<Sdx::optional<Sdx::ElevationAzimuth>>>::parse(m_values["ElevationAzimuths"]);
    }

    void GetElevationAzimuthForEachSVResult::setElevationAzimuths(const std::vector<Sdx::optional<Sdx::ElevationAzimuth>>& elevationAzimuths)
    {
      m_values.AddMember("ElevationAzimuths", parse_json<std::vector<Sdx::optional<Sdx::ElevationAzimuth>>>::format(elevationAzimuths, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
