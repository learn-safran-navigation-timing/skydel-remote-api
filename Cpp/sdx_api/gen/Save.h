#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Save configuration.
    ///
    /// 
    ///

    class Save;
    typedef std::shared_ptr<Save> SavePtr;
    
    
    class Save : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      Save();

      static SavePtr create();
      static SavePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

