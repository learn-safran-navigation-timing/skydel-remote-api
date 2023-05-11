#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Begins a new track definition. Actual track remains unchanged until
    /// EndTrackDefinition command is sent and successful. After this command, the
    /// client must push time and position pairs to form a complete track. Once all the
    /// positions are sent, the client must send the command EndTrackDefinition.
    ///
    /// 
    ///

    class BeginTrackDefinition;
    typedef std::shared_ptr<BeginTrackDefinition> BeginTrackDefinitionPtr;
    
    
    class BeginTrackDefinition : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      BeginTrackDefinition();

      static BeginTrackDefinitionPtr create();
      static BeginTrackDefinitionPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

