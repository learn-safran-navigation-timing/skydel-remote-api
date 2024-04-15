#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// This command completes the track started with the BeginSpoofTxTrackDefinition command. If
    /// the track is accepted, the current track in the configuration is replaced with
    /// this new track. If the track is not accepted, the current track in the config
    /// remains unchanged.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class EndSpoofTxTrackDefinition;
    typedef std::shared_ptr<EndSpoofTxTrackDefinition> EndSpoofTxTrackDefinitionPtr;
    
    
    class EndSpoofTxTrackDefinition : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EndSpoofTxTrackDefinition();

      EndSpoofTxTrackDefinition(const std::string& id);

      static EndSpoofTxTrackDefinitionPtr create(const std::string& id);
      static EndSpoofTxTrackDefinitionPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

