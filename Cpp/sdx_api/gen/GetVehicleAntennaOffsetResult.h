#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetVehicleAntennaOffset.
    ///
    /// Name  Type            Description
    /// ----- --------------- --------------------------------------------
    /// X     double          Antenna X offset in the body frame (meter)
    /// Y     double          Antenna Y offset in the body frame (meter)
    /// Z     double          Antenna Z offset in the body frame (meter)
    /// Yaw   double          Antenna Yaw offset in the body frame (rad)
    /// Pitch double          Antenna Pitch offset in the body frame (rad)
    /// Roll  double          Antenna Roll offset in the body frame (rad)
    /// Name  optional string Unique vehicle antenna name
    ///

    class GetVehicleAntennaOffsetResult;
    typedef std::shared_ptr<GetVehicleAntennaOffsetResult> GetVehicleAntennaOffsetResultPtr;
    
    
    class GetVehicleAntennaOffsetResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetVehicleAntennaOffsetResult();

      GetVehicleAntennaOffsetResult(double x, double y, double z, double yaw, double pitch, double roll, const std::optional<std::string>& name = {});

      GetVehicleAntennaOffsetResult(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll, const std::optional<std::string>& name = {});

      static GetVehicleAntennaOffsetResultPtr create(double x, double y, double z, double yaw, double pitch, double roll, const std::optional<std::string>& name = {});

      static GetVehicleAntennaOffsetResultPtr create(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll, const std::optional<std::string>& name = {});
      static GetVehicleAntennaOffsetResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** x ****
      double x() const;
      void setX(double x);


      // **** y ****
      double y() const;
      void setY(double y);


      // **** z ****
      double z() const;
      void setZ(double z);


      // **** yaw ****
      double yaw() const;
      void setYaw(double yaw);


      // **** pitch ****
      double pitch() const;
      void setPitch(double pitch);


      // **** roll ****
      double roll() const;
      void setRoll(double roll);


      // **** name ****
      std::optional<std::string> name() const;
      void setName(const std::optional<std::string>& name);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetVehicleAntennaOffsetResult);
  }
}

