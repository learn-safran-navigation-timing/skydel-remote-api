#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get Add a plug-in instance of specified type.
    ///
    /// 
    ///

    class GetPlugInInstance;
    typedef std::shared_ptr<GetPlugInInstance> GetPlugInInstancePtr;
    
    
    class GetPlugInInstance : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPlugInInstance();
  
      static GetPlugInInstancePtr create();
      static GetPlugInInstancePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
  }
}

