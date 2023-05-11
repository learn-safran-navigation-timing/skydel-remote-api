#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include "gen/ElevationAzimuth.h"
#include "sdx_optional.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetElevationAzimuthForEachSV.
    ///
    /// Name              Type                            Description
    /// ----------------- ------------------------------- -----------------------------------------------------------------
    /// System            string                          "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC".
    /// ElevationAzimuths array optional ElevationAzimuth Elevation and Azimuth position angles of the satellites.
    ///

    class GetElevationAzimuthForEachSVResult;
    typedef std::shared_ptr<GetElevationAzimuthForEachSVResult> GetElevationAzimuthForEachSVResultPtr;
    
    
    class GetElevationAzimuthForEachSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetElevationAzimuthForEachSVResult();

      GetElevationAzimuthForEachSVResult(const std::string& system, const std::vector<Sdx::optional<Sdx::ElevationAzimuth>>& elevationAzimuths);

      GetElevationAzimuthForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<Sdx::optional<Sdx::ElevationAzimuth>>& elevationAzimuths);

      static GetElevationAzimuthForEachSVResultPtr create(const std::string& system, const std::vector<Sdx::optional<Sdx::ElevationAzimuth>>& elevationAzimuths);

      static GetElevationAzimuthForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<Sdx::optional<Sdx::ElevationAzimuth>>& elevationAzimuths);
      static GetElevationAzimuthForEachSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** elevationAzimuths ****
      std::vector<Sdx::optional<Sdx::ElevationAzimuth>> elevationAzimuths() const;
      void setElevationAzimuths(const std::vector<Sdx::optional<Sdx::ElevationAzimuth>>& elevationAzimuths);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetElevationAzimuthForEachSVResult);
  }
}

