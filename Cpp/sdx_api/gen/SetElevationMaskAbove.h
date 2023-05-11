#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set elevation mask angle. See command EnableElevationMaskAbove
    ///
    /// Name  Type   Description
    /// ----- ------ ---------------------------
    /// Angle double Elevation mask angle in rad
    ///

    class SetElevationMaskAbove;
    typedef std::shared_ptr<SetElevationMaskAbove> SetElevationMaskAbovePtr;
    
    
    class SetElevationMaskAbove : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetElevationMaskAbove();

      SetElevationMaskAbove(double angle);

      static SetElevationMaskAbovePtr create(double angle);
      static SetElevationMaskAbovePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** angle ****
      double angle() const;
      void setAngle(double angle);
    };
    
  }
}

