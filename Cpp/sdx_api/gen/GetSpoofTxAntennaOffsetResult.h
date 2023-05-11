#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSpoofTxAntennaOffset.
    ///
    /// Name  Type   Description
    /// ----- ------ --------------------------------------
    /// X     double Antenna X offset in the body frame
    /// Y     double Antenna Y offset in the body frame
    /// Z     double Antenna Z offset in the body frame
    /// Yaw   double Antenna Yaw offset in the body frame
    /// Pitch double Antenna Pitch offset in the body frame
    /// Roll  double Antenna Roll offset in the body frame
    /// Id    string Transmitter unique identifier.
    ///

    class GetSpoofTxAntennaOffsetResult;
    typedef std::shared_ptr<GetSpoofTxAntennaOffsetResult> GetSpoofTxAntennaOffsetResultPtr;
    
    
    class GetSpoofTxAntennaOffsetResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSpoofTxAntennaOffsetResult();

      GetSpoofTxAntennaOffsetResult(double x, double y, double z, double yaw, double pitch, double roll, const std::string& id);

      GetSpoofTxAntennaOffsetResult(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll, const std::string& id);

      static GetSpoofTxAntennaOffsetResultPtr create(double x, double y, double z, double yaw, double pitch, double roll, const std::string& id);

      static GetSpoofTxAntennaOffsetResultPtr create(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll, const std::string& id);
      static GetSpoofTxAntennaOffsetResultPtr dynamicCast(CommandBasePtr ptr);
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


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetSpoofTxAntennaOffsetResult);
  }
}

