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
    /// Please note the command EnableRFForEachPrn is deprecated since 21.3. You may use EnableRFOutputForEachSV.
    /// 
    /// Enable (or disable) RF for each satellite individually.
    ///
    /// Name    Type       Description
    /// ------- ---------- ------------------------------------------------------------------------------------------------------
    /// System  string     "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Enabled array bool RF is enabled when value is True. Zero based index (index 0 => first PRN, index 1 => second PRN, etc).
    ///

    class EnableRFForEachPrn;
    typedef std::shared_ptr<EnableRFForEachPrn> EnableRFForEachPrnPtr;
    
    
    class EnableRFForEachPrn : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnableRFForEachPrn();

      EnableRFForEachPrn(const std::string& system, const std::vector<bool>& enabled);
  
      static EnableRFForEachPrnPtr create(const std::string& system, const std::vector<bool>& enabled);
      static EnableRFForEachPrnPtr dynamicCast(CommandBasePtr ptr);
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

