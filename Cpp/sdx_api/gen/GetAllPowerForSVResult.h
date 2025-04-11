#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "gen/SignalPower.h"
#include <map>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetAllPowerForSV.
    ///
    /// Name            Type                    Description
    /// --------------- ----------------------- -----------------------------------------------------------------------------
    /// System          string                  "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR".
    /// SvId            int                     The Satellite's SV ID.
    /// NominalPower    double                  The nominal power in dBm.
    /// GlobalOffset    double                  The global power offset (dB).
    /// SignalPowerDict dict string:SignalPower A dictionary of signal power pairs.
    ///                                         Accepted keys are: "All", "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P",
    ///                                                            "L2ME", "L2MR", "L5", "G1", "G2", "E1", "E1PRS", "E5a",
    ///                                                            "E5b", "E6BC", "E6PRS", "B1", "B2", "B1C", "B2a", "B3I",
    ///                                                            "SBASL1", "SBASL5", "QZSSL1CA", "QZSSL1CB", "QZSSL1C",
    ///                                                            "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "QZSSL6",
    ///                                                            "NAVICL1", "NAVICL5", "NAVICS", "PULSARXL", "PULSARX1" and
    ///                                                            "PULSARX5"
    ///

    class GetAllPowerForSVResult;
    typedef std::shared_ptr<GetAllPowerForSVResult> GetAllPowerForSVResultPtr;
    
    
    class GetAllPowerForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetAllPowerForSVResult();

      GetAllPowerForSVResult(const std::string& system, int svId, double nominalPower, double globalOffset, const std::map<std::string, Sdx::SignalPower>& signalPowerDict);

      GetAllPowerForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, double nominalPower, double globalOffset, const std::map<std::string, Sdx::SignalPower>& signalPowerDict);

      static GetAllPowerForSVResultPtr create(const std::string& system, int svId, double nominalPower, double globalOffset, const std::map<std::string, Sdx::SignalPower>& signalPowerDict);

      static GetAllPowerForSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, double nominalPower, double globalOffset, const std::map<std::string, Sdx::SignalPower>& signalPowerDict);
      static GetAllPowerForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** nominalPower ****
      double nominalPower() const;
      void setNominalPower(double nominalPower);


      // **** globalOffset ****
      double globalOffset() const;
      void setGlobalOffset(double globalOffset);


      // **** signalPowerDict ****
      std::map<std::string, Sdx::SignalPower> signalPowerDict() const;
      void setSignalPowerDict(const std::map<std::string, Sdx::SignalPower>& signalPowerDict);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetAllPowerForSVResult);
  }
}

