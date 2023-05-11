#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// EndRouteDefinition Result with created route informations.
    ///
    /// Name  Type Description
    /// ----- ---- ----------------------------------------------------------------------------------------------------
    /// Count int  Number of nodes in the route. The client can compare this value with the number of positions pushed.
    ///

    class EndRouteDefinitionResult;
    typedef std::shared_ptr<EndRouteDefinitionResult> EndRouteDefinitionResultPtr;
    
    
    class EndRouteDefinitionResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EndRouteDefinitionResult();

      EndRouteDefinitionResult(int count);

      EndRouteDefinitionResult(CommandBasePtr relatedCommand, int count);

      static EndRouteDefinitionResultPtr create(int count);

      static EndRouteDefinitionResultPtr create(CommandBasePtr relatedCommand, int count);
      static EndRouteDefinitionResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** count ****
      int count() const;
      void setCount(int count);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(EndRouteDefinitionResult);
  }
}

