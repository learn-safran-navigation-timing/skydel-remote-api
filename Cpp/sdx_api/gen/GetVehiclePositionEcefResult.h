#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetVehiclePositionEcef.
    ///
    /// Name        Type   Description
    /// ----------- ------ --------------------------------------------------------------------------------------
    /// ElapsedTime int    Simulation elapsed time in milliseconds at which the vehicle's position was retrieved.
    /// X           double X-component of vehicle's ECEF position (m).
    /// Y           double Y-component of vehicle's ECEF position (m).
    /// Z           double Z-component of vehicle's ECEF position (m).
    ///

    class GetVehiclePositionEcefResult;
    typedef std::shared_ptr<GetVehiclePositionEcefResult> GetVehiclePositionEcefResultPtr;
    
    
    class GetVehiclePositionEcefResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetVehiclePositionEcefResult();

      GetVehiclePositionEcefResult(int elapsedTime, double x, double y, double z);

      GetVehiclePositionEcefResult(CommandBasePtr relatedCommand, int elapsedTime, double x, double y, double z);

      static GetVehiclePositionEcefResultPtr create(int elapsedTime, double x, double y, double z);

      static GetVehiclePositionEcefResultPtr create(CommandBasePtr relatedCommand, int elapsedTime, double x, double y, double z);
      static GetVehiclePositionEcefResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** elapsedTime ****
      int elapsedTime() const;
      void setElapsedTime(int elapsedTime);


      // **** x ****
      double x() const;
      void setX(double x);


      // **** y ****
      double y() const;
      void setY(double y);


      // **** z ****
      double z() const;
      void setZ(double z);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetVehiclePositionEcefResult);
  }
}

