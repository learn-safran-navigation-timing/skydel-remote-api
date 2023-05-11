#pragma once

#include <memory>
#include "command_base.h"

#include <map>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the power offsets applied to the signals of a satellite. Use SV ID 0 to set the power offset of all the satellites. Use key "All" to set the power offset to all signals.
    ///
    /// Name                  Type               Description
    /// --------------------- ------------------ -----------------------------------------------------------------------------
    /// System                string             "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC".
    /// SvId                  int                The satellite's SV ID.
    /// SignalPowerOffsetDict dict string:double A dictionary of signal poweroffset pairs.
    ///                                          Accepted keys are: "All", "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P",
    ///                                                             "L2ME", "L2MR", "L5", "G1", "G2", "E1", "E1PRS", "E5a",
    ///                                                             "E5b", "E6BC", "E6PRS", "B1", "B2", "B1C", "B2a", "B3I",
    ///                                                             "SBASL1", "SBASL5", "QZSSL1CA", "QZSSL1CB", "QZSSL1C",
    ///                                                             "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S" and "NAVICL5"
    /// IsRelativePowerOffset bool               If true, the power offset(s) are added to the current value(s).
    ///

    class SetManualPowerOffsetForSV;
    typedef std::shared_ptr<SetManualPowerOffsetForSV> SetManualPowerOffsetForSVPtr;
    
    
    class SetManualPowerOffsetForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetManualPowerOffsetForSV();

      SetManualPowerOffsetForSV(const std::string& system, int svId, const std::map<std::string, double>& signalPowerOffsetDict, bool isRelativePowerOffset);

      static SetManualPowerOffsetForSVPtr create(const std::string& system, int svId, const std::map<std::string, double>& signalPowerOffsetDict, bool isRelativePowerOffset);
      static SetManualPowerOffsetForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** signalPowerOffsetDict ****
      std::map<std::string, double> signalPowerOffsetDict() const;
      void setSignalPowerOffsetDict(const std::map<std::string, double>& signalPowerOffsetDict);


      // **** isRelativePowerOffset ****
      bool isRelativePowerOffset() const;
      void setIsRelativePowerOffset(bool isRelativePowerOffset);
    };
    
  }
}

