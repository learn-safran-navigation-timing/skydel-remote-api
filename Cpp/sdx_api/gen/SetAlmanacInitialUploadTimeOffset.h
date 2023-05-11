#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set next almanac upload time relative to simulation start time.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------------------------------------
    /// System string Must be "GPS"
    /// Offset int    Next upload time in sec (relative to simulation start time). Accepted range is [30..259200]
    ///

    class SetAlmanacInitialUploadTimeOffset;
    typedef std::shared_ptr<SetAlmanacInitialUploadTimeOffset> SetAlmanacInitialUploadTimeOffsetPtr;
    
    
    class SetAlmanacInitialUploadTimeOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetAlmanacInitialUploadTimeOffset();

      SetAlmanacInitialUploadTimeOffset(const std::string& system, int offset);

      static SetAlmanacInitialUploadTimeOffsetPtr create(const std::string& system, int offset);
      static SetAlmanacInitialUploadTimeOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** offset ****
      int offset() const;
      void setOffset(int offset);
    };
    
  }
}

