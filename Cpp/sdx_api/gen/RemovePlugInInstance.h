#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Removes the plug-in instance.
    ///
    /// Name Type   Description
    /// ---- ------ -----------------------------
    /// Name string Plug-in instance unique name.
    ///

    class RemovePlugInInstance;
    typedef std::shared_ptr<RemovePlugInInstance> RemovePlugInInstancePtr;
    
    
    class RemovePlugInInstance : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      RemovePlugInInstance();

      RemovePlugInInstance(const std::string& name);

      static RemovePlugInInstancePtr create(const std::string& name);
      static RemovePlugInInstancePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** name ****
      std::string name() const;
      void setName(const std::string& name);
    };
    
  }
}

