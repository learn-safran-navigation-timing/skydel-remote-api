#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable (or disable) the satellite signal propagation delay. If disabled, the signal is immediately received
    /// by the receiver. The delay should always be enabled, unless your are doing a PPS calibration for the simulator.
    ///
    /// Name    Type   Description
    /// ------- ------ -------------------------------------------------------------------------------------------------
    /// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Enabled bool   If false, the propagation delay between the GPS satellite and the receiver is forced to 0 second.
    ///

    class SetPropagationDelay;
    typedef std::shared_ptr<SetPropagationDelay> SetPropagationDelayPtr;
    
    
    class SetPropagationDelay : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetPropagationDelay();

      SetPropagationDelay(const std::string& system, bool enabled);

      static SetPropagationDelayPtr create(const std::string& system, bool enabled);
      static SetPropagationDelayPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

