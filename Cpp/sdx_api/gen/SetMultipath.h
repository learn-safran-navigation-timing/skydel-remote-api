#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetMultipath is deprecated since 21.3. You may use SetMultipathForSV.
    /// 
    /// Add or update signal echo (multipath). Offsets (power loss, pseudorange, Doppler and carrier phase) are all relative to line-of-sight signal.
    /// If Id is not set, or unknown to Skydel, a new echo will be added. Otherwise, existing echo will be updated.
    ///
    /// Name         Type   Description
    /// ------------ ------ -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Prn          int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS and SV ID for QZSS.
    /// System       string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Signal       string Allowed signal keys: "L1CA", "L1C", "L1P", "L1M", "L2C", "L2P", "L2M", "L5", "G1", "G2", "E1", "E5a", "E5b", "B1", "B2", "B1C", "B2a", "SBASL1", "QZSSL1CA", "QZSSL1C", "QZSSL5", "QZSSL1S", "QZSSL5S", "NAVICL5"
    /// PowerLoss    double Power loss in dB (value must be positive)
    /// Pseudorange  double Pseudorange offset in meters (value must be positive)
    /// Doppler      double Doppler frequency offset in Hz
    /// CarrierPhase double Carrier phase offset in radians
    /// Echo         int    Echo number [1..3], or use zero to let Skydel assign an echo number.
    /// Id           string Unique identifier.
    ///

    class SetMultipath;
    typedef std::shared_ptr<SetMultipath> SetMultipathPtr;
    
    
    class SetMultipath : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetMultipath();

      SetMultipath(int prn, const std::string& system, const std::string& signal, double powerLoss, double pseudorange, double doppler, double carrierPhase, int echo, const std::string& id);
  
      static SetMultipathPtr create(int prn, const std::string& system, const std::string& signal, double powerLoss, double pseudorange, double doppler, double carrierPhase, int echo, const std::string& id);
      static SetMultipathPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


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

