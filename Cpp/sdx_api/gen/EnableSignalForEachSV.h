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
    /// Enable (or disable) signal for each satellite individually.
    ///
    /// Name    Type       Description
    /// ------- ---------- --------------------------------------------------------------------------------------------------------------
    /// Signal  string     Accepted signal keys: "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME", "L2MR", "L5",
    ///                                          "G1", "G2", "E1", "E1PRS", "E5a", "E5b", "E6BC", "E6PRS",
    ///                                          "B1", "B2", "B1C", "B2a", "B3I", "SBASL1", "SBASL5", "QZSSL1CA",
    ///                                          "QZSSL1CB", "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "NAVICL5"
    /// Enabled array bool Signal is enabled when value is True. Zero based index (index 0 => first SV ID, index 1 => second SV ID, etc).
    ///

    class EnableSignalForEachSV;
    typedef std::shared_ptr<EnableSignalForEachSV> EnableSignalForEachSVPtr;
    
    
    class EnableSignalForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnableSignalForEachSV();

      EnableSignalForEachSV(const std::string& signal, const std::vector<bool>& enabled);

      static EnableSignalForEachSVPtr create(const std::string& signal, const std::vector<bool>& enabled);
      static EnableSignalForEachSVPtr dynamicCast(CommandBasePtr ptr);
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

