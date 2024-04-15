#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetElevationMaskBelow.
    ///
    /// Name  Type   Description
    /// ----- ------ ---------------------------
    /// Angle double Elevation mask angle in rad
    ///

    class GetElevationMaskBelowResult;
    typedef std::shared_ptr<GetElevationMaskBelowResult> GetElevationMaskBelowResultPtr;
    
    
    class GetElevationMaskBelowResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetElevationMaskBelowResult();

      GetElevationMaskBelowResult(double angle);

      GetElevationMaskBelowResult(CommandBasePtr relatedCommand, double angle);

      static GetElevationMaskBelowResultPtr create(double angle);

      static GetElevationMaskBelowResultPtr create(CommandBasePtr relatedCommand, double angle);
      static GetElevationMaskBelowResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** angle ****
      double angle() const;
      void setAngle(double angle);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetElevationMaskBelowResult);
  }
}

