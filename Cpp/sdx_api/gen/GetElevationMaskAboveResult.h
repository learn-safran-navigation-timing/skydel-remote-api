#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


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
      static const char* const TargetId;


      GetElevationMaskAboveResult();

      GetElevationMaskAboveResult(double angle);

      GetElevationMaskAboveResult(CommandBasePtr relatedCommand, double angle);

      static GetElevationMaskAboveResultPtr create(double angle);

      static GetElevationMaskAboveResultPtr create(CommandBasePtr relatedCommand, double angle);
      static GetElevationMaskAboveResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** angle ****
      double angle() const;
      void setAngle(double angle);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetElevationMaskAboveResult);
  }
}

