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
    /// Please note the command EnableSignalForEachPrn is deprecated since 21.3. You may use EnableSignalForEachSV.
    /// 
    /// Enable (or disable) signal for each satellite individually.
    /// Allowed signal keys: "L1CA", "L1C", "L1P", "L1M", "L2C", "L2P", "L2M", "L5",
    ///                      "G1", "G2", "E1", "E5a", "E5b", "B1", "B2", "B1C", "B2a",
    ///                      "SBASL1", "QZSSL1CA", "QZSSL1C", "QZSSL5", "QZSSL1S", "QZSSL5S",
    ///                      "NAVICL5"
    ///
    /// Name    Type       Description
    /// ------- ---------- ----------------------------------------------------------------------------------------------------------
    /// Signal  string     Signal key - see command description for possible values
    /// Enabled array bool Signal is enabled when value is True. Zero based index (index 0 => first PRN, index 1 => second PRN, etc).
    ///

    class EnableSignalForEachPrn;
    typedef std::shared_ptr<EnableSignalForEachPrn> EnableSignalForEachPrnPtr;
    
    
    class EnableSignalForEachPrn : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnableSignalForEachPrn();

      EnableSignalForEachPrn(const std::string& signal, const std::vector<bool>& enabled);
  
      static EnableSignalForEachPrnPtr create(const std::string& signal, const std::vector<bool>& enabled);
      static EnableSignalForEachPrnPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** enabled ****
      std::vector<bool> enabled() const;
      void setEnabled(const std::vector<bool>& enabled);
    };
  }
}

