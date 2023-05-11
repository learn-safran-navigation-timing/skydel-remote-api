#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Disable all multipath for the specified constellation.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Reset  bool   Reset attributes (PSR offset, power loss, Doppler shift and carrier phase offset are set to zero)
    ///

    class RemoveAllMultipathForSystem;
    typedef std::shared_ptr<RemoveAllMultipathForSystem> RemoveAllMultipathForSystemPtr;
    
    
    class RemoveAllMultipathForSystem : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      RemoveAllMultipathForSystem();

      RemoveAllMultipathForSystem(const std::string& system, bool reset);

      static RemoveAllMultipathForSystemPtr create(const std::string& system, bool reset);
      static RemoveAllMultipathForSystemPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** reset ****
      bool reset() const;
      void setReset(bool reset);
    };
    
  }
}

