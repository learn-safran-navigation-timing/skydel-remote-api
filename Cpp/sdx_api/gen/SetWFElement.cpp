
#include "SetWFElement.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetWFElement
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetWFElement::CmdName = "SetWFElement";
    const char* const SetWFElement::Documentation = "Set the Wavefront element properties.\n"
      "\n"
      "Name                            Type            Description\n"
      "------------------------------- --------------- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Element                         int             One-based index of the element. Value -1 adds a new element at the end of the list.\n"
      "Enabled                         bool            If True, this antenna element will be simulated.\n"
      "AntennaModelName                string          Antenna Model name for this element. Antenna models can be defined in Vehicle Antenna Model menu.\n"
      "LnaGain                         optional int    LNA gain to add to the element. If unspecified, default value is 0 dB. Value must be a positive integer between 0 dB and +25 dB.\n"
      "IsGaussianNoiseEnabled          optional bool   If true, add Gaussian noise to the GNSS outputs of the element to ensure realistic signal to noise ratio. If unspecified, default value is True. The Gaussian Noise seed used is unique for each output of each element of the Wavefront system.\n"
      "GaussianNoisePowerDensityOffset optional double The Noise Power Density Offset (dB/Hz) added to the base Gaussian Noise power density (-174 dB/Hz) on the GNSS outputs of the element. If Gaussian Noise is not enabled on the element, this offset has no effect. If unspecified, default value is 0 dB/Hz. Value must be between -10 and +10 dB/Hz.";
    const char* const SetWFElement::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetWFElement);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetWFElement);


    SetWFElement::SetWFElement()
      : CommandBase(CmdName, TargetId)
    {}

    SetWFElement::SetWFElement(int element, bool enabled, const std::string& antennaModelName, const std::optional<int>& lnaGain, const std::optional<bool>& isGaussianNoiseEnabled, const std::optional<double>& gaussianNoisePowerDensityOffset)
      : CommandBase(CmdName, TargetId)
    {

      setElement(element);
      setEnabled(enabled);
      setAntennaModelName(antennaModelName);
      setLnaGain(lnaGain);
      setIsGaussianNoiseEnabled(isGaussianNoiseEnabled);
      setGaussianNoisePowerDensityOffset(gaussianNoisePowerDensityOffset);
    }

    SetWFElementPtr SetWFElement::create(int element, bool enabled, const std::string& antennaModelName, const std::optional<int>& lnaGain, const std::optional<bool>& isGaussianNoiseEnabled, const std::optional<double>& gaussianNoisePowerDensityOffset)
    {
      return std::make_shared<SetWFElement>(element, enabled, antennaModelName, lnaGain, isGaussianNoiseEnabled, gaussianNoisePowerDensityOffset);
    }

    SetWFElementPtr SetWFElement::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetWFElement>(ptr);
    }

    bool SetWFElement::isValid() const
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

    std::string SetWFElement::documentation() const { return Documentation; }

    const std::vector<std::string>& SetWFElement::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Element", "Enabled", "AntennaModelName", "LnaGain", "IsGaussianNoiseEnabled", "GaussianNoisePowerDensityOffset"}; 
      return names; 
    }


    int SetWFElement::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetWFElement::element() const
    {
      return parse_json<int>::parse(m_values["Element"]);
    }

    void SetWFElement::setElement(int element)
    {
      m_values.AddMember("Element", parse_json<int>::format(element, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetWFElement::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void SetWFElement::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetWFElement::antennaModelName() const
    {
      return parse_json<std::string>::parse(m_values["AntennaModelName"]);
    }

    void SetWFElement::setAntennaModelName(const std::string& antennaModelName)
    {
      m_values.AddMember("AntennaModelName", parse_json<std::string>::format(antennaModelName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<int> SetWFElement::lnaGain() const
    {
      return parse_json<std::optional<int>>::parse(m_values["LnaGain"]);
    }

    void SetWFElement::setLnaGain(const std::optional<int>& lnaGain)
    {
      m_values.AddMember("LnaGain", parse_json<std::optional<int>>::format(lnaGain, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<bool> SetWFElement::isGaussianNoiseEnabled() const
    {
      return parse_json<std::optional<bool>>::parse(m_values["IsGaussianNoiseEnabled"]);
    }

    void SetWFElement::setIsGaussianNoiseEnabled(const std::optional<bool>& isGaussianNoiseEnabled)
    {
      m_values.AddMember("IsGaussianNoiseEnabled", parse_json<std::optional<bool>>::format(isGaussianNoiseEnabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<double> SetWFElement::gaussianNoisePowerDensityOffset() const
    {
      return parse_json<std::optional<double>>::parse(m_values["GaussianNoisePowerDensityOffset"]);
    }

    void SetWFElement::setGaussianNoisePowerDensityOffset(const std::optional<double>& gaussianNoisePowerDensityOffset)
    {
      m_values.AddMember("GaussianNoisePowerDensityOffset", parse_json<std::optional<double>>::format(gaussianNoisePowerDensityOffset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
