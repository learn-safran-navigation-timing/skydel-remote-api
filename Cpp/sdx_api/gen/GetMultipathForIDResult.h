#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetMultipathForID.
    ///
    /// Name         Type   Description
    /// ------------ ------ -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Id           string A multipath ID
    /// System       string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// Signal       string Accepted signal keys: "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME", "L2MR", "L5", "G1", "G2", "E1", "E5a", "E5b", "B1", "B2", "B1C", "B2a", "B3I", "SBASL1", "QZSSL1CA", "QZSSL1CB", "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "QZSSL6", "NAVICL1", "NAVICL5", "NAVICS", "PULSARXL"
    /// SvId         int    The satellite's SV ID
    /// PowerLoss    double Power loss in dB (value must be positive)
    /// Pseudorange  double Pseudorange offset in meters (value must be positive)
    /// Doppler      double Doppler frequency offset in Hz
    /// CarrierPhase double Carrier phase offset in radians
    /// Echo         int    Echo number [1..5], or use zero to let Skydel assign an echo number.
    ///

    class GetMultipathForIDResult;
    typedef std::shared_ptr<GetMultipathForIDResult> GetMultipathForIDResultPtr;
    
    
    class GetMultipathForIDResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetMultipathForIDResult();

      GetMultipathForIDResult(const std::string& id, const std::string& system, const std::string& signal, int svId, double powerLoss, double pseudorange, double doppler, double carrierPhase, int echo);

      GetMultipathForIDResult(CommandBasePtr relatedCommand, const std::string& id, const std::string& system, const std::string& signal, int svId, double powerLoss, double pseudorange, double doppler, double carrierPhase, int echo);

      static GetMultipathForIDResultPtr create(const std::string& id, const std::string& system, const std::string& signal, int svId, double powerLoss, double pseudorange, double doppler, double carrierPhase, int echo);

      static GetMultipathForIDResultPtr create(CommandBasePtr relatedCommand, const std::string& id, const std::string& system, const std::string& signal, int svId, double powerLoss, double pseudorange, double doppler, double carrierPhase, int echo);
      static GetMultipathForIDResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** powerLoss ****
      double powerLoss() const;
      void setPowerLoss(double powerLoss);


      // **** pseudorange ****
      double pseudorange() const;
      void setPseudorange(double pseudorange);


      // **** doppler ****
      double doppler() const;
      void setDoppler(double doppler);


      // **** carrierPhase ****
      double carrierPhase() const;
      void setCarrierPhase(double carrierPhase);


      // **** echo ****
      int echo() const;
      void setEcho(int echo);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetMultipathForIDResult);
  }
}

