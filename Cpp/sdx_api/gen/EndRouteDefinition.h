#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// This command completes the route started with BeginRouteDefinition command. If
    /// the route is accepted, the current route in the configuration is replaced with
    /// this new route. If the route is not accepted, the current route in the config
    /// remains unchanged.
    ///
    /// 
    ///

    class EndRouteDefinition;
    typedef std::shared_ptr<EndRouteDefinition> EndRouteDefinitionPtr;
    
    
    class EndRouteDefinition : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EndRouteDefinition();

      static EndRouteDefinitionPtr create();
      static EndRouteDefinitionPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

