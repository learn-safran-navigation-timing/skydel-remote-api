#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSyncTime
    ///
    /// Name Type   Description
    /// ---- ------ ----------------------------------------
    /// Time double Time delay in msec (minimum is 500 msec)
    ///

    class GetSyncTimeResult;
    typedef std::shared_ptr<GetSyncTimeResult> GetSyncTimeResultPtr;
    
    
    class GetSyncTimeResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSyncTimeResult();

      GetSyncTimeResult(CommandBasePtr relatedCommand, double time);
  
      static GetSyncTimeResultPtr create(CommandBasePtr relatedCommand, double time);
      static GetSyncTimeResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** time ****
      double time() const;
      void setTime(double time);
    };
  }
}

