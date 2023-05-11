
#include "gen/SetVehicleAntennaGain.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetVehicleAntennaGain
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetVehicleAntennaGain::CmdName = "SetVehicleAntennaGain";
    const char* const SetVehicleAntennaGain::Documentation = "Set Vehicle gain antenna pattern. If no name is specified, the command is aplied to Basic vehicle Antenna.";

    REGISTER_COMMAND_FACTORY(SetVehicleAntennaGain);


    SetVehicleAntennaGain::SetVehicleAntennaGain()
      : CommandBase(CmdName)
    {}

    SetVehicleAntennaGain::SetVehicleAntennaGain(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const Sdx::optional<std::string>& name)
      : CommandBase(CmdName)
    {

      setGain(gain);
      setType(type);
      setBand(band);
      setName(name);
    }

    SetVehicleAntennaGainPtr SetVehicleAntennaGain::create(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const Sdx::optional<std::string>& name)
    {
      return std::make_shared<SetVehicleAntennaGain>(gain, type, band, name);
    }

    SetVehicleAntennaGainPtr SetVehicleAntennaGain::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetVehicleAntennaGain>(ptr);
    }

    bool SetVehicleAntennaGain::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["Gain"])
          && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["Type"])
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["Name"])
        ;

    }

    std::string SetVehicleAntennaGain::documentation() const { return Documentation; }


    int SetVehicleAntennaGain::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::vector<std::vector<double>> SetVehicleAntennaGain::gain() const
    {
      return parse_json<std::vector<std::vector<double>>>::parse(m_values["Gain"]);
    }

    void SetVehicleAntennaGain::setGain(const std::vector<std::vector<double>>& gain)
    {
      m_values.AddMember("Gain", parse_json<std::vector<std::vector<double>>>::format(gain, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::AntennaPatternType SetVehicleAntennaGain::type() const
    {
      return parse_json<Sdx::AntennaPatternType>::parse(m_values["Type"]);
    }

    void SetVehicleAntennaGain::setType(const Sdx::AntennaPatternType& type)
    {
      m_values.AddMember("Type", parse_json<Sdx::AntennaPatternType>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::GNSSBand SetVehicleAntennaGain::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void SetVehicleAntennaGain::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetVehicleAntennaGain::name() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["Name"]);
    }

    void SetVehicleAntennaGain::setName(const Sdx::optional<std::string>& name)
    {
      m_values.AddMember("Name", parse_json<Sdx::optional<std::string>>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
