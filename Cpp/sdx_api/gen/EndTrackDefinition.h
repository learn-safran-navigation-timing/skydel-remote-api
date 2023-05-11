#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// This command completes the track started with BeginTrackDefinition command. If
    /// the track is accepted, the current track in the configuration is replaced with
    /// this new track. If the track is not accepted, the current track in the config
    /// remains unchanged.
    ///
    /// 
    ///

    class EndTrackDefinition;
    typedef std::shared_ptr<EndTrackDefinition> EndTrackDefinitionPtr;
    
    
    class EndTrackDefinition : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EndTrackDefinition();

      static EndTrackDefinitionPtr create();
      static EndTrackDefinitionPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

