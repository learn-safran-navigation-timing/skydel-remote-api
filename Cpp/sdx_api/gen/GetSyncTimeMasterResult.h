#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSyncTimeMaster.
    ///
    /// Name Type   Description
    /// ---- ------ ----------------------------------------
    /// Time double Time delay in msec (minimum is 500 msec)
    ///

    class GetSyncTimeMasterResult;
    typedef std::shared_ptr<GetSyncTimeMasterResult> GetSyncTimeMasterResultPtr;
    
    
    class GetSyncTimeMasterResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSyncTimeMasterResult();

      GetSyncTimeMasterResult(double time);

      GetSyncTimeMasterResult(CommandBasePtr relatedCommand, double time);

      static GetSyncTimeMasterResultPtr create(double time);

      static GetSyncTimeMasterResultPtr create(CommandBasePtr relatedCommand, double time);
      static GetSyncTimeMasterResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** time ****
      double time() const;
      void setTime(double time);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetSyncTimeMasterResult);
  }
}

