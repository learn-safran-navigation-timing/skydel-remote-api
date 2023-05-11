#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetPowerForSV.
    ///
    /// Name                Type   Description
    /// ------------------- ------ -----------------------------------------------------------------------------------------------------------
    /// System              string The system, can be "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// SvId                int    The Satellite SV ID
    /// NominalPower        double The nominal power in dBm
    /// SignalStrengthModel double The power difference coming from the Signal Strength Model (dB)
    /// Antenna             double The receiver antenna power offset (dB). It depends on antenna pattern and relative orientation with signal.
    /// SignalLevelOffset   double The global power offset (dB)
    /// ManualGain          double The power offset provided by the user (dB). See SetPowerForSV
    /// Total               double The sum of all the other fields (dBm)
    ///

    class GetPowerForSVResult;
    typedef std::shared_ptr<GetPowerForSVResult> GetPowerForSVResultPtr;
    
    
    class GetPowerForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPowerForSVResult();

      GetPowerForSVResult(const std::string& system, int svId, double nominalPower, double signalStrengthModel, double antenna, double signalLevelOffset, double manualGain, double total);

      GetPowerForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, double nominalPower, double signalStrengthModel, double antenna, double signalLevelOffset, double manualGain, double total);

      static GetPowerForSVResultPtr create(const std::string& system, int svId, double nominalPower, double signalStrengthModel, double antenna, double signalLevelOffset, double manualGain, double total);

      static GetPowerForSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, double nominalPower, double signalStrengthModel, double antenna, double signalLevelOffset, double manualGain, double total);
      static GetPowerForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


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
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetPowerForSVResult);
  }
}

