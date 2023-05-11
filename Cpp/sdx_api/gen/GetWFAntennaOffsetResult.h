#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetWFAntennaOffset.
    ///
    /// Name  Type   Description
    /// ----- ------ -----------------------------------------------
    /// X     double WF Antenna X offset in the body frame (meter)
    /// Y     double WF Antenna Y offset in the body frame (meter)
    /// Z     double WF Antenna Z offset in the body frame (meter)
    /// Yaw   double WF Antenna Yaw offset in the body frame (rad)
    /// Pitch double WF Antenna Pitch offset in the body frame (rad)
    /// Roll  double WF Antenna Roll offset in the body frame (rad)
    ///

    class GetWFAntennaOffsetResult;
    typedef std::shared_ptr<GetWFAntennaOffsetResult> GetWFAntennaOffsetResultPtr;
    
    
    class GetWFAntennaOffsetResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetWFAntennaOffsetResult();

      GetWFAntennaOffsetResult(double x, double y, double z, double yaw, double pitch, double roll);

      GetWFAntennaOffsetResult(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll);

      static GetWFAntennaOffsetResultPtr create(double x, double y, double z, double yaw, double pitch, double roll);

      static GetWFAntennaOffsetResultPtr create(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll);
      static GetWFAntennaOffsetResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


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
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetWFAntennaOffsetResult);
  }
}

