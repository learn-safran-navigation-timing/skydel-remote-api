#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Begins a new spoofer transmitter track definition. Actual track remains unchanged until
    /// EndSpoofTxTrackDefinition command is sent and successful. After this command, the
    /// client must push time and position pairs to form a complete track. Once all the
    /// positions are sent, the client must send the command EndSpoofTxTrackDefinition.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class BeginSpoofTxTrackDefinition;
    typedef std::shared_ptr<BeginSpoofTxTrackDefinition> BeginSpoofTxTrackDefinitionPtr;
    
    
    class BeginSpoofTxTrackDefinition : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      BeginSpoofTxTrackDefinition();

      BeginSpoofTxTrackDefinition(const std::string& id);

      static BeginSpoofTxTrackDefinitionPtr create(const std::string& id);
      static BeginSpoofTxTrackDefinitionPtr dynamicCast(CommandBasePtr ptr);
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

