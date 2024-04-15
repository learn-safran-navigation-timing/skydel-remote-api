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
    /// EndIntTxTrackDefinition Result with created track informations.
    ///
    /// Name  Type   Description
    /// ----- ------ ----------------------------------------------------------------------------------------------------
    /// Count int    Number of nodes in the track. The client can compare this value with the number of positions pushed.
    /// Id    string Transmitter unique identifier.
    ///

    class EndIntTxTrackDefinitionResult;
    typedef std::shared_ptr<EndIntTxTrackDefinitionResult> EndIntTxTrackDefinitionResultPtr;
    
    
    class EndIntTxTrackDefinitionResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EndIntTxTrackDefinitionResult();

      EndIntTxTrackDefinitionResult(int count, const std::string& id);

      EndIntTxTrackDefinitionResult(CommandBasePtr relatedCommand, int count, const std::string& id);

      static EndIntTxTrackDefinitionResultPtr create(int count, const std::string& id);

      static EndIntTxTrackDefinitionResultPtr create(CommandBasePtr relatedCommand, int count, const std::string& id);
      static EndIntTxTrackDefinitionResultPtr dynamicCast(CommandBasePtr ptr);
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
    REGISTER_COMMAND_TO_FACTORY_DECL(EndIntTxTrackDefinitionResult);
  }
}

