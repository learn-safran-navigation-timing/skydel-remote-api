
#include "GetVehicleAntennaPhaseOffsetResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleAntennaPhaseOffsetResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleAntennaPhaseOffsetResult::CmdName = "GetVehicleAntennaPhaseOffsetResult";
    const char* const GetVehicleAntennaPhaseOffsetResult::Documentation = "Result of GetVehicleAntennaPhaseOffset.\n"
      "\n"
      "Name        Type               Description\n"
      "----------- ------------------ ----------------------------------------------------------------------------------------------------------------------------------\n"
      "PhaseOffset array array double Phase offset matrix (rad). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.\n"
      "Type        AntennaPatternType Pattern type\n"
      "Band        GNSSBand           Frequency band\n"
      "Name        optional string    Vehicle antenna name";
    const char* const GetVehicleAntennaPhaseOffsetResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetVehicleAntennaPhaseOffsetResult);


    GetVehicleAntennaPhaseOffsetResult::GetVehicleAntennaPhaseOffsetResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetVehicleAntennaPhaseOffsetResult::GetVehicleAntennaPhaseOffsetResult(const std::vector<std::vector<double>>& phaseOffset, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::optional<std::string>& name)
      : CommandResult(CmdName, TargetId)
    {

      setPhaseOffset(phaseOffset);
      setType(type);
      setBand(band);
      setName(name);
    }

    GetVehicleAntennaPhaseOffsetResult::GetVehicleAntennaPhaseOffsetResult(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& phaseOffset, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::optional<std::string>& name)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setPhaseOffset(phaseOffset);
      setType(type);
      setBand(band);
      setName(name);
    }


    GetVehicleAntennaPhaseOffsetResultPtr GetVehicleAntennaPhaseOffsetResult::create(const std::vector<std::vector<double>>& phaseOffset, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::optional<std::string>& name)
    {
      return std::make_shared<GetVehicleAntennaPhaseOffsetResult>(phaseOffset, type, band, name);
    }

    GetVehicleAntennaPhaseOffsetResultPtr GetVehicleAntennaPhaseOffsetResult::create(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& phaseOffset, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::optional<std::string>& name)
    {
      return std::make_shared<GetVehicleAntennaPhaseOffsetResult>(relatedCommand, phaseOffset, type, band, name);
    }

    GetVehicleAntennaPhaseOffsetResultPtr GetVehicleAntennaPhaseOffsetResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleAntennaPhaseOffsetResult>(ptr);
    }

    bool GetVehicleAntennaPhaseOffsetResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["PhaseOffset"])
          && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["Type"])
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["Name"])
        ;

    }

    std::string GetVehicleAntennaPhaseOffsetResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetVehicleAntennaPhaseOffsetResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"PhaseOffset", "Type", "Band", "Name"}; 
      return names; 
    }


    std::vector<std::vector<double>> GetVehicleAntennaPhaseOffsetResult::phaseOffset() const
    {
      return parse_json<std::vector<std::vector<double>>>::parse(m_values["PhaseOffset"]);
    }

    void GetVehicleAntennaPhaseOffsetResult::setPhaseOffset(const std::vector<std::vector<double>>& phaseOffset)
    {
      m_values.AddMember("PhaseOffset", parse_json<std::vector<std::vector<double>>>::format(phaseOffset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::AntennaPatternType GetVehicleAntennaPhaseOffsetResult::type() const
    {
      return parse_json<Sdx::AntennaPatternType>::parse(m_values["Type"]);
    }

    void GetVehicleAntennaPhaseOffsetResult::setType(const Sdx::AntennaPatternType& type)
    {
      m_values.AddMember("Type", parse_json<Sdx::AntennaPatternType>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::GNSSBand GetVehicleAntennaPhaseOffsetResult::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void GetVehicleAntennaPhaseOffsetResult::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetVehicleAntennaPhaseOffsetResult::name() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["Name"]);
    }

    void GetVehicleAntennaPhaseOffsetResult::setName(const std::optional<std::string>& name)
    {
      m_values.AddMember("Name", parse_json<std::optional<std::string>>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
