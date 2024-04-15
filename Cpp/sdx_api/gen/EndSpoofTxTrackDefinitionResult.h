#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// EndSpoofTxTrackDefinition Result with created track informations.
    ///
    /// Name  Type   Description
    /// ----- ------ ----------------------------------------------------------------------------------------------------
    /// Count int    Number of nodes in the track. The client can compare this value with the number of positions pushed.
    /// Id    string Transmitter unique identifier.
    ///

    class EndSpoofTxTrackDefinitionResult;
    typedef std::shared_ptr<EndSpoofTxTrackDefinitionResult> EndSpoofTxTrackDefinitionResultPtr;
    
    
    class EndSpoofTxTrackDefinitionResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EndSpoofTxTrackDefinitionResult();

      EndSpoofTxTrackDefinitionResult(int count, const std::string& id);

      EndSpoofTxTrackDefinitionResult(CommandBasePtr relatedCommand, int count, const std::string& id);

      static EndSpoofTxTrackDefinitionResultPtr create(int count, const std::string& id);

      static EndSpoofTxTrackDefinitionResultPtr create(CommandBasePtr relatedCommand, int count, const std::string& id);
      static EndSpoofTxTrackDefinitionResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** count ****
      int count() const;
      void setCount(int count);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(EndSpoofTxTrackDefinitionResult);
  }
}

