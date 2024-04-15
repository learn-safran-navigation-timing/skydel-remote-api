#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get all multipath ID for the specified constellation.
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    ///

    class GetAllMultipathForSystem;
    typedef std::shared_ptr<GetAllMultipathForSystem> GetAllMultipathForSystemPtr;
    
    
    class GetAllMultipathForSystem : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetAllMultipathForSystem();

      GetAllMultipathForSystem(const std::string& system);

      static GetAllMultipathForSystemPtr create(const std::string& system);
      static GetAllMultipathForSystemPtr dynamicCast(CommandBasePtr ptr);
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

