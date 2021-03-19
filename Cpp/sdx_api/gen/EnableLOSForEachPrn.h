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
    /// Please note the command EnableLOSForEachPrn is deprecated since 21.3. You may use EnableLosForEachSV.
    /// 
    /// Set Direct Line Of Sight signal from satellite disabled or enabled. Generally used when only multipaths signal is visible.
    ///
    /// Name    Type       Description
    /// ------- ---------- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// System  string     "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Enabled array bool Direct Line of Sight enabled or not. Zero based index (index 0 => first PRN (Slot for GLONASS, SV ID for QSZZ and NavIC), index 1 => second PRN (Slot for GLONASS, SV ID for QSZZ), etc).
    ///

    class EnableLOSForEachPrn;
    typedef std::shared_ptr<EnableLOSForEachPrn> EnableLOSForEachPrnPtr;
    
    
    class EnableLOSForEachPrn : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnableLOSForEachPrn();

      EnableLOSForEachPrn(const std::string& system, const std::vector<bool>& enabled);
  
      static EnableLOSForEachPrnPtr create(const std::string& system, const std::vector<bool>& enabled);
      static EnableLOSForEachPrnPtr dynamicCast(CommandBasePtr ptr);
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

