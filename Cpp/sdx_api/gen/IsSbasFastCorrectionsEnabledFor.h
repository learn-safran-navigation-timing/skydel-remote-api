#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get whether pseudorange errors for this constellation should be compensated in SBAS fast corrections
    ///
    /// Name   Type   Description
    /// ------ ------ ---------------
    /// System string "GPS" or "SBAS"
    ///

    class IsSbasFastCorrectionsEnabledFor;
    typedef std::shared_ptr<IsSbasFastCorrectionsEnabledFor> IsSbasFastCorrectionsEnabledForPtr;
    
    
    class IsSbasFastCorrectionsEnabledFor : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSbasFastCorrectionsEnabledFor();

      IsSbasFastCorrectionsEnabledFor(const std::string& system);
  
      static IsSbasFastCorrectionsEnabledForPtr create(const std::string& system);
      static IsSbasFastCorrectionsEnabledForPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
  }
}

