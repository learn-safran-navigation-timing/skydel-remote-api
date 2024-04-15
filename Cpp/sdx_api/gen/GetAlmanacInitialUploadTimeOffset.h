#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get next almanac upload time relative to simulation start time.
    ///
    /// 
    ///

    class GetAlmanacInitialUploadTimeOffset;
    typedef std::shared_ptr<GetAlmanacInitialUploadTimeOffset> GetAlmanacInitialUploadTimeOffsetPtr;
    
    
    class GetAlmanacInitialUploadTimeOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetAlmanacInitialUploadTimeOffset();

      static GetAlmanacInitialUploadTimeOffsetPtr create();
      static GetAlmanacInitialUploadTimeOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

