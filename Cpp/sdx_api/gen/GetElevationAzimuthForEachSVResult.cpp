
#include "gen/GetElevationAzimuthForEachSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetElevationAzimuthForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetElevationAzimuthForEachSVResult::CmdName = "GetElevationAzimuthForEachSVResult";
    const char* const GetElevationAzimuthForEachSVResult::Documentation = "Result of GetElevationAzimuthForEachSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetElevationAzimuthForEachSVResult);


    GetElevationAzimuthForEachSVResult::GetElevationAzimuthForEachSVResult()
      : CommandResult(CmdName)
    {}

    GetElevationAzimuthForEachSVResult::GetElevationAzimuthForEachSVResult(const std::string& system, const std::vector<Sdx::optional<Sdx::ElevationAzimuth>>& elevationAzimuths)
      : CommandResult(CmdName)
    {

      setSystem(system);
      setElevationAzimuths(elevationAzimuths);
    }

    GetElevationAzimuthForEachSVResult::GetElevationAzimuthForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<Sdx::optional<Sdx::ElevationAzimuth>>& elevationAzimuths)
      : CommandResult(CmdName, relatedCommand)
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
