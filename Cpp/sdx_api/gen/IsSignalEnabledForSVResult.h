#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsSignalEnabledForSV
    ///
    /// Name    Type   Description
    /// ------- ------ -------------------------------------------------------------------------------
    /// Signal  string Accepted signal keys: "L1CA", "L1C", "L1P", "L1M", "L2C", "L2P", "L2M", "L5",
    ///                                      "G1", "G2", "E1", "E1PRS", "E5a", "E5b", "E6BC", "E6PRS",
    ///                                      "B1", "B2", "B1C", "B2a", "SBASL1", "SBASL5", "QZSSL1CA"
    ///                                      "QZSSL1C", "QZSSL5", "QZSSL1S", "QZSSL5S", "NAVICL5"
    /// SvId    int    The satellite's SV ID (use 0 for all constellation's satellites)
    /// Enabled bool   Signal is enabled when value is True
    ///

    class IsSignalEnabledForSVResult;
    typedef std::shared_ptr<IsSignalEnabledForSVResult> IsSignalEnabledForSVResultPtr;
    
    
    class IsSignalEnabledForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSignalEnabledForSVResult();

      IsSignalEnabledForSVResult(CommandBasePtr relatedCommand, const std::string& signal, int svId, bool enabled);
  
      static IsSignalEnabledForSVResultPtr create(CommandBasePtr relatedCommand, const std::string& signal, int svId, bool enabled);
      static IsSignalEnabledForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


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

