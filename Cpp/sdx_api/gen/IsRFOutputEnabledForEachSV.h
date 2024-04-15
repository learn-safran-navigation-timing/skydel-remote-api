#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Tells if the RF output is enabled or disabled for each satellite.
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    ///

    class IsRFOutputEnabledForEachSV;
    typedef std::shared_ptr<IsRFOutputEnabledForEachSV> IsRFOutputEnabledForEachSVPtr;
    
    
    class IsRFOutputEnabledForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsRFOutputEnabledForEachSV();

      IsRFOutputEnabledForEachSV(const std::string& system);

      static IsRFOutputEnabledForEachSVPtr create(const std::string& system);
      static IsRFOutputEnabledForEachSVPtr dynamicCast(CommandBasePtr ptr);
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

