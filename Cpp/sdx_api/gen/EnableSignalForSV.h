#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable (or disable) signal for specified satellite.
    ///
    /// Name    Type   Description
    /// ------- ------ -------------------------------------------------------------------------------------------------------------
    /// Signal  string Accepted signal keys: "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME", "L2MR", "L5",
    ///                                      "G1", "G2", "E1", "E1PRS", "E5a", "E5b", "E6BC", "E6PRS",
    ///                                      "B1", "B2", "B1C", "B2a", "B3I", "SBASL1", "SBASL5", "QZSSL1CA", "QZSSL1CB", "QZSSL1C",
    ///                                      "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "QZSSL6", "NAVICL1", "NAVICL5", "NAVICS",
    ///                                      "PULSARXL", "PULSARX1", "PULSARX5"
    /// SvId    int    The satellite's SV ID (use 0 for all constellation's satellites)
    /// Enabled bool   Signal is enabled when value is True
    ///

    class EnableSignalForSV;
    typedef std::shared_ptr<EnableSignalForSV> EnableSignalForSVPtr;
    
    
    class EnableSignalForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EnableSignalForSV();

      EnableSignalForSV(const std::string& signal, int svId, bool enabled);

      static EnableSignalForSVPtr create(const std::string& signal, int svId, bool enabled);
      static EnableSignalForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

