#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetModulationTargetSignals.
    ///
    /// Name             Type            Description
    /// ---------------- --------------- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Output           int             Output index (zero based)
    /// MinRate          int             Minimum sampling rate (12500000, 25000000, 50000000, 60000000, 100000000)
    /// MaxRate          int             Maximum sampling rate (12500000, 25000000, 50000000, 60000000, 100000000)
    /// Band             string          Frequency band is "LowerL" or "UpperL"
    /// Signal           string          Comma separated signal keys, accepted signal keys: "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME", "L2MR", "L5", "G1", "G2", "E1", "E5a", "E5b", "B1", "B2", "B1C", "B2a", "B3I", "SBASL1", "QZSSL1CA", "QZSSL1CB", "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "QZSSL6", "NAVICL1", "NAVICL5", "NAVICS", "PULSARXL"
    /// Gain             int             The gain associated to this output (dB). This value has to be between the radio minimum value and 115. A negative value means to use the radio default value.
    /// GaussianNoise    bool            If true, add Gaussian noise to ensure realistic signal to noise ratio. When combining multiple outputs, only one should have Gaussian noise enabled.
    /// Id               string          Target identifier
    /// CentralFrequency optional double Forced central frequency to this value. Central frequency can only be one of this values: 1176450000, 1191795000, 1202000000, 1207140000, 1217370000, 1222000000, 1227000000, 1227600000, 1230000000, 1235000000, 1246000000, 1561098000, 1575420000, 1582000000, 1584000000, 1586000000, 1602000000.
    ///

    class GetModulationTargetSignalsResult;
    typedef std::shared_ptr<GetModulationTargetSignalsResult> GetModulationTargetSignalsResultPtr;
    
    
    class GetModulationTargetSignalsResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetModulationTargetSignalsResult();

      GetModulationTargetSignalsResult(int output, int minRate, int maxRate, const std::string& band, const std::string& signal, int gain, bool gaussianNoise, const std::string& id, const std::optional<double>& centralFrequency = {});

      GetModulationTargetSignalsResult(CommandBasePtr relatedCommand, int output, int minRate, int maxRate, const std::string& band, const std::string& signal, int gain, bool gaussianNoise, const std::string& id, const std::optional<double>& centralFrequency = {});

      static GetModulationTargetSignalsResultPtr create(int output, int minRate, int maxRate, const std::string& band, const std::string& signal, int gain, bool gaussianNoise, const std::string& id, const std::optional<double>& centralFrequency = {});

      static GetModulationTargetSignalsResultPtr create(CommandBasePtr relatedCommand, int output, int minRate, int maxRate, const std::string& band, const std::string& signal, int gain, bool gaussianNoise, const std::string& id, const std::optional<double>& centralFrequency = {});
      static GetModulationTargetSignalsResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** output ****
      int output() const;
      void setOutput(int output);


      // **** minRate ****
      int minRate() const;
      void setMinRate(int minRate);


      // **** maxRate ****
      int maxRate() const;
      void setMaxRate(int maxRate);


      // **** band ****
      std::string band() const;
      void setBand(const std::string& band);


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** gain ****
      int gain() const;
      void setGain(int gain);


      // **** gaussianNoise ****
      bool gaussianNoise() const;
      void setGaussianNoise(bool gaussianNoise);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);


      // **** centralFrequency ****
      std::optional<double> centralFrequency() const;
      void setCentralFrequency(const std::optional<double>& centralFrequency);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetModulationTargetSignalsResult);
  }
}

