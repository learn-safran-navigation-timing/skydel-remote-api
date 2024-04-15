#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command RemoveAllPseudorangeRamp is deprecated since 21.3. You may use RemoveAllPseudorangeRampForSystem.
    /// 
    /// Remove all PSR Ramps for all satellites of the specified system.
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    ///

    class RemoveAllPseudorangeRamp;
    typedef std::shared_ptr<RemoveAllPseudorangeRamp> RemoveAllPseudorangeRampPtr;
    
    
    class RemoveAllPseudorangeRamp : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      RemoveAllPseudorangeRamp();

      RemoveAllPseudorangeRamp(const std::string& system);

      static RemoveAllPseudorangeRampPtr create(const std::string& system);
      static RemoveAllPseudorangeRampPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
    
  }
}

