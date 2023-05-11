#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get Direct Line Of Sight signal from satellite disabled or enabled. Generally used when only multipaths signal is visible.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    ///

    class IsLOSEnabledForEachSV;
    typedef std::shared_ptr<IsLOSEnabledForEachSV> IsLOSEnabledForEachSVPtr;
    
    
    class IsLOSEnabledForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsLOSEnabledForEachSV();

      IsLOSEnabledForEachSV(const std::string& system);

      static IsLOSEnabledForEachSVPtr create(const std::string& system);
      static IsLOSEnabledForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
    
  }
}

