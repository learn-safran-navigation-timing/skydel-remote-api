#pragma once

#include <memory>
#include "command_base.h"

#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Group multiple commands as one
    ///
    /// Name     Type               Description
    /// -------- ------------------ -----------------------
    /// Commands array command_base The commands to execute
    ///

    class CommandGroup;
    typedef std::shared_ptr<CommandGroup> CommandGroupPtr;
    
    
    class CommandGroup : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      CommandGroup();

      CommandGroup(const std::vector<Sdx::CommandBasePtr>& commands);

      static CommandGroupPtr create(const std::vector<Sdx::CommandBasePtr>& commands);
      static CommandGroupPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** commands ****
      std::vector<Sdx::CommandBasePtr> commands() const;
      void setCommands(const std::vector<Sdx::CommandBasePtr>& commands);
    };
    
  }
}

