#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetPlugInInstance.
    ///
    /// Name Type   Description
    /// ---- ------ -------------------------------------
    /// Name string Unique name for the plug-in instance.
    /// Type string Type of the plug-in instance.
    ///

    class GetPlugInInstanceResult;
    typedef std::shared_ptr<GetPlugInInstanceResult> GetPlugInInstanceResultPtr;
    
    
    class GetPlugInInstanceResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPlugInInstanceResult();

      GetPlugInInstanceResult(CommandBasePtr relatedCommand, const std::string& name, const std::string& type);
  
      static GetPlugInInstanceResultPtr create(CommandBasePtr relatedCommand, const std::string& name, const std::string& type);
      static GetPlugInInstanceResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** name ****
      std::string name() const;
      void setName(const std::string& name);


      // **** type ****
      std::string type() const;
      void setType(const std::string& type);
    };
  }
}

