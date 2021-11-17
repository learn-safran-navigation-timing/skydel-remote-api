#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetElevationMaskAbove.
    ///
    /// Name  Type   Description
    /// ----- ------ ---------------------------
    /// Angle double Elevation mask angle in rad
    ///

    class GetElevationMaskAboveResult;
    typedef std::shared_ptr<GetElevationMaskAboveResult> GetElevationMaskAboveResultPtr;
    
    
    class GetElevationMaskAboveResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetElevationMaskAboveResult();

      GetElevationMaskAboveResult(CommandBasePtr relatedCommand, double angle);
  
      static GetElevationMaskAboveResultPtr create(CommandBasePtr relatedCommand, double angle);
      static GetElevationMaskAboveResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** angle ****
      double angle() const;
      void setAngle(double angle);
    };
  }
}

