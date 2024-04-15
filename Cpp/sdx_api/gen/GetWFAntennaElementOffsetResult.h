#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetWFAntennaElementOffset.
    ///
    /// Name    Type   Description
    /// ------- ------ -------------------------------------------------------
    /// X       double WF Element X offset in the CRPA antenna frame (meter)
    /// Y       double WF Element Y offset in the CRPA antenna frame (meter)
    /// Z       double WF Element Z offset in the CRPA antenna frame (meter)
    /// Yaw     double WF Element Yaw offset in the CRPA antenna frame (rad)
    /// Pitch   double WF Element Pitch offset in the CRPA antenna frame (rad)
    /// Roll    double WF Element Roll offset in the CRPA antenna frame (rad)
    /// Element int    One-based index for element in antenna.
    ///

    class GetWFAntennaElementOffsetResult;
    typedef std::shared_ptr<GetWFAntennaElementOffsetResult> GetWFAntennaElementOffsetResultPtr;
    
    
    class GetWFAntennaElementOffsetResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetWFAntennaElementOffsetResult();

      GetWFAntennaElementOffsetResult(double x, double y, double z, double yaw, double pitch, double roll, int element);

      GetWFAntennaElementOffsetResult(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll, int element);

      static GetWFAntennaElementOffsetResultPtr create(double x, double y, double z, double yaw, double pitch, double roll, int element);

      static GetWFAntennaElementOffsetResultPtr create(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll, int element);
      static GetWFAntennaElementOffsetResultPtr dynamicCast(CommandBasePtr ptr);
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


      // **** element ****
      int element() const;
      void setElement(int element);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetWFAntennaElementOffsetResult);
  }
}

