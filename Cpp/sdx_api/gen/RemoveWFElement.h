#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Remove last Wavefront element.
    ///
    /// 
    ///

    class RemoveWFElement;
    typedef std::shared_ptr<RemoveWFElement> RemoveWFElementPtr;
    
    
    class RemoveWFElement : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      RemoveWFElement();

      static RemoveWFElementPtr create();
      static RemoveWFElementPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

