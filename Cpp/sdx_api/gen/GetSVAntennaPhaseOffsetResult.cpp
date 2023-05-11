
#include "gen/GetSVAntennaPhaseOffsetResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVAntennaPhaseOffsetResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVAntennaPhaseOffsetResult::CmdName = "GetSVAntennaPhaseOffsetResult";
    const char* const GetSVAntennaPhaseOffsetResult::Documentation = "Result of GetSVAntennaPhaseOffset.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetSVAntennaPhaseOffsetResult);


    GetSVAntennaPhaseOffsetResult::GetSVAntennaPhaseOffsetResult()
      : CommandResult(CmdName)
    {}

    GetSVAntennaPhaseOffsetResult::GetSVAntennaPhaseOffsetResult(const std::vector<std::vector<double>>& phaseOffset, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name)
      : CommandResult(CmdName)
    {

      setPhaseOffset(phaseOffset);
      setType(type);
      setBand(band);
      setSystem(system);
      setName(name);
    }

    GetSVAntennaPhaseOffsetResult::GetSVAntennaPhaseOffsetResult(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& phaseOffset, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name)
      : CommandResult(CmdName, relatedCommand)
    {

      setPhaseOffset(phaseOffset);
      setType(type);
      setBand(band);
      setSystem(system);
      setName(name);
    }


    GetSVAntennaPhaseOffsetResultPtr GetSVAntennaPhaseOffsetResult::create(const std::vector<std::vector<double>>& phaseOffset, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name)
    {
      return std::make_shared<GetSVAntennaPhaseOffsetResult>(phaseOffset, type, band, system, name);
    }

    GetSVAntennaPhaseOffsetResultPtr GetSVAntennaPhaseOffsetResult::create(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& phaseOffset, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name)
    {
      return std::make_shared<GetSVAntennaPhaseOffsetResult>(relatedCommand, phaseOffset, type, band, system, name);
    }

    GetSVAntennaPhaseOffsetResultPtr GetSVAntennaPhaseOffsetResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSVAntennaPhaseOffsetResult>(ptr);
    }

    bool GetSVAntennaPhaseOffsetResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["PhaseOffset"])
          && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["Type"])
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["Name"])
        ;

    }

    std::string GetSVAntennaPhaseOffsetResult::documentation() const { return Documentation; }


    std::vector<std::vector<double>> GetSVAntennaPhaseOffsetResult::phaseOffset() const
    {
      return parse_json<std::vector<std::vector<double>>>::parse(m_values["PhaseOffset"]);
    }

    void GetSVAntennaPhaseOffsetResult::setPhaseOffset(const std::vector<std::vector<double>>& phaseOffset)
    {
      m_values.AddMember("PhaseOffset", parse_json<std::vector<std::vector<double>>>::format(phaseOffset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::AntennaPatternType GetSVAntennaPhaseOffsetResult::type() const
    {
      return parse_json<Sdx::AntennaPatternType>::parse(m_values["Type"]);
    }

    void GetSVAntennaPhaseOffsetResult::setType(const Sdx::AntennaPatternType& type)
    {
      m_values.AddMember("Type", parse_json<Sdx::AntennaPatternType>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::GNSSBand GetSVAntennaPhaseOffsetResult::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void GetSVAntennaPhaseOffsetResult::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSVAntennaPhaseOffsetResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetSVAntennaPhaseOffsetResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetSVAntennaPhaseOffsetResult::name() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["Name"]);
    }

    void GetSVAntennaPhaseOffsetResult::setName(const Sdx::optional<std::string>& name)
    {
      m_values.AddMember("Name", parse_json<Sdx::optional<std::string>>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
