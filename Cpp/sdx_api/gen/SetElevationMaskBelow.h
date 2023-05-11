#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set elevation mask angle. See command EnableElevationMaskBelow
    ///
    /// Name  Type   Description
    /// ----- ------ ---------------------------
    /// Angle double Elevation mask angle in rad
    ///

    class SetElevationMaskBelow;
    typedef std::shared_ptr<SetElevationMaskBelow> SetElevationMaskBelowPtr;
    
    
    class SetElevationMaskBelow : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetElevationMaskBelow();

      SetElevationMaskBelow(double angle);

      static SetElevationMaskBelowPtr create(double angle);
      static SetElevationMaskBelowPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** angle ****
      double angle() const;
      void setAngle(double angle);
    };
    
  }
}

