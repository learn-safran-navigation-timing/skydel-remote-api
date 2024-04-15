#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSpoofTxFixEcef.
    ///
    /// Name  Type   Description
    /// ----- ------ ------------------------------
    /// X     double ECEF X (m)
    /// Y     double ECEF Y (m)
    /// Z     double ECEF Z (m)
    /// Yaw   double Yaw (rad)
    /// Pitch double Pitch (rad)
    /// Roll  double Roll (rad)
    /// Id    string Transmitter unique identifier.
    ///

    class GetSpoofTxFixEcefResult;
    typedef std::shared_ptr<GetSpoofTxFixEcefResult> GetSpoofTxFixEcefResultPtr;
    
    
    class GetSpoofTxFixEcefResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSpoofTxFixEcefResult();

      GetSpoofTxFixEcefResult(double x, double y, double z, double yaw, double pitch, double roll, const std::string& id);

      GetSpoofTxFixEcefResult(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll, const std::string& id);

      static GetSpoofTxFixEcefResultPtr create(double x, double y, double z, double yaw, double pitch, double roll, const std::string& id);

      static GetSpoofTxFixEcefResultPtr create(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll, const std::string& id);
      static GetSpoofTxFixEcefResultPtr dynamicCast(CommandBasePtr ptr);
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


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetSpoofTxFixEcefResult);
  }
}

