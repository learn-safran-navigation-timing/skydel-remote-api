#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// This command completes the track started with BeginIntTxTrackDefinition command. If
    /// the track is accepted, the current track in the configuration is replaced with
    /// this new track. If the track is not accepted, the current track in the config
    /// remains unchanged.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class EndIntTxTrackDefinition;
    typedef std::shared_ptr<EndIntTxTrackDefinition> EndIntTxTrackDefinitionPtr;
    
    
    class EndIntTxTrackDefinition : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EndIntTxTrackDefinition();

      EndIntTxTrackDefinition(const std::string& id);

      static EndIntTxTrackDefinitionPtr create(const std::string& id);
      static EndIntTxTrackDefinitionPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

