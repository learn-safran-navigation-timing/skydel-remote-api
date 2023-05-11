#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Remove a modulation target.
    ///
    /// Name Type   Description
    /// ---- ------ -----------------
    /// Id   string Target identifier
    ///

    class RemoveModulationTarget;
    typedef std::shared_ptr<RemoveModulationTarget> RemoveModulationTargetPtr;
    
    
    class RemoveModulationTarget : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      RemoveModulationTarget();

      RemoveModulationTarget(const std::string& id);

      static RemoveModulationTargetPtr create(const std::string& id);
      static RemoveModulationTargetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

