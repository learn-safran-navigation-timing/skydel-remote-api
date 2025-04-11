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
    /// Result of GetWFElement.
    ///
    /// Name                            Type            Description
    /// ------------------------------- --------------- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Element                         int             One-based index of the element. Value -1 adds a new element at the end of the list.
    /// Enabled                         bool            If True, this antenna element will be simulated.
    /// AntennaModelName                string          Antenna Model name for this element. Antenna models can be defined in Vehicle Antenna Model menu.
    /// LnaGain                         optional int    LNA gain to add to the element. If unspecified, default value is 0 dB. Value must be a positive integer between 0 dB and +25 dB.
    /// IsGaussianNoiseEnabled          optional bool   If true, add Gaussian noise to the GNSS outputs of the element to ensure realistic signal to noise ratio. If unspecified, default value is True. The Gaussian Noise seed used is unique for each output of each element of the Wavefront system.
    /// GaussianNoisePowerDensityOffset optional double The Noise Power Density Offset (dB/Hz) added to the base Gaussian Noise power density (-174 dB/Hz) on the GNSS outputs of the element. If Gaussian Noise is not enabled on the element, this offset has no effect. If unspecified, default value is 0 dB/Hz. Value must be between -10 and +10 dB/Hz.
    ///

    class GetWFElementResult;
    typedef std::shared_ptr<GetWFElementResult> GetWFElementResultPtr;
    
    
    class GetWFElementResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetWFElementResult();

      GetWFElementResult(int element, bool enabled, const std::string& antennaModelName, const std::optional<int>& lnaGain = {}, const std::optional<bool>& isGaussianNoiseEnabled = {}, const std::optional<double>& gaussianNoisePowerDensityOffset = {});

      GetWFElementResult(CommandBasePtr relatedCommand, int element, bool enabled, const std::string& antennaModelName, const std::optional<int>& lnaGain = {}, const std::optional<bool>& isGaussianNoiseEnabled = {}, const std::optional<double>& gaussianNoisePowerDensityOffset = {});

      static GetWFElementResultPtr create(int element, bool enabled, const std::string& antennaModelName, const std::optional<int>& lnaGain = {}, const std::optional<bool>& isGaussianNoiseEnabled = {}, const std::optional<double>& gaussianNoisePowerDensityOffset = {});

      static GetWFElementResultPtr create(CommandBasePtr relatedCommand, int element, bool enabled, const std::string& antennaModelName, const std::optional<int>& lnaGain = {}, const std::optional<bool>& isGaussianNoiseEnabled = {}, const std::optional<double>& gaussianNoisePowerDensityOffset = {});
      static GetWFElementResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** element ****
      int element() const;
      void setElement(int element);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** antennaModelName ****
      std::string antennaModelName() const;
      void setAntennaModelName(const std::string& antennaModelName);


      // **** lnaGain ****
      std::optional<int> lnaGain() const;
      void setLnaGain(const std::optional<int>& lnaGain);


      // **** isGaussianNoiseEnabled ****
      std::optional<bool> isGaussianNoiseEnabled() const;
      void setIsGaussianNoiseEnabled(const std::optional<bool>& isGaussianNoiseEnabled);


      // **** gaussianNoisePowerDensityOffset ****
      std::optional<double> gaussianNoisePowerDensityOffset() const;
      void setGaussianNoisePowerDensityOffset(const std::optional<double>& gaussianNoisePowerDensityOffset);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetWFElementResult);
  }
}

