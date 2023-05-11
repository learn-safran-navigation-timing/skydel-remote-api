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
    /// Result of GetIntTxFixEcef.
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

    class GetIntTxFixEcefResult;
    typedef std::shared_ptr<GetIntTxFixEcefResult> GetIntTxFixEcefResultPtr;
    
    
    class GetIntTxFixEcefResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIntTxFixEcefResult();

      GetIntTxFixEcefResult(double x, double y, double z, double yaw, double pitch, double roll, const std::string& id);

      GetIntTxFixEcefResult(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll, const std::string& id);

      static GetIntTxFixEcefResultPtr create(double x, double y, double z, double yaw, double pitch, double roll, const std::string& id);

      static GetIntTxFixEcefResultPtr create(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll, const std::string& id);
      static GetIntTxFixEcefResultPtr dynamicCast(CommandBasePtr ptr);
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
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetIntTxFixEcefResult);
  }
}

