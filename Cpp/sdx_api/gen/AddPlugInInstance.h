#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Add a plug-in instance of specified type.
    ///
    /// Name Type   Description
    /// ---- ------ -------------------------------------
    /// Name string Unique name for the plug-in instance.
    /// Type string Type of the plug-in instance.
    ///

    class AddPlugInInstance;
    typedef std::shared_ptr<AddPlugInInstance> AddPlugInInstancePtr;
    
    
    class AddPlugInInstance : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      AddPlugInInstance();

      AddPlugInInstance(const std::string& name, const std::string& type);

      static AddPlugInInstancePtr create(const std::string& name, const std::string& type);
      static AddPlugInInstancePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** name ****
      std::string name() const;
      void setName(const std::string& name);


      // **** type ****
      std::string type() const;
      void setType(const std::string& type);
    };
    
  }
}

