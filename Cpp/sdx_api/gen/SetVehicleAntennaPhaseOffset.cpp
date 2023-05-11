
#include "gen/SetVehicleAntennaPhaseOffset.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetVehicleAntennaPhaseOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetVehicleAntennaPhaseOffset::CmdName = "SetVehicleAntennaPhaseOffset";
    const char* const SetVehicleAntennaPhaseOffset::Documentation = "Set Vehicle phase offset antenna pattern. If no name is specified, the command is aplied to Basic Vehicle Antenna.";

    REGISTER_COMMAND_FACTORY(SetVehicleAntennaPhaseOffset);


    SetVehicleAntennaPhaseOffset::SetVehicleAntennaPhaseOffset()
      : CommandBase(CmdName)
    {}

    SetVehicleAntennaPhaseOffset::SetVehicleAntennaPhaseOffset(const std::vector<std::vector<double>>& phaseOffset, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const Sdx::optional<std::string>& name)
      : CommandBase(CmdName)
    {

      setPhaseOffset(phaseOffset);
      setType(type);
      setBand(band);
      setName(name);
    }

    SetVehicleAntennaPhaseOffsetPtr SetVehicleAntennaPhaseOffset::create(const std::vector<std::vector<double>>& phaseOffset, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const Sdx::optional<std::string>& name)
    {
      return std::make_shared<SetVehicleAntennaPhaseOffset>(phaseOffset, type, band, name);
    }

    SetVehicleAntennaPhaseOffsetPtr SetVehicleAntennaPhaseOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetVehicleAntennaPhaseOffset>(ptr);
    }

    bool SetVehicleAntennaPhaseOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["PhaseOffset"])
          && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["Type"])
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["Name"])
        ;

    }

    std::string SetVehicleAntennaPhaseOffset::documentation() const { return Documentation; }


    int SetVehicleAntennaPhaseOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::vector<std::vector<double>> SetVehicleAntennaPhaseOffset::phaseOffset() const
    {
      return parse_json<std::vector<std::vector<double>>>::parse(m_values["PhaseOffset"]);
    }

    void SetVehicleAntennaPhaseOffset::setPhaseOffset(const std::vector<std::vector<double>>& phaseOffset)
    {
      m_values.AddMember("PhaseOffset", parse_json<std::vector<std::vector<double>>>::format(phaseOffset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::AntennaPatternType SetVehicleAntennaPhaseOffset::type() const
    {
      return parse_json<Sdx::AntennaPatternType>::parse(m_values["Type"]);
    }

    void SetVehicleAntennaPhaseOffset::setType(const Sdx::AntennaPatternType& type)
    {
      m_values.AddMember("Type", parse_json<Sdx::AntennaPatternType>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::GNSSBand SetVehicleAntennaPhaseOffset::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void SetVehicleAntennaPhaseOffset::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetVehicleAntennaPhaseOffset::name() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["Name"]);
    }

    void SetVehicleAntennaPhaseOffset::setName(const Sdx::optional<std::string>& name)
    {
      m_values.AddMember("Name", parse_json<Sdx::optional<std::string>>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
