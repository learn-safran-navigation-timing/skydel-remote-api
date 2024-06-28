
#include "GetElevationAzimuthForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetElevationAzimuthForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetElevationAzimuthForSVResult::CmdName = "GetElevationAzimuthForSVResult";
    const char* const GetElevationAzimuthForSVResult::Documentation = "Result of GetElevationAzimuthForSV.\n"
      "\n"
      "Name             Type                      Description\n"
      "---------------- ------------------------- ---------------------------------------------------------------------------\n"
      "System           string                    \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\".\n"
      "SvId             int                       Satellite's SV ID.\n"
      "ElevationAzimuth optional ElevationAzimuth Elevation and Azimuth position angles of the satellite.";
    const char* const GetElevationAzimuthForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetElevationAzimuthForSVResult);


    GetElevationAzimuthForSVResult::GetElevationAzimuthForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetElevationAzimuthForSVResult::GetElevationAzimuthForSVResult(const std::string& system, int svId, const std::optional<Sdx::ElevationAzimuth>& elevationAzimuth)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setElevationAzimuth(elevationAzimuth);
    }

    GetElevationAzimuthForSVResult::GetElevationAzimuthForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::optional<Sdx::ElevationAzimuth>& elevationAzimuth)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
      setElevationAzimuth(elevationAzimuth);
    }


    GetElevationAzimuthForSVResultPtr GetElevationAzimuthForSVResult::create(const std::string& system, int svId, const std::optional<Sdx::ElevationAzimuth>& elevationAzimuth)
    {
      return std::make_shared<GetElevationAzimuthForSVResult>(system, svId, elevationAzimuth);
    }

    GetElevationAzimuthForSVResultPtr GetElevationAzimuthForSVResult::create(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::optional<Sdx::ElevationAzimuth>& elevationAzimuth)
    {
      return std::make_shared<GetElevationAzimuthForSVResult>(relatedCommand, system, svId, elevationAzimuth);
    }

    GetElevationAzimuthForSVResultPtr GetElevationAzimuthForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetElevationAzimuthForSVResult>(ptr);
    }

    bool GetElevationAzimuthForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::optional<Sdx::ElevationAzimuth>>::is_valid(m_values["ElevationAzimuth"])
        ;

    }

    std::string GetElevationAzimuthForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetElevationAzimuthForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "ElevationAzimuth"}; 
      return names; 
    }


    std::string GetElevationAzimuthForSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetElevationAzimuthForSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetElevationAzimuthForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetElevationAzimuthForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<Sdx::ElevationAzimuth> GetElevationAzimuthForSVResult::elevationAzimuth() const
    {
      return parse_json<std::optional<Sdx::ElevationAzimuth>>::parse(m_values["ElevationAzimuth"]);
    }

    void GetElevationAzimuthForSVResult::setElevationAzimuth(const std::optional<Sdx::ElevationAzimuth>& elevationAzimuth)
    {
      m_values.AddMember("ElevationAzimuth", parse_json<std::optional<Sdx::ElevationAzimuth>>::format(elevationAzimuth, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
