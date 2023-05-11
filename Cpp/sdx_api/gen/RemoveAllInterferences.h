#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Clear all interferences
    ///
    /// 
    ///

    class RemoveAllInterferences;
    typedef std::shared_ptr<RemoveAllInterferences> RemoveAllInterferencesPtr;
    
    
    class RemoveAllInterferences : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      RemoveAllInterferences();

      static RemoveAllInterferencesPtr create();
      static RemoveAllInterferencesPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

