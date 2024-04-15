#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Begins a new interference track definition. Actual track remains unchanged until
    /// EndIntTxTrackDefinition command is sent and successful. After this command, the
    /// client must push time and position pairs to form a complete track. Once all the
    /// positions are sent, the client must send the command EndIntTxTrackDefinition.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class BeginIntTxTrackDefinition;
    typedef std::shared_ptr<BeginIntTxTrackDefinition> BeginIntTxTrackDefinitionPtr;
    
    
    class BeginIntTxTrackDefinition : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      BeginIntTxTrackDefinition();

      BeginIntTxTrackDefinition(const std::string& id);

      static BeginIntTxTrackDefinitionPtr create(const std::string& id);
      static BeginIntTxTrackDefinitionPtr dynamicCast(CommandBasePtr ptr);
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

