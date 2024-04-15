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
    /// Enable or disable each satellite for this constellation.
    ///
    /// Name    Type       Description
    /// ------- ---------- ----------------------------------------------------------------------------------------------------------------
    /// System  string     The satellites' constellation. Can be "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// Enabled array bool Array of present/absent flags for the constellation
    ///

    class EnableEachSV;
    typedef std::shared_ptr<EnableEachSV> EnableEachSVPtr;
    
    
    class EnableEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EnableEachSV();

      EnableEachSV(const std::string& system, const std::vector<bool>& enabled);

      static EnableEachSVPtr create(const std::string& system, const std::vector<bool>& enabled);
      static EnableEachSVPtr dynamicCast(CommandBasePtr ptr);
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

