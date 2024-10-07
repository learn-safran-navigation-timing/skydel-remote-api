#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Add or update signal echo (multipath). Offsets (power loss, pseudorange, Doppler and carrier phase) are all relative to line-of-sight signal.
    /// If Id is not set, or unknown to Skydel, a new echo will be added. Otherwise, existing echo will be updated.
    ///
    /// Name         Type   Description
    /// ------------ ------ -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Signal       string Accepted signal keys: "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME", "L2MR", "L5", "G1", "G2", "E1", "E5a", "E5b", "B1", "B2", "B1C", "B2a", "B3I", "SBASL1", "QZSSL1CA", "QZSSL1CB", "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "QZSSL6", "NAVICL1", "NAVICL5", "NAVICS", "PULSARXL"
    /// SvId         int    The satellite's SV ID
    /// PowerLoss    double Power loss in dB (value must be positive)
    /// Pseudorange  double Pseudorange offset in meters (value must be positive)
    /// Doppler      double Doppler frequency offset in Hz
    /// CarrierPhase double Carrier phase offset in radians
    /// Echo         int    Echo number [1..5], or use zero to let Skydel assign an echo number.
    /// Id           string Unique identifier.
    ///

    class SetMultipathForSV;
    typedef std::shared_ptr<SetMultipathForSV> SetMultipathForSVPtr;
    
    
    class SetMultipathForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetMultipathForSV();

      SetMultipathForSV(const std::string& signal, int svId, double powerLoss, double pseudorange, double doppler, double carrierPhase, int echo, const std::string& id);

      static SetMultipathForSVPtr create(const std::string& signal, int svId, double powerLoss, double pseudorange, double doppler, double carrierPhase, int echo, const std::string& id);
      static SetMultipathForSVPtr dynamicCast(CommandBasePtr ptr);
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


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

