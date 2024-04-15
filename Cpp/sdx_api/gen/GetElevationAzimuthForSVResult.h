#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "gen/ElevationAzimuth.h"
#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetElevationAzimuthForSV.
    ///
    /// Name             Type                      Description
    /// ---------------- ------------------------- ---------------------------------------------------------------------------
    /// System           string                    "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR".
    /// SvId             int                       Satellite's SV ID.
    /// ElevationAzimuth optional ElevationAzimuth Elevation and Azimuth position angles of the satellite.
    ///

    class GetElevationAzimuthForSVResult;
    typedef std::shared_ptr<GetElevationAzimuthForSVResult> GetElevationAzimuthForSVResultPtr;
    
    
    class GetElevationAzimuthForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetElevationAzimuthForSVResult();

      GetElevationAzimuthForSVResult(const std::string& system, int svId, const Sdx::optional<Sdx::ElevationAzimuth>& elevationAzimuth = {});

      GetElevationAzimuthForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const Sdx::optional<Sdx::ElevationAzimuth>& elevationAzimuth = {});

      static GetElevationAzimuthForSVResultPtr create(const std::string& system, int svId, const Sdx::optional<Sdx::ElevationAzimuth>& elevationAzimuth = {});

      static GetElevationAzimuthForSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, const Sdx::optional<Sdx::ElevationAzimuth>& elevationAzimuth = {});
      static GetElevationAzimuthForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** elevationAzimuth ****
      Sdx::optional<Sdx::ElevationAzimuth> elevationAzimuth() const;
      void setElevationAzimuth(const Sdx::optional<Sdx::ElevationAzimuth>& elevationAzimuth);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetElevationAzimuthForSVResult);
  }
}

