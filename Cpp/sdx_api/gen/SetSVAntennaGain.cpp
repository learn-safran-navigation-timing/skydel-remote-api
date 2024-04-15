
#include "SetSVAntennaGain.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSVAntennaGain
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSVAntennaGain::CmdName = "SetSVAntennaGain";
    const char* const SetSVAntennaGain::Documentation = "Set space vehicle gain antenna pattern. If no name is specified, the command is aplied to Basic SV Antenna.\n"
      "\n"
      "Name   Type               Description\n"
      "------ ------------------ -------------------------------------------------------------------------------------------------------------------------\n"
      "Gain   array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.\n"
      "Type   AntennaPatternType Pattern type\n"
      "Band   GNSSBand           Frequency band\n"
      "System string             \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Name   optional string    SV antenna name";
    const char* const SetSVAntennaGain::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSVAntennaGain);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSVAntennaGain);


    SetSVAntennaGain::SetSVAntennaGain()
      : CommandBase(CmdName, TargetId)
    {}

    SetSVAntennaGain::SetSVAntennaGain(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name)
      : CommandBase(CmdName, TargetId)
    {

      setGain(gain);
      setType(type);
      setBand(band);
      setSystem(system);
      setName(name);
    }

    SetSVAntennaGainPtr SetSVAntennaGain::create(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name)
    {
      return std::make_shared<SetSVAntennaGain>(gain, type, band, system, name);
    }

    SetSVAntennaGainPtr SetSVAntennaGain::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSVAntennaGain>(ptr);
    }

    bool SetSVAntennaGain::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["Gain"])
          && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["Type"])
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["Name"])
        ;

    }

    std::string SetSVAntennaGain::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSVAntennaGain::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Gain", "Type", "Band", "System", "Name"}; 
      return names; 
    }


    int SetSVAntennaGain::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::vector<std::vector<double>> SetSVAntennaGain::gain() const
    {
      return parse_json<std::vector<std::vector<double>>>::parse(m_values["Gain"]);
    }

    void SetSVAntennaGain::setGain(const std::vector<std::vector<double>>& gain)
    {
      m_values.AddMember("Gain", parse_json<std::vector<std::vector<double>>>::format(gain, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::AntennaPatternType SetSVAntennaGain::type() const
    {
      return parse_json<Sdx::AntennaPatternType>::parse(m_values["Type"]);
    }

    void SetSVAntennaGain::setType(const Sdx::AntennaPatternType& type)
    {
      m_values.AddMember("Type", parse_json<Sdx::AntennaPatternType>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::GNSSBand SetSVAntennaGain::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void SetSVAntennaGain::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetSVAntennaGain::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetSVAntennaGain::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetSVAntennaGain::name() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["Name"]);
    }

    void SetSVAntennaGain::setName(const Sdx::optional<std::string>& name)
    {
      m_values.AddMember("Name", parse_json<Sdx::optional<std::string>>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
