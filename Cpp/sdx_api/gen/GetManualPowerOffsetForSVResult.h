#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <map>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetManualPowerOffsetForSV.
    ///
    /// Name                  Type               Description
    /// --------------------- ------------------ -----------------------------------------------------------------------------
    /// System                string             "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR".
    /// SvId                  int                The satellite's SV ID.
    /// SignalPowerOffsetDict dict string:double A dictionary of signal poweroffset pairs.
    ///                                          Accepted keys are: "All", "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P",
    ///                                                             "L2ME", "L2MR", "L5", "G1", "G2", "E1", "E1PRS", "E5a",
    ///                                                             "E5b", "E6BC", "E6PRS", "B1", "B2", "B1C", "B2a", "B3I",
    ///                                                             "SBASL1", "SBASL5", "QZSSL1CA", "QZSSL1CB", "QZSSL1C",
    ///                                                             "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "QZSSL6",
    ///                                                             "NAVICL1", "NAVICL5", "NAVICS", "PULSARXL" and "PULSARX1"
    ///

    class GetManualPowerOffsetForSVResult;
    typedef std::shared_ptr<GetManualPowerOffsetForSVResult> GetManualPowerOffsetForSVResultPtr;
    
    
    class GetManualPowerOffsetForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetManualPowerOffsetForSVResult();

      GetManualPowerOffsetForSVResult(const std::string& system, int svId, const std::map<std::string, double>& signalPowerOffsetDict);

      GetManualPowerOffsetForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::map<std::string, double>& signalPowerOffsetDict);

      static GetManualPowerOffsetForSVResultPtr create(const std::string& system, int svId, const std::map<std::string, double>& signalPowerOffsetDict);

      static GetManualPowerOffsetForSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::map<std::string, double>& signalPowerOffsetDict);
      static GetManualPowerOffsetForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** signalPowerOffsetDict ****
      std::map<std::string, double> signalPowerOffsetDict() const;
      void setSignalPowerOffsetDict(const std::map<std::string, double>& signalPowerOffsetDict);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetManualPowerOffsetForSVResult);
  }
}

