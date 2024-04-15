#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get all Plug-ins present on the system (regardless of state).
    ///
    /// 
    ///

    class GetPlugins;
    typedef std::shared_ptr<GetPlugins> GetPluginsPtr;
    
    
    class GetPlugins : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetPlugins();

      static GetPluginsPtr create();
      static GetPluginsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

