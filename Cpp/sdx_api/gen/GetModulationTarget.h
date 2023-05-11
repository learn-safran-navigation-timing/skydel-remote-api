#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get a modulation target.
    /// If Id is not set, or if new, a new target is added.
    /// For setter : If the Id is already used, the corresponding target is updated.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------------------------
    /// Id   string Unique identifier automatically set by simulator
    ///

    class GetModulationTarget;
    typedef std::shared_ptr<GetModulationTarget> GetModulationTargetPtr;
    
    
    class GetModulationTarget : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetModulationTarget();

      GetModulationTarget(const std::string& id);

      static GetModulationTargetPtr create(const std::string& id);
      static GetModulationTargetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

