
#include "GetWFElementResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetWFElementResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetWFElementResult::CmdName = "GetWFElementResult";
    const char* const GetWFElementResult::Documentation = "Result of GetWFElement.\n"
      "\n"
      "Name                            Type            Description\n"
      "------------------------------- --------------- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Element                         int             One-based index of the element. Value -1 adds a new element at the end of the list.\n"
      "Enabled                         bool            If True, this antenna element will be simulated.\n"
      "AntennaModelName                string          Antenna Model name for this element. Antenna models can be defined in Vehicle Antenna Model menu.\n"
      "LnaGain                         optional int    LNA gain to add to the element. If unspecified, default value is 0 dB. Value must be a positive integer between 0 dB and +25 dB.\n"
      "IsGaussianNoiseEnabled          optional bool   If true, add Gaussian noise to the GNSS outputs of the element to ensure realistic signal to noise ratio. If unspecified, default value is True. The Gaussian Noise seed used is unique for each output of each element of the Wavefront system.\n"
      "GaussianNoisePowerDensityOffset optional double The Noise Power Density Offset (dB/Hz) added to the base Gaussian Noise power density (-174 dB/Hz) on the GNSS outputs of the element. If Gaussian Noise is not enabled on the element, this offset has no effect. If unspecified, default value is 0 dB/Hz. Value must be between -10 and +10 dB/Hz.";
    const char* const GetWFElementResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetWFElementResult);


    GetWFElementResult::GetWFElementResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetWFElementResult::GetWFElementResult(int element, bool enabled, const std::string& antennaModelName, const std::optional<int>& lnaGain, const std::optional<bool>& isGaussianNoiseEnabled, const std::optional<double>& gaussianNoisePowerDensityOffset)
      : CommandResult(CmdName, TargetId)
    {

      setElement(element);
      setEnabled(enabled);
      setAntennaModelName(antennaModelName);
      setLnaGain(lnaGain);
      setIsGaussianNoiseEnabled(isGaussianNoiseEnabled);
      setGaussianNoisePowerDensityOffset(gaussianNoisePowerDensityOffset);
    }

    GetWFElementResult::GetWFElementResult(CommandBasePtr relatedCommand, int element, bool enabled, const std::string& antennaModelName, const std::optional<int>& lnaGain, const std::optional<bool>& isGaussianNoiseEnabled, const std::optional<double>& gaussianNoisePowerDensityOffset)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setElement(element);
      setEnabled(enabled);
      setAntennaModelName(antennaModelName);
      setLnaGain(lnaGain);
      setIsGaussianNoiseEnabled(isGaussianNoiseEnabled);
      setGaussianNoisePowerDensityOffset(gaussianNoisePowerDensityOffset);
    }


    GetWFElementResultPtr GetWFElementResult::create(int element, bool enabled, const std::string& antennaModelName, const std::optional<int>& lnaGain, const std::optional<bool>& isGaussianNoiseEnabled, const std::optional<double>& gaussianNoisePowerDensityOffset)
    {
      return std::make_shared<GetWFElementResult>(element, enabled, antennaModelName, lnaGain, isGaussianNoiseEnabled, gaussianNoisePowerDensityOffset);
    }

    GetWFElementResultPtr GetWFElementResult::create(CommandBasePtr relatedCommand, int element, bool enabled, const std::string& antennaModelName, const std::optional<int>& lnaGain, const std::optional<bool>& isGaussianNoiseEnabled, const std::optional<double>& gaussianNoisePowerDensityOffset)
    {
      return std::make_shared<GetWFElementResult>(relatedCommand, element, enabled, antennaModelName, lnaGain, isGaussianNoiseEnabled, gaussianNoisePowerDensityOffset);
    }

    GetWFElementResultPtr GetWFElementResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetWFElementResult>(ptr);
    }

    bool GetWFElementResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Element"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<std::string>::is_valid(m_values["AntennaModelName"])
          && parse_json<std::optional<int>>::is_valid(m_values["LnaGain"])
          && parse_json<std::optional<bool>>::is_valid(m_values["IsGaussianNoiseEnabled"])
          && parse_json<std::optional<double>>::is_valid(m_values["GaussianNoisePowerDensityOffset"])
        ;

    }

    std::string GetWFElementResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetWFElementResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Element", "Enabled", "AntennaModelName", "LnaGain", "IsGaussianNoiseEnabled", "GaussianNoisePowerDensityOffset"}; 
      return names; 
    }


    int GetWFElementResult::element() const
    {
      return parse_json<int>::parse(m_values["Element"]);
    }

    void GetWFElementResult::setElement(int element)
    {
      m_values.AddMember("Element", parse_json<int>::format(element, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetWFElementResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void GetWFElementResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetWFElementResult::antennaModelName() const
    {
      return parse_json<std::string>::parse(m_values["AntennaModelName"]);
    }

    void GetWFElementResult::setAntennaModelName(const std::string& antennaModelName)
    {
      m_values.AddMember("AntennaModelName", parse_json<std::string>::format(antennaModelName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<int> GetWFElementResult::lnaGain() const
    {
      return parse_json<std::optional<int>>::parse(m_values["LnaGain"]);
    }

    void GetWFElementResult::setLnaGain(const std::optional<int>& lnaGain)
    {
      m_values.AddMember("LnaGain", parse_json<std::optional<int>>::format(lnaGain, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<bool> GetWFElementResult::isGaussianNoiseEnabled() const
    {
      return parse_json<std::optional<bool>>::parse(m_values["IsGaussianNoiseEnabled"]);
    }

    void GetWFElementResult::setIsGaussianNoiseEnabled(const std::optional<bool>& isGaussianNoiseEnabled)
    {
      m_values.AddMember("IsGaussianNoiseEnabled", parse_json<std::optional<bool>>::format(isGaussianNoiseEnabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<double> GetWFElementResult::gaussianNoisePowerDensityOffset() const
    {
      return parse_json<std::optional<double>>::parse(m_values["GaussianNoisePowerDensityOffset"]);
    }

    void GetWFElementResult::setGaussianNoisePowerDensityOffset(const std::optional<double>& gaussianNoisePowerDensityOffset)
    {
      m_values.AddMember("GaussianNoisePowerDensityOffset", parse_json<std::optional<double>>::format(gaussianNoisePowerDensityOffset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
