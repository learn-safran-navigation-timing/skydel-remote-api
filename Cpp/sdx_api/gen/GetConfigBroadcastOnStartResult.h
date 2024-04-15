#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetConfigBroadcastOnStart.
    ///
    /// Name             Type Description
    /// ---------------- ---- --------------------------------------------------------------
    /// BroadcastOnStart bool True to broadcast the configuration on start, false otherwise.
    ///

    class GetConfigBroadcastOnStartResult;
    typedef std::shared_ptr<GetConfigBroadcastOnStartResult> GetConfigBroadcastOnStartResultPtr;
    
    
    class GetConfigBroadcastOnStartResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetConfigBroadcastOnStartResult();

      GetConfigBroadcastOnStartResult(bool broadcastOnStart);

      GetConfigBroadcastOnStartResult(CommandBasePtr relatedCommand, bool broadcastOnStart);

      static GetConfigBroadcastOnStartResultPtr create(bool broadcastOnStart);

      static GetConfigBroadcastOnStartResultPtr create(CommandBasePtr relatedCommand, bool broadcastOnStart);
      static GetConfigBroadcastOnStartResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** broadcastOnStart ****
      bool broadcastOnStart() const;
      void setBroadcastOnStart(bool broadcastOnStart);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetConfigBroadcastOnStartResult);
  }
}

