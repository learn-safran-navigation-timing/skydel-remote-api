#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Sends a command to a plug-in instance.
    ///
    /// Name    Type   Description
    /// ------- ------ --------------------------------------------------
    /// Name    string Plug-in instance unique name.
    /// Command string The command to be handled by the plug-in instance.
    ///

    class PlugInCommand;
    typedef std::shared_ptr<PlugInCommand> PlugInCommandPtr;
    
    
    class PlugInCommand : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      PlugInCommand();

      PlugInCommand(const std::string& name, const std::string& command);

      static PlugInCommandPtr create(const std::string& name, const std::string& command);
      static PlugInCommandPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** name ****
      std::string name() const;
      void setName(const std::string& name);


      // **** command ****
      std::string command() const;
      void setCommand(const std::string& command);
    };
    
  }
}

