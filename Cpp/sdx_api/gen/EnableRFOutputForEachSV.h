#pragma once

#include <memory>
#include "command_base.h"

#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable (or disable) RF output for each satellite individually.
    ///
    /// Name    Type       Description
    /// ------- ---------- -------------------------------------------------------------------------------------------------
    /// System  string     "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// Enabled array bool RF is enabled when value is True. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc).
    ///

    class EnableRFOutputForEachSV;
    typedef std::shared_ptr<EnableRFOutputForEachSV> EnableRFOutputForEachSVPtr;
    
    
    class EnableRFOutputForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EnableRFOutputForEachSV();

      EnableRFOutputForEachSV(const std::string& system, const std::vector<bool>& enabled);

      static EnableRFOutputForEachSVPtr create(const std::string& system, const std::vector<bool>& enabled);
      static EnableRFOutputForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** enabled ****
      std::vector<bool> enabled() const;
      void setEnabled(const std::vector<bool>& enabled);
    };
    
  }
}

