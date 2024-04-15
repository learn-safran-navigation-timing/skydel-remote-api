#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get elevation and azimuth position angles for all satellites.
    ///
    /// Name   Type   Description
    /// ------ ------ ---------------------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR".
    ///

    class GetElevationAzimuthForEachSV;
    typedef std::shared_ptr<GetElevationAzimuthForEachSV> GetElevationAzimuthForEachSVPtr;
    
    
    class GetElevationAzimuthForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetElevationAzimuthForEachSV();

      GetElevationAzimuthForEachSV(const std::string& system);

      static GetElevationAzimuthForEachSVPtr create(const std::string& system);
      static GetElevationAzimuthForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
    
  }
}

