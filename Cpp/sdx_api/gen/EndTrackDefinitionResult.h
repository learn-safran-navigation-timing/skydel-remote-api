#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// EndTrackDefinition Result with created track informations.
    ///
    /// Name  Type Description
    /// ----- ---- ----------------------------------------------------------------------------------------------------
    /// Count int  Number of nodes in the track. The client can compare this value with the number of positions pushed.
    ///

    class EndTrackDefinitionResult;
    typedef std::shared_ptr<EndTrackDefinitionResult> EndTrackDefinitionResultPtr;
    
    
    class EndTrackDefinitionResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EndTrackDefinitionResult();

      EndTrackDefinitionResult(int count);

      EndTrackDefinitionResult(CommandBasePtr relatedCommand, int count);

      static EndTrackDefinitionResultPtr create(int count);

      static EndTrackDefinitionResultPtr create(CommandBasePtr relatedCommand, int count);
      static EndTrackDefinitionResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** count ****
      int count() const;
      void setCount(int count);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(EndTrackDefinitionResult);
  }
}

