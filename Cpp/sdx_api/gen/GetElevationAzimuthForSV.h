#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get elevation and azimuth position angles for satellite.
    ///
    /// Name   Type   Description
    /// ------ ------ -----------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC".
    /// SvId   int    Satellite's SV ID.
    ///

    class GetElevationAzimuthForSV;
    typedef std::shared_ptr<GetElevationAzimuthForSV> GetElevationAzimuthForSVPtr;
    
    
    class GetElevationAzimuthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetElevationAzimuthForSV();

      GetElevationAzimuthForSV(const std::string& system, int svId);

      static GetElevationAzimuthForSVPtr create(const std::string& system, int svId);
      static GetElevationAzimuthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
    
  }
}

