#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Removes a PSR ramp events. When adding an event, the simulator
    /// sets the Id parameter. Use that Id here to remove the associated ramp.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Id     string Unique identifier of the PSR ramp to remove.
    ///

    class RemovePseudorangeRamp;
    typedef std::shared_ptr<RemovePseudorangeRamp> RemovePseudorangeRampPtr;
    
    
    class RemovePseudorangeRamp : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      RemovePseudorangeRamp();

      RemovePseudorangeRamp(const std::string& system, const std::string& id);

      static RemovePseudorangeRampPtr create(const std::string& system, const std::string& id);
      static RemovePseudorangeRampPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

