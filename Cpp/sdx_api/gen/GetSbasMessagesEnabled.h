#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the enabled SBAS messages. Message 63 is always enabled
    ///
    /// 
    ///

    class GetSbasMessagesEnabled;
    typedef std::shared_ptr<GetSbasMessagesEnabled> GetSbasMessagesEnabledPtr;
    
    
    class GetSbasMessagesEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSbasMessagesEnabled();

      static GetSbasMessagesEnabledPtr create();
      static GetSbasMessagesEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

