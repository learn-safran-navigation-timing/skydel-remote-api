#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSatellitePower.
    ///
    /// Name                Type   Description
    /// ------------------- ------ --------------------------------------------------------------------------------------------------------
    /// NominalPower        double The nominal power in dBm
    /// SignalStrengthModel double The power difference coming from the Signal Strength Model (dB)
    /// Antenna             double The receiver antenna power offset (dB). Depends on antenna pattern and relative orientation with signal.
    /// SignalLevelOffset   double The global power offset (dB)
    /// ManualGain          double The power offset provided by the user (dB). See SetSatellitePower
    /// Total               double The sum of all the other fields (dBm)
    ///

    class GetSatellitePowerResult;
    typedef std::shared_ptr<GetSatellitePowerResult> GetSatellitePowerResultPtr;
    
    
    class GetSatellitePowerResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSatellitePowerResult();

      GetSatellitePowerResult(CommandBasePtr relatedCommand, double nominalPower, double signalStrengthModel, double antenna, double signalLevelOffset, double manualGain, double total);
  
      static GetSatellitePowerResultPtr create(CommandBasePtr relatedCommand, double nominalPower, double signalStrengthModel, double antenna, double signalLevelOffset, double manualGain, double total);
      static GetSatellitePowerResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** nominalPower ****
      double nominalPower() const;
      void setNominalPower(double nominalPower);


      // **** signalStrengthModel ****
      double signalStrengthModel() const;
      void setSignalStrengthModel(double signalStrengthModel);


      // **** antenna ****
      double antenna() const;
      void setAntenna(double antenna);


      // **** signalLevelOffset ****
      double signalLevelOffset() const;
      void setSignalLevelOffset(double signalLevelOffset);


      // **** manualGain ****
      double manualGain() const;
      void setManualGain(double manualGain);


      // **** total ****
      double total() const;
      void setTotal(double total);
    };
  }
}

