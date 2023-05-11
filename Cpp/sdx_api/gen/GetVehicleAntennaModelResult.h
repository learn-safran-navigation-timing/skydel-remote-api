#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include "gen/AntennaPatternType.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetVehicleAntennaModel.
    ///
    /// Name                 Type               Description
    /// -------------------- ------------------ ----------------------------------------------------------------------------------------------------------------------------------
    /// GainL1               array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.
    /// GainTypeL1           AntennaPatternType Pattern type
    /// GainOffsetL1         double             Pattern offset
    /// GainL2               array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.
    /// GainTypeL2           AntennaPatternType Pattern type
    /// GainOffsetL2         double             Pattern offset
    /// GainL5               array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.
    /// GainTypeL5           AntennaPatternType Pattern type
    /// GainOffsetL5         double             Pattern offset
    /// GainE6               array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.
    /// GainTypeE6           AntennaPatternType Pattern type
    /// GainOffsetE6         double             Pattern offset
    /// PhaseOffsetL1        array array double Phase offset matrix (rad). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.
    /// PhaseOffsetTypeL1    AntennaPatternType Pattern type
    /// PhasePatternOffsetL1 double             Pattern offset
    /// PhaseOffsetL2        array array double Phase offset matrix (rad). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.
    /// PhaseOffsetTypeL2    AntennaPatternType Pattern type
    /// PhasePatternOffsetL2 double             Pattern offset
    /// PhaseOffsetL5        array array double Phase offset matrix (rad). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.
    /// PhaseOffsetTypeL5    AntennaPatternType Pattern type
    /// PhasePatternOffsetL5 double             Pattern offset
    /// PhaseOffsetE6        array array double Phase offset matrix (rad). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.
    /// PhaseOffsetTypeE6    AntennaPatternType Pattern type
    /// PhasePatternOffsetE6 double             Pattern offset
    /// X                    double             Antenna X offset in the body frame (meter)
    /// Y                    double             Antenna Y offset in the body frame (meter)
    /// Z                    double             Antenna Z offset in the body frame (meter)
    /// Yaw                  double             Antenna Yaw offset in the body frame (rad)
    /// Pitch                double             Antenna Pitch offset in the body frame (rad)
    /// Roll                 double             Antenna Roll offset in the body frame (rad)
    /// Name                 string             Vehicle antenna model name
    ///

    class GetVehicleAntennaModelResult;
    typedef std::shared_ptr<GetVehicleAntennaModelResult> GetVehicleAntennaModelResultPtr;
    
    
    class GetVehicleAntennaModelResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetVehicleAntennaModelResult();

      GetVehicleAntennaModelResult(const std::vector<std::vector<double>>& gainL1, const Sdx::AntennaPatternType& gainTypeL1, double gainOffsetL1, const std::vector<std::vector<double>>& gainL2, const Sdx::AntennaPatternType& gainTypeL2, double gainOffsetL2, const std::vector<std::vector<double>>& gainL5, const Sdx::AntennaPatternType& gainTypeL5, double gainOffsetL5, const std::vector<std::vector<double>>& gainE6, const Sdx::AntennaPatternType& gainTypeE6, double gainOffsetE6, const std::vector<std::vector<double>>& phaseOffsetL1, const Sdx::AntennaPatternType& phaseOffsetTypeL1, double phasePatternOffsetL1, const std::vector<std::vector<double>>& phaseOffsetL2, const Sdx::AntennaPatternType& phaseOffsetTypeL2, double phasePatternOffsetL2, const std::vector<std::vector<double>>& phaseOffsetL5, const Sdx::AntennaPatternType& phaseOffsetTypeL5, double phasePatternOffsetL5, const std::vector<std::vector<double>>& phaseOffsetE6, const Sdx::AntennaPatternType& phaseOffsetTypeE6, double phasePatternOffsetE6, double x, double y, double z, double yaw, double pitch, double roll, const std::string& name);

      GetVehicleAntennaModelResult(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& gainL1, const Sdx::AntennaPatternType& gainTypeL1, double gainOffsetL1, const std::vector<std::vector<double>>& gainL2, const Sdx::AntennaPatternType& gainTypeL2, double gainOffsetL2, const std::vector<std::vector<double>>& gainL5, const Sdx::AntennaPatternType& gainTypeL5, double gainOffsetL5, const std::vector<std::vector<double>>& gainE6, const Sdx::AntennaPatternType& gainTypeE6, double gainOffsetE6, const std::vector<std::vector<double>>& phaseOffsetL1, const Sdx::AntennaPatternType& phaseOffsetTypeL1, double phasePatternOffsetL1, const std::vector<std::vector<double>>& phaseOffsetL2, const Sdx::AntennaPatternType& phaseOffsetTypeL2, double phasePatternOffsetL2, const std::vector<std::vector<double>>& phaseOffsetL5, const Sdx::AntennaPatternType& phaseOffsetTypeL5, double phasePatternOffsetL5, const std::vector<std::vector<double>>& phaseOffsetE6, const Sdx::AntennaPatternType& phaseOffsetTypeE6, double phasePatternOffsetE6, double x, double y, double z, double yaw, double pitch, double roll, const std::string& name);

      static GetVehicleAntennaModelResultPtr create(const std::vector<std::vector<double>>& gainL1, const Sdx::AntennaPatternType& gainTypeL1, double gainOffsetL1, const std::vector<std::vector<double>>& gainL2, const Sdx::AntennaPatternType& gainTypeL2, double gainOffsetL2, const std::vector<std::vector<double>>& gainL5, const Sdx::AntennaPatternType& gainTypeL5, double gainOffsetL5, const std::vector<std::vector<double>>& gainE6, const Sdx::AntennaPatternType& gainTypeE6, double gainOffsetE6, const std::vector<std::vector<double>>& phaseOffsetL1, const Sdx::AntennaPatternType& phaseOffsetTypeL1, double phasePatternOffsetL1, const std::vector<std::vector<double>>& phaseOffsetL2, const Sdx::AntennaPatternType& phaseOffsetTypeL2, double phasePatternOffsetL2, const std::vector<std::vector<double>>& phaseOffsetL5, const Sdx::AntennaPatternType& phaseOffsetTypeL5, double phasePatternOffsetL5, const std::vector<std::vector<double>>& phaseOffsetE6, const Sdx::AntennaPatternType& phaseOffsetTypeE6, double phasePatternOffsetE6, double x, double y, double z, double yaw, double pitch, double roll, const std::string& name);

      static GetVehicleAntennaModelResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& gainL1, const Sdx::AntennaPatternType& gainTypeL1, double gainOffsetL1, const std::vector<std::vector<double>>& gainL2, const Sdx::AntennaPatternType& gainTypeL2, double gainOffsetL2, const std::vector<std::vector<double>>& gainL5, const Sdx::AntennaPatternType& gainTypeL5, double gainOffsetL5, const std::vector<std::vector<double>>& gainE6, const Sdx::AntennaPatternType& gainTypeE6, double gainOffsetE6, const std::vector<std::vector<double>>& phaseOffsetL1, const Sdx::AntennaPatternType& phaseOffsetTypeL1, double phasePatternOffsetL1, const std::vector<std::vector<double>>& phaseOffsetL2, const Sdx::AntennaPatternType& phaseOffsetTypeL2, double phasePatternOffsetL2, const std::vector<std::vector<double>>& phaseOffsetL5, const Sdx::AntennaPatternType& phaseOffsetTypeL5, double phasePatternOffsetL5, const std::vector<std::vector<double>>& phaseOffsetE6, const Sdx::AntennaPatternType& phaseOffsetTypeE6, double phasePatternOffsetE6, double x, double y, double z, double yaw, double pitch, double roll, const std::string& name);
      static GetVehicleAntennaModelResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** gainL1 ****
      std::vector<std::vector<double>> gainL1() const;
      void setGainL1(const std::vector<std::vector<double>>& gainL1);


      // **** gainTypeL1 ****
      Sdx::AntennaPatternType gainTypeL1() const;
      void setGainTypeL1(const Sdx::AntennaPatternType& gainTypeL1);


      // **** gainOffsetL1 ****
      double gainOffsetL1() const;
      void setGainOffsetL1(double gainOffsetL1);


      // **** gainL2 ****
      std::vector<std::vector<double>> gainL2() const;
      void setGainL2(const std::vector<std::vector<double>>& gainL2);


      // **** gainTypeL2 ****
      Sdx::AntennaPatternType gainTypeL2() const;
      void setGainTypeL2(const Sdx::AntennaPatternType& gainTypeL2);


      // **** gainOffsetL2 ****
      double gainOffsetL2() const;
      void setGainOffsetL2(double gainOffsetL2);


      // **** gainL5 ****
      std::vector<std::vector<double>> gainL5() const;
      void setGainL5(const std::vector<std::vector<double>>& gainL5);


      // **** gainTypeL5 ****
      Sdx::AntennaPatternType gainTypeL5() const;
      void setGainTypeL5(const Sdx::AntennaPatternType& gainTypeL5);


      // **** gainOffsetL5 ****
      double gainOffsetL5() const;
      void setGainOffsetL5(double gainOffsetL5);


      // **** gainE6 ****
      std::vector<std::vector<double>> gainE6() const;
      void setGainE6(const std::vector<std::vector<double>>& gainE6);


      // **** gainTypeE6 ****
      Sdx::AntennaPatternType gainTypeE6() const;
      void setGainTypeE6(const Sdx::AntennaPatternType& gainTypeE6);


      // **** gainOffsetE6 ****
      double gainOffsetE6() const;
      void setGainOffsetE6(double gainOffsetE6);


      // **** phaseOffsetL1 ****
      std::vector<std::vector<double>> phaseOffsetL1() const;
      void setPhaseOffsetL1(const std::vector<std::vector<double>>& phaseOffsetL1);


      // **** phaseOffsetTypeL1 ****
      Sdx::AntennaPatternType phaseOffsetTypeL1() const;
      void setPhaseOffsetTypeL1(const Sdx::AntennaPatternType& phaseOffsetTypeL1);


      // **** phasePatternOffsetL1 ****
      double phasePatternOffsetL1() const;
      void setPhasePatternOffsetL1(double phasePatternOffsetL1);


      // **** phaseOffsetL2 ****
      std::vector<std::vector<double>> phaseOffsetL2() const;
      void setPhaseOffsetL2(const std::vector<std::vector<double>>& phaseOffsetL2);


      // **** phaseOffsetTypeL2 ****
      Sdx::AntennaPatternType phaseOffsetTypeL2() const;
      void setPhaseOffsetTypeL2(const Sdx::AntennaPatternType& phaseOffsetTypeL2);


      // **** phasePatternOffsetL2 ****
      double phasePatternOffsetL2() const;
      void setPhasePatternOffsetL2(double phasePatternOffsetL2);


      // **** phaseOffsetL5 ****
      std::vector<std::vector<double>> phaseOffsetL5() const;
      void setPhaseOffsetL5(const std::vector<std::vector<double>>& phaseOffsetL5);


      // **** phaseOffsetTypeL5 ****
      Sdx::AntennaPatternType phaseOffsetTypeL5() const;
      void setPhaseOffsetTypeL5(const Sdx::AntennaPatternType& phaseOffsetTypeL5);


      // **** phasePatternOffsetL5 ****
      double phasePatternOffsetL5() const;
      void setPhasePatternOffsetL5(double phasePatternOffsetL5);


      // **** phaseOffsetE6 ****
      std::vector<std::vector<double>> phaseOffsetE6() const;
      void setPhaseOffsetE6(const std::vector<std::vector<double>>& phaseOffsetE6);


      // **** phaseOffsetTypeE6 ****
      Sdx::AntennaPatternType phaseOffsetTypeE6() const;
      void setPhaseOffsetTypeE6(const Sdx::AntennaPatternType& phaseOffsetTypeE6);


      // **** phasePatternOffsetE6 ****
      double phasePatternOffsetE6() const;
      void setPhasePatternOffsetE6(double phasePatternOffsetE6);


      // **** x ****
      double x() const;
      void setX(double x);


      // **** y ****
      double y() const;
      void setY(double y);


      // **** z ****
      double z() const;
      void setZ(double z);


      // **** yaw ****
      double yaw() const;
      void setYaw(double yaw);


      // **** pitch ****
      double pitch() const;
      void setPitch(double pitch);


      // **** roll ****
      double roll() const;
      void setRoll(double roll);


      // **** name ****
      std::string name() const;
      void setName(const std::string& name);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetVehicleAntennaModelResult);
  }
}

