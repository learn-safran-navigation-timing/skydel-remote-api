#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Tells if the propagation delay is enabled.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    ///

    class IsPropagationDelayEnabled;
    typedef std::shared_ptr<IsPropagationDelayEnabled> IsPropagationDelayEnabledPtr;
    
    
    class IsPropagationDelayEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsPropagationDelayEnabled();

      IsPropagationDelayEnabled(const std::string& system);

      static IsPropagationDelayEnabledPtr create(const std::string& system);
      static IsPropagationDelayEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
    
  }
}

