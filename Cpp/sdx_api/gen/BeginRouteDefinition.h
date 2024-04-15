#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Begins a new route definition. Actual route remains unchanged until
    /// EndRouteDefinition command is sent and successful. After this command, the
    /// client must push time and position pairs to form a complete route. Once all the
    /// positions are sent, the client must send the command EndRouteDefinition.
    ///
    /// 
    ///

    class BeginRouteDefinition;
    typedef std::shared_ptr<BeginRouteDefinition> BeginRouteDefinitionPtr;
    
    
    class BeginRouteDefinition : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      BeginRouteDefinition();

      static BeginRouteDefinitionPtr create();
      static BeginRouteDefinitionPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

