#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetDynamicRangeOffset.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------
    /// Offset double Dynamic Range Offset (dB). Value must be between -10 and +45 dB.
    ///

    class GetDynamicRangeOffsetResult;
    typedef std::shared_ptr<GetDynamicRangeOffsetResult> GetDynamicRangeOffsetResultPtr;
    
    
    class GetDynamicRangeOffsetResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetDynamicRangeOffsetResult();

      GetDynamicRangeOffsetResult(double offset);

      GetDynamicRangeOffsetResult(CommandBasePtr relatedCommand, double offset);

      static GetDynamicRangeOffsetResultPtr create(double offset);

      static GetDynamicRangeOffsetResultPtr create(CommandBasePtr relatedCommand, double offset);
      static GetDynamicRangeOffsetResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** offset ****
      double offset() const;
      void setOffset(double offset);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetDynamicRangeOffsetResult);
  }
}

