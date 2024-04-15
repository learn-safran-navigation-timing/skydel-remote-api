#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetStartTimeOffset.
    ///
    /// Name   Type Description
    /// ------ ---- -----------------------------------------------------------------------------------------
    /// Offset int  Time Offset, in seconds, between simulated GPS time and time given by GPS Timing receiver
    ///

    class GetStartTimeOffsetResult;
    typedef std::shared_ptr<GetStartTimeOffsetResult> GetStartTimeOffsetResultPtr;
    
    
    class GetStartTimeOffsetResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetStartTimeOffsetResult();

      GetStartTimeOffsetResult(int offset);

      GetStartTimeOffsetResult(CommandBasePtr relatedCommand, int offset);

      static GetStartTimeOffsetResultPtr create(int offset);

      static GetStartTimeOffsetResultPtr create(CommandBasePtr relatedCommand, int offset);
      static GetStartTimeOffsetResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** offset ****
      int offset() const;
      void setOffset(int offset);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetStartTimeOffsetResult);
  }
}

