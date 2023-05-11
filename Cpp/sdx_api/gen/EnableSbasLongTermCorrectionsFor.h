#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set whether ephemeris errors for this constellation should be compensated in SBAS long term corrections.
    ///
    /// Name      Type   Description
    /// --------- ------ -------------------------------------
    /// System    string As of today, only "GPS" is supported.
    /// IsEnabled bool   True if corrections are enabled.
    ///

    class EnableSbasLongTermCorrectionsFor;
    typedef std::shared_ptr<EnableSbasLongTermCorrectionsFor> EnableSbasLongTermCorrectionsForPtr;
    
    
    class EnableSbasLongTermCorrectionsFor : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnableSbasLongTermCorrectionsFor();

      EnableSbasLongTermCorrectionsFor(const std::string& system, bool isEnabled);

      static EnableSbasLongTermCorrectionsForPtr create(const std::string& system, bool isEnabled);
      static EnableSbasLongTermCorrectionsForPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** isEnabled ****
      bool isEnabled() const;
      void setIsEnabled(bool isEnabled);
    };
    
  }
}

