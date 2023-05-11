#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get whether ephemeris errors for this constellation should be compensated in SBAS long term corrections.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------
    /// System string As of today, only "GPS" is supported.
    ///

    class IsSbasLongTermCorrectionsEnabledFor;
    typedef std::shared_ptr<IsSbasLongTermCorrectionsEnabledFor> IsSbasLongTermCorrectionsEnabledForPtr;
    
    
    class IsSbasLongTermCorrectionsEnabledFor : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSbasLongTermCorrectionsEnabledFor();

      IsSbasLongTermCorrectionsEnabledFor(const std::string& system);

      static IsSbasLongTermCorrectionsEnabledForPtr create(const std::string& system);
      static IsSbasLongTermCorrectionsEnabledForPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
    
  }
}

