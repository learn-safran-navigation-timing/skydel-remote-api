#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get whether each satellite is enabled or disabled for this constellation.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------------------------------------------------------
    /// System string The satellites' constellation. Can be "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    ///

    class IsEachSVEnabled;
    typedef std::shared_ptr<IsEachSVEnabled> IsEachSVEnabledPtr;
    
    
    class IsEachSVEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsEachSVEnabled();

      IsEachSVEnabled(const std::string& system);

      static IsEachSVEnabledPtr create(const std::string& system);
      static IsEachSVEnabledPtr dynamicCast(CommandBasePtr ptr);
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

