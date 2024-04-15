
#include "SetSVAntennaPhaseOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSVAntennaPhaseOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSVAntennaPhaseOffset::CmdName = "SetSVAntennaPhaseOffset";
    const char* const SetSVAntennaPhaseOffset::Documentation = "Set space vehicle phase offset antenna pattern. If no name is specified, the command is aplied to Basic Vehicle Antenna.\n"
      "\n"
      "Name        Type               Description\n"
      "----------- ------------------ ----------------------------------------------------------------------------------------------------------------------------------\n"
      "PhaseOffset array array double Phase offset matrix (rad). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.\n"
      "Type        AntennaPatternType Pattern type\n"
      "Band        GNSSBand           Frequency band\n"
      "System      string             \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Name        optional string    SV antenna name";
    const char* const SetSVAntennaPhaseOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSVAntennaPhaseOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSVAntennaPhaseOffset);


    SetSVAntennaPhaseOffset::SetSVAntennaPhaseOffset()
      : CommandBase(CmdName, TargetId)
    {}

    SetSVAntennaPhaseOffset::SetSVAntennaPhaseOffset(const std::vector<std::vector<double>>& phaseOffset, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name)
      : CommandBase(CmdName, TargetId)
    {

      setPhaseOffset(phaseOffset);
      setType(type);
      setBand(band);
      setSystem(system);
      setName(name);
    }

    SetSVAntennaPhaseOffsetPtr SetSVAntennaPhaseOffset::create(const std::vector<std::vector<double>>& phaseOffset, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name)
    {
      return std::make_shared<SetSVAntennaPhaseOffset>(phaseOffset, type, band, system, name);
    }

    SetSVAntennaPhaseOffsetPtr SetSVAntennaPhaseOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSVAntennaPhaseOffset>(ptr);
    }

    bool SetSVAntennaPhaseOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["PhaseOffset"])
          && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["Type"])
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["Name"])
        ;

    }

    std::string SetSVAntennaPhaseOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSVAntennaPhaseOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"PhaseOffset", "Type", "Band", "System", "Name"}; 
      return names; 
    }


    int SetSVAntennaPhaseOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::vector<std::vector<double>> SetSVAntennaPhaseOffset::phaseOffset() const
    {
      return parse_json<std::vector<std::vector<double>>>::parse(m_values["PhaseOffset"]);
    }

    void SetSVAntennaPhaseOffset::setPhaseOffset(const std::vector<std::vector<double>>& phaseOffset)
    {
      m_values.AddMember("PhaseOffset", parse_json<std::vector<std::vector<double>>>::format(phaseOffset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::AntennaPatternType SetSVAntennaPhaseOffset::type() const
    {
      return parse_json<Sdx::AntennaPatternType>::parse(m_values["Type"]);
    }

    void SetSVAntennaPhaseOffset::setType(const Sdx::AntennaPatternType& type)
    {
      m_values.AddMember("Type", parse_json<Sdx::AntennaPatternType>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::GNSSBand SetSVAntennaPhaseOffset::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void SetSVAntennaPhaseOffset::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetSVAntennaPhaseOffset::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetSVAntennaPhaseOffset::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetSVAntennaPhaseOffset::name() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["Name"]);
    }

    void SetSVAntennaPhaseOffset::setName(const Sdx::optional<std::string>& name)
    {
      m_values.AddMember("Name", parse_json<Sdx::optional<std::string>>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
