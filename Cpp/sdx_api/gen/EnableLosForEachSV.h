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
    /// Set Direct Line Of Sight signal from satellite disabled or enabled. Generally used when only multipaths signal is visible.
    ///
    /// Name    Type       Description
    /// ------- ---------- -----------------------------------------------------------------------------------------------------------
    /// System  string     "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Enabled array bool Direct Line of Sight enabled or not. Zero based index (index 0 => SV ID 1, index 1 => second SV ID 2, etc).
    ///

    class EnableLosForEachSV;
    typedef std::shared_ptr<EnableLosForEachSV> EnableLosForEachSVPtr;
    
    
    class EnableLosForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnableLosForEachSV();

      EnableLosForEachSV(const std::string& system, const std::vector<bool>& enabled);

      static EnableLosForEachSVPtr create(const std::string& system, const std::vector<bool>& enabled);
      static EnableLosForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

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

