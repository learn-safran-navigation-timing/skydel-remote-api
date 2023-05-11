#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGlobalPowerOffset.
    ///
    /// Name   Type   Description
    /// ------ ------ ---------------------------------------------------
    /// Offset double Offset in dB (negative value will attenuate signal)
    ///

    class GetGlobalPowerOffsetResult;
    typedef std::shared_ptr<GetGlobalPowerOffsetResult> GetGlobalPowerOffsetResultPtr;
    typedef GetGlobalPowerOffsetResult GetPowerGlobalOffsetResult;
    typedef std::shared_ptr<GetPowerGlobalOffsetResult> GetPowerGlobalOffsetResultPtr;
    
    class GetGlobalPowerOffsetResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGlobalPowerOffsetResult();

      GetGlobalPowerOffsetResult(double offset);

      GetGlobalPowerOffsetResult(CommandBasePtr relatedCommand, double offset);

      static GetGlobalPowerOffsetResultPtr create(double offset);

      static GetGlobalPowerOffsetResultPtr create(CommandBasePtr relatedCommand, double offset);
      static GetGlobalPowerOffsetResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** offset ****
      double offset() const;
      void setOffset(double offset);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetGlobalPowerOffsetResult);
  }
}

